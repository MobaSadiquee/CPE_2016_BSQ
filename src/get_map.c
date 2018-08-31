/*
** get_map.c for get_map in /home/sadiqu-m/delivery/C_prog_elem/CPE_2016_BSQ/src
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Mon Dec  5 13:48:05 2016 Sadiqu-m
** Last update Sun Dec 18 14:58:46 2016 Sadiqu-m
*/

#include "my.h"

char	*get_map(char *str, int fd)
{
  char	c[BUFF_SIZE];
  int	i;
  int	j;

  i = 1;
  j = 0;
  while ((i = read(fd, c, BUFF_SIZE)))
    {
      str = my_strdup(str, c);
      j++;
    }
  if (j > 2)
    {
      my_error("[Too big]\n");
      return (NULL);
    }
  c[i] = '\0';
  return (str);
}
