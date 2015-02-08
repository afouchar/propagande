#include "mod_image.h"

int     ft_isdir(char *newfile)
{
  struct stat   buf;

  if (stat(newfile, &buf) != -1)
    {
      if (buf.st_mode & S_IFDIR)
	return (1);
    }
  return (0);
}

void    ft_usage(char *prog_name, char *opt, int err_num)
{
  if (err_num == 1)
    {
      printf("%s", prog_name);
      printf(": illegal option ");
      printf("%s\n", opt);
    }
  printf("usage: ");
  printf("%s", prog_name);
  printf(" [-c | -g] source_file\n\n");
  printf("option [-c]: copy source_file\n");
  printf("option [-g]: copy a glitched version of source_file\n");
  if (err_num == 2)
    {
      printf("\nsupported file types:\n");
      printf("image:  ");
      //      printf(".jpeg\n");
      printf(".png\n");
      //      printf("texte:  ");
      //      printf(".txt\n");
    }
}

int     ft_error(char *prog_name, char *file, char *ext, int err_num)
{
  char  *oldfile;

  oldfile = NULL;

  printf("An error occured : ");
  printf("%s", prog_name);

  if (err_num == 1)
    {
      printf(" cannot open ");
      printf("%s", file);
      printf(" because this file does not exit\n");
      exit(0);
    }
  if (err_num == 2)
    {
      printf(" cannot create ");
      printf("%s\n", file);
      exit(0);
    }
  if (err_num == 3)
    {
      oldfile = ft_strsub(file, 0, (ft_strlen(file) - 5 - ft_strlen(ext)));
      printf(" cannot copy ");
      printf("%s", oldfile);
      printf(" to ");
      printf("%s\n", file);
      exit(0);
    }
  if (err_num == 4)
    {
      printf(" cannot close ");
      printf("%s\n", file);
      exit(0);
    }
  if (err_num == 5)
    {
      printf(" cannot create a copy of ");
      printf("%s", file);
      printf(" because [");
      printf("%s", ext);
      printf("] is not a valid type of file\n");
      ft_usage(prog_name, "", 2);
      exit(0);
    }
  if (err_num == 6)
    {
      printf(" cannot create a copy of ");
      printf("%s", file);
      printf(" because it is a directory\n");
      ft_usage(prog_name, "", 2);
      exit(0);
    }
  if (err_num == 7)
    {
      printf(" cannot create a copy. ");
      printf("%s", file);
      printf(" may be corrupted\n");
      ft_usage(prog_name, "", 2);
      exit(0);
    }
  exit(0);
  return (0);
}
