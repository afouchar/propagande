#include "mod_image.h"

int	ft_file_type(char *prog_name, char *file, char *ext, int opt)
{
  FILE		*fp;
  unsigned char	sig[8];

  if (opt == 2)
    {
	  fp = fopen(file, "rb");
	  if (!fp)
	    {
	      fclose(fp);
	      ft_error(prog_name, file, ext, 7);
	    }
	  fread(sig, 1, 8, fp);
	  if (strncmp((char *)sig, "\211PNG\r\n\032\n", 8) != 0)
            {
	      fclose(fp);
              ft_error(prog_name, file, ext, 5);
            }
	  else
	    printf("IS PNG\n");
	  return (9);
    }
  if (opt == 1)
    return (1);
  return (0);
}

char	*ft_exist(char *prog_name, char *newfile, char *ext, int opt)
{
  DIR		*dirp;
  struct dirent	*dp;
  char		*tmp;
  char		*name;

  name = ft_strnew(ft_strlen(newfile));
  if ((dirp = opendir(".")) != NULL)
    {
      if (ext != NULL)
        tmp = ft_strjoin(newfile, ext);
      else
	tmp = ft_strdup(newfile);
      while ((dp = readdir(dirp)) != NULL)
	{
	  if (ft_strcmp(tmp, dp->d_name) == 0)
	    {
	      if (ft_isdir(newfile) == 1)
		{
		  ft_error(prog_name, newfile, ext, 6);
		  return (NULL);
		}
	      if (opt == 2)
		newfile = ft_strjoin(newfile, "_GLITCHED");
	      newfile = ft_strjoin(newfile, "_copy");
	      free(tmp);
	      name = ft_exist(prog_name, newfile, ext, opt);
	      return (name);
	    }
	}
      free(tmp);
      closedir(dirp);
    }
  free(name);
  return (newfile);
}

int	ft_option(char *opt)
{
  int		nb;

  nb = 0;
  if ((ft_strcmp(opt, "-c")) == 0)
    nb = 1;
  else if ((ft_strcmp(opt, "-g")) == 0)
    nb = 2;
  return (nb);
}

int	main(int argc, char **argv)
{
  int		fd;
  int		opt;

  fd = 0;
  opt = 0;
  if (argc == 3)
    {
      opt = ft_option(argv[1]);
      if (opt == 0)
	{
	  ft_usage(argv[0], argv[1], 1);
	  return (0);
	}
      if ((fd = open(argv[2], O_RDONLY)) < 0)
	  return (ft_error(argv[0], argv[2], "", 1));
      ft_copy(fd, argv[2], argv[0], opt);
    }
  else
    ft_usage(argv[0], "", 0);
  return (0);
}
