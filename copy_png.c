#include "header_png.h"

void	ft_copy(t_file *file)
{
  char		*cname;
  char		*buf;
  int		ret;

  cname = ft_strjoin(file->path, file->file_name);
  if ((file->fd = open(cname, O_RDONLY)) < 0)
    ft_error(file, 6);
  if ((file->new_fd = open(file->new_file_name, O_WRONLY | O_CREAT | O_EXCL, 0666)) < 0)
    ft_error(file, 7);
  buf = malloc(sizeof(char) * (BUF_SIZE + 1));
  while ((ret = read(file->fd, buf, BUF_SIZE)))
    {
      buf[ret] = '\0';
      write(file->new_fd, buf, ret);
    }
  close(file->new_fd);
  close(file->fd);
}

void	ft_is_png(t_file *file, FILE **fp)
{
  unsigned char	buf[PNG_BYTES_TO_CHECK];

  if ((*fp = fopen(file->file_name, "rb")) == NULL)
    ft_error(file, 6);
  if (fread(buf, 1, PNG_BYTES_TO_CHECK, *fp) != PNG_BYTES_TO_CHECK)
    ft_error(file, 8);
  if (png_sig_cmp(buf, (png_size_t)0, PNG_BYTES_TO_CHECK))
    ft_error(file, 8);
}

void	ft_read_png(t_file *file, FILE **fp)
{
  if (file->level > 0)
    ft_glitch(file, fp);
  else
    ft_copy(file);
}
