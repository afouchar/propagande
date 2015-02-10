#ifndef HEADER_PNG_H
# define HEADER_PNG_H

# define BUF_SIZE 64
# define PNG_BYTES_TO_CHECK 8

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <dirent.h>
# include "./libft/libft.h"
# include <zlib.h>
# include <png.h>

typedef struct	s_file
{
  char		*prog_name;
  char		*file_name;
  char		*new_file_name;
  char		*ext;
  char		*path;
  char		*new_path;
  char		*option;
  int		level;
  int		fd;
  int		new_fd;
}		t_file;

typedef struct	s_png
{
  png_structp	png_ptr;
  png_infop	info_ptr;
  unsigned int	sig_read;
  png_bytep	*row_pointers;
  png_uint_32	width;
  png_uint_32	height;
  int		bit_depth;
  int		color_type;
  int		interlace_type;
}		t_png;

//ARGS_PNG.C
void	ft_struct_init(t_file *file, char *src, char *target);
void	ft_target_exist(t_file *file);
void	ft_src_exist(t_file *file);
void	ft_isdir(t_file *file, char *path);
void	ft_isoption(t_file *file, char *option, int nb);
void	ft_islevel(t_file *file, char *level);

//ERROR_PNG.C
void	ft_error(t_file *file, int err_nb);
void	ft_usage(char * prog_name);

//COPY_PNG.C
void	ft_copy(t_file *file);
void	ft_is_png(t_file *file, FILE **fp);
void	ft_read_png(t_file *file, FILE **fp);

//GLITCH_PNG.C
void	ft_glitch(t_file *file, FILE **fp);

#endif
