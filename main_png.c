#include "header_png.h"

int	main(int argc, char **argv)
{
  t_file	file;
  FILE		*fp;

  file.prog_name = ft_strdup(argv[0] + 2);
  if (argc == 4)
    {
      ft_isoption(&file, argv[1], 1);
      ft_struct_init(&file, argv[2], argv[3]);
      ft_copy(&file);
    }
  else if (argc == 5)
    {
      ft_isoption(&file, argv[1], 2);
      ft_islevel(&file, argv[2]);
      ft_struct_init(&file, argv[3], argv[4]);
      ft_is_png(&file, &fp);
      ft_read_png(&file, &fp);
    }
  else
    ft_error(&file, 1);
  return (0);
}
