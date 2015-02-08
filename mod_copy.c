#include "mod_image.h"

int     ft_copy(int fd, char *file, char *prog_name, int opt)
{
  char          *buf;
  int           ret;
  char          *newfile;
  char          *ext;
  int           newfd;
  ssize_t       nwrite;
  int		type;

  ret = 0;
  type = 0;
  newfd = 0;
  buf = malloc(sizeof(char) * (BUF_SIZE + 1));
  newfile = (char *)malloc(sizeof(char) * (ft_strlen(file) + 1));
  ext = (char *)malloc(sizeof(char) * (ft_strlen(file) + 1));

  ext = ft_strrchr(file, '.');

  newfile = ft_strsub(file, 0, (ft_strlen(file) - ft_strlen(ext)));
  newfile = ft_exist(prog_name, newfile, ext, opt);
  if (ext != NULL)
    newfile = ft_strjoin(newfile, ext);

  if ((type = ft_file_type(prog_name, file, ext, opt)) == 0)
      return (0);
  newfd = open(newfile, O_WRONLY | O_CREAT | O_EXCL, 0666);
  if (newfd < 0)
    return (ft_error(prog_name, newfile, ext, 2));

  while ((ret = read(fd, buf, BUF_SIZE)) > 0)
    {
      buf[ret] = '\0';
      if (opt == 2 && strncmp(buf, "\211PNG\r\n\032\n", 8) != 0
	&& strstr(buf, "IEND") == NULL && strstr(buf, "IDAT") == NULL
	&& strstr(buf, "IHDR") == NULL)
        buf = ft_strdup(ft_glitch(buf, ret));
      nwrite = write(newfd, buf, ret);
      if (nwrite >= 0)
        {
          ret -= nwrite;
          buf += nwrite;
        }
      else if (nwrite < 0)
	return (ft_error(prog_name, newfile, ext, 3));
    }
  if (ret == 0)
    {
      if (close(newfd) < 0)
        return (ft_error(prog_name, newfile, ext, 4));
      close(fd);
    }
  return (0);
}
