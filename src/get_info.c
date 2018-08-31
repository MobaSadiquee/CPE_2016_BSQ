/*
** get_info.c for get_info in /home/sadiqu-m/delivery/C_prog_elem/CPE_2016_BSQ/src
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Fri Dec  9 14:44:01 2016 Sadiqu-m
** Last update Sun Dec 18 12:28:22 2016 Sadiqu-m
*/

#include "my.h"

int	*mesure_size(char *str)
{
  int	*size;
  int	i;
  int	j;
  int	z;
  int	z2;

  i = 0;
  j = 0;
  z = 0;
  if ((size = malloc(sizeof(int) * 2)) == NULL)
    return (NULL);
  while (str[z] != '\n')
    z++;
  z++;
  z2 = z;
  j = count_line(str, z, j);
  z = z2;
  i = count_col(str, z, i);
  if (j == 1)
    return (NULL);
  size[0] = i;
  size[1] = j;
 return (size);
}

int	count_line(char *str, int z, int j)
{
  while (str[z] != '\n')
    {
      z++;
      j++;
    }
  return (j);
}

int	count_col(char *str, int z, int i)
{
  while (str[z] != '\0')
    {
      z++;
      if (str[z]== '\n')
	i++;
    }
  return (i);
}

int	**get_bin(char *str, int hauteur, int longueur)
{
  int	x;
  int	**result;
  int	i[2];

  i[0] = 0;
  i[1] = 0;
  result = malloc(sizeof(int *) * hauteur + 1);
  x = 1;
  while (*str != '\n')
    str++;
  while (str[x] != '\0')
    {
      result[i[0]] = malloc(sizeof(int *) * longueur);
      while (str[x] != '\n')
	{
	  if (str[x] == '.')
	    result[i[0]][i[1]] = 1;
	  else
	    result[i[0]][i[1]] = 0;
	  x++;
	  i[1]++;
	}
      x++;
      i[0]++;
      (str[x + 1] == '\0') ? (i[1] = 1) : (i[1] = 0);
    }
  return (result);
}

