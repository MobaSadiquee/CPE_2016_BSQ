/*
** display_map.c for display_map in /home/sadiqu-m/delivery/C_prog_elem/CPE_2016_BSQ/src
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Thu Dec  8 16:04:19 2016 Sadiqu-m
** Last update Tue Jan 31 11:18:03 2017 Sadiqu-m
*/

#include "my.h"

int	my_error(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i++;
    }
  return (0);
}

int	print_finalmap(int **map, int hauteur, int longueur, int *buf)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < hauteur)
    {
      while (j < longueur)
	{
	  if ((i >= buf[1] && i < buf[1] + buf[2])
	      && (j >= buf[0] && j < buf[0] + buf[2]))
	    my_putchar('x');
	  else if (map[i][j] != 0)
	    my_putchar('.');
	  else
	    my_putchar('o');
	  j++;
	}
      my_putchar('\n');
      j = 0;
      i++;
    }
  return (0);
}
