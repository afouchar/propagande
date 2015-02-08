#ifndef MOD_IMAGE_H
# define MOD_IMAGE_H

//MAIN
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

//IMAGE
# include <zlib.h>
# include <png.h>
# include <jpeglib.h>

# define BUF_SIZE 64

//mod_main.c
int	ft_option(char *opt);
char	*ft_exist(char *prog_name, char *newfile, char *ext, int opt);
int	ft_file_type(char *prog_name, char *file, char *ext, int opt);

//mod_error.c
void    ft_usage(char *prog_name, char *opt, int err_num);
int     ft_error(char *prog_name, char *file, char *ext, int err_num);
int	ft_isdir(char *newfile);

//mod_copy.c
int	ft_copy(int fd, char *file, char *prog_name, int opt);

//mod_glitch.c
char	*ft_glitch_type(char *buf, int ret, int type);
char	*ft_glitch(char *buf, int ret);

#endif
