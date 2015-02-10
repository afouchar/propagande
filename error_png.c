#include "header_png.h"

void	ft_usage(char *prog_name)
{
  ft_putstr("usage: ");
  ft_putstr(prog_name);
  ft_putstr(" [-copy] source_file target_file\n");
  ft_putstr("       ");
  ft_putstr(prog_name);
  ft_putstr(" [-glitch] [option] source_file target_file\n");
}

void	ft_error(t_file *file, int err_nb)
{
  if (err_nb == 1)	//Not enough or too many arguments
    ft_usage(file->prog_name);
  if (err_nb == 2)	//Target_file or source_file is a directory and already exist
    {
      ft_putstr(file->prog_name);
      ft_putstr(" cannot create ");
      ft_putstr(file->new_file_name);
      ft_putendl(" because source_file or target_file already exist and is a directory\n");
      ft_usage(file->prog_name);
    }
  if (err_nb == 3)	//Target_file already exist
    {
      ft_putstr(file->prog_name);
      ft_putstr(" cannot create ");
      ft_putstr(file->new_file_name);
      ft_putendl(" because it already exist\n");
      ft_usage(file->prog_name);
    }
  if (err_nb == 4)      //Source_file does not exist
    {
      ft_putstr(file->prog_name);
      ft_putstr(" cannot create ");
      ft_putstr(file->new_file_name);
      ft_putstr(" because ");
      ft_putstr(file->file_name);
      ft_putendl(" does not exist\n");
      ft_usage(file->prog_name);
    }
  if (err_nb == 5)	//Illegal option
    {
      ft_putstr(file->prog_name);
      ft_putstr(": illegal option -- ");
      if (ft_strchr(file->option, '-') != NULL)
        ft_putendl(file->option + 1);
      else
	ft_putendl(file->option);
      ft_putchar('\n');
      ft_usage(file->prog_name);
    }
  if (err_nb == 6)	//Cannot read source_file
    {
      ft_putstr(file->prog_name);
      ft_putstr(" cannot read ");
      ft_putendl(file->file_name);
    }
  if (err_nb == 7)	//Cannot create target_file
    {
      ft_putstr(file->prog_name);
      ft_putstr(" cannot create ");
      ft_putendl(file->new_file_name);
    }
  if (err_nb == 8)	//Bad file type for glitch
    {
      ft_putstr(file->prog_name);
      ft_putstr(" cannot glitch ");
      ft_putstr(file->file_name);
      ft_putstr(" because [");
      ft_putstr(file->ext);
      ft_putendl("] is not a valid type of file\n");
      ft_usage(file->prog_name);
    }
  if (err_nb == 9)
    {
      ft_putstr(file->prog_name);
      ft_putstr(": illegal option ");
      ft_putendl(file->option);
      ft_putchar('\n');
      ft_usage(file->prog_name);
    }
  if (err_nb == 10)
    {
      ft_putstr(file->prog_name);
      ft_putstr(" cannot read ");
      ft_putendl(file->file_name);
    }
  if (err_nb == 11)
    {
      ft_putstr(file->prog_name);
      ft_putstr(" cannot write ");
      ft_putendl(file->new_file_name);
    }
  exit(0);
}
