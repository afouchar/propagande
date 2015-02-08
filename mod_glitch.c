#include "mod_image.h"

char	*ft_rand_write(char *buf, int ret)
{
  char		*str;
  int		del;
  int		r;
  int		i;

  i = 0;
  del = (rand() % 100) + 1;
  str = ft_strnew(ret);
    if (del <= 5)
        str = "";
    else if (del > 5 && del < 15)
        return(buf);
    else
      {
	while (i < ret)
	  {
	    r = (rand() % 65280) + 1;
	    str[i] = r;
	    i++;
	  }
      }
  return (str);
}

char	*ft_glitch(char *buf, int ret)
{
  int		cp;
  char		*str;
  static char	*save;

  cp = (rand() % 30) + 1;
  str = (char *)malloc(sizeof(char) * ret);
  if (cp <= 5 && save == NULL)
    {
      ft_putendl("save");
      save = ft_strnew(ret + 1);
      save = strdup(buf);
    }
  if (cp > 5 && cp <= 10 && save != NULL)
    {
      ft_putendl("copy");
      str = ft_strdup(save);
    }
  else
    str = ft_rand_write(buf, ret);
  return (str);
}

char    *ft_glitch_type(char *buf, int ret, int type)
{
  if (type == 1)
    ;
  if (type == 2)
    ;
  if (type == 3)
    ;
  if (type == 4)
    ;
  if (type == 5)
    ;
  if (type == 6)
    ;
  if (type == 7)
    ;
  if (type == 8)
    ;
  if (type == 9)
    return (ft_glitch(buf, ret));
  if (type == 10)
    ;
  if (type == 11)
    ;
  if (type == 12)
    ;
  return (buf);
}
