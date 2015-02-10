#include "header_png.h"

void	ft_isdir(t_file *file, char *path)
{
  struct stat	buf;

  if (stat(path, &buf) != -1)
    {
      if (buf.st_mode & S_IFDIR)
	ft_error(file, 2);
    }
}

void	ft_src_exist(t_file *file)
{
  DIR		*dirp;
  struct dirent	*dp;
  char		*isdir;
  int		exist;

  exist =0;
  if ((dirp = opendir(file->path)) != NULL)
    {
      while ((dp = readdir(dirp)) != NULL)
        {
          if (ft_strcmp(file->file_name, dp->d_name) == 0)
	    {
	      isdir = ft_strjoin(file->path, file->file_name);
	      ft_isdir(file, isdir);
	      exist = 1;
	    }
        }
      closedir(dirp);
    }
  if (exist == 0)
      ft_error(file, 4);
}

void	ft_target_exist(t_file *file)
{
  DIR		*dirp;
  struct dirent	*dp;
  char		*isdir;

  if ((dirp = opendir(file->new_path)) != NULL)
    {
      while ((dp = readdir(dirp)) != NULL)
	{
	  if (ft_strcmp(file->new_file_name, dp->d_name) == 0)
	    {
	      isdir = ft_strjoin(file->new_path, file->new_file_name);
	      ft_isdir(file, isdir);
	      ft_error(file, 3);
	    }
	}
      closedir(dirp);
    }
}

void	ft_islevel(t_file *file, char *level)
{
  int		i;

  i = 0;
  while (level[i] != '\0')
    {
      if (ft_isdigit(level[i]) == 0)
	{
	  file->option = ft_strdup(level);
	  ft_error(file, 9);
	}
      i++;
    }
  file->level = ft_atoi(level);
  if (file->level < 0 || file->level > 100)
    {
      file->option = ft_strdup(level);
      ft_error(file, 9);
    }
}

void	ft_isoption(t_file *file, char *option, int nb)
{
  if (ft_strcmp(option, "-glitch") == 0 && nb == 2)
    file->option = ft_strdup(option);
  else if (ft_strcmp(option, "-copy") == 0 && nb == 1)
    file->option = ft_strdup(option);
  else if ((ft_strcmp(option, "-glitch") == 0 && nb == 1)
  || (ft_strcmp(option, "-copy") == 0 && nb == 2))
      ft_error(file, 1);
  else
    {
      file->option = ft_strdup(option);
      ft_error(file, 5);
    }
}

void	ft_struct_init(t_file *file, char *src, char *target)
{
  if (ft_strchr(src, '/') == NULL && ft_strncmp(src, "./", 2) != 0)
    file->path = ft_strdup("./");
  else
    file->path = ft_strsub(src, 0, (ft_strlen(src) - ft_strlen(ft_strrchr(src, '/'))) + 1 );

  file->ext = ft_strrchr(src, '.');

  file->file_name = ft_strdup(src);
  if (ft_strrchr(file->file_name, '/') != NULL)
    file->file_name = ft_strdup(ft_strrchr(file->file_name, '/') + 1);

  if (ft_strchr(target, '/') == NULL && ft_strncmp(target, "./", 2) != 0)
    file->new_path = ft_strdup("./");
  else
    file->path = ft_strsub(target, 0, (ft_strlen(target) - ft_strlen(ft_strrchr(target, '/'))) + 1 );

  file->new_file_name = ft_strdup(target);
  if (ft_strrchr(file->new_file_name, '/') != NULL)
    file->new_file_name = ft_strdup(ft_strrchr(file->new_file_name, '/') + 1);
  if (ft_strrchr(file->new_file_name, '.') == NULL
  || ft_strcmp(ft_strrchr(file->new_file_name, '.'), file->ext) != 0)
    file->new_file_name = ft_strjoin(file->new_file_name, file->ext);

  ft_src_exist(file);
  ft_target_exist(file);
}
