/*
** my_basic_fonc.c for my_basic_fonc in /home/sadiqu-m/delivery/C_prog_elem/CPE_2016_BSQ/src
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Mon Dec  5 13:11:17 2016 Sadiqu-m
** Last update Sun Dec 18 18:29:41 2016 Sadiqu-m
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char	*my_realloc(char *str, int buff)
{
  char	*new_str;
  int	i;

  i = 0;
  if ((new_str = malloc(sizeof(char) * (buff + 1))) == NULL)
      return (NULL);
  while (str[i] != '\0')
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}

char	*my_strdup(char *dest, char *src)
{
  int	i;

  i = 0;
  dest = my_realloc(dest, BUFF_SIZE);
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
