/*
** bsq.c for bsq in /home/sadiqu-m/delivery/C_prog_elem/CPE_2016_BSQ/src
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Mon Dec  5 13:42:28 2016 Sadiqu-m
** Last update Sun Dec 18 12:59:38 2016 Sadiqu-m
*/

#include "my.h"

int	check_xyz(int x, int y, int z)
{
  int	size_x;
  int	size_y;
  int	size_z;

  size_x = x;
  size_y = y;
  size_z = z;
  if (size_x <= size_y && size_x <= size_z)
    return (size_x);
  else if (size_y <= size_x && size_y <= size_z)
    return (size_y);
  else if (size_z <= size_x && size_z <= size_y)
    return (size_z);
  return (0);
}

int	**init_carre(int **map, int y, int x)
{
  int i;
  int **new_carre;

  i = 0;
  if ((new_carre = malloc(sizeof(int *) * (y + 3))) == NULL)
    return (0);
  while (i < y)
  {
    new_carre[i] = malloc(sizeof(int) *(x + 3));
    i++;
  }
  new_carre = transfert(map, new_carre, y, x);
 return (new_carre);
}

int	**transfert(int **src, int **dest, int y, int x)
{
  int	i;

  i = 0;
  while (i < x)
    {
      dest[0][i] = src[0][i];
      i++;
    }
  i = 0;
  while (i < y)
    {
      dest[i][0] = src[i][0];
      i++;
    }
  return (dest);
}

int	**make_carre(int **map, int hauteur, int longueur)
{
  int	i;
  int	j;
  int	**new_carre;

  new_carre = init_carre(map, hauteur, longueur);
  j = 0;
  i = 1;
  while (i < hauteur)
    {
      while (j < longueur)
	{
	  if (map[i][j] == 0)
	    new_carre[i][j] = 0;
	  else
	    new_carre[i][j] = check_xyz(new_carre[i - 1][j - 1],
				    new_carre[i][j - 1], new_carre[i - 1][j]) + 1;
	  j++;
	}
      j = 1;
      i++;
    }
  return (new_carre);
}

int	*find_carre(int **map, int hauteur, int longueur)
{
  int	i;
  int	j;
  int	*pos;
  int	max;

  max = 0;
  pos = malloc(sizeof(int) * 3);
  i = hauteur - 1;
  j = longueur - 1;
  while (i >= 0)
    {
      while (j >= 0)
	{
	  if (map[i][j] >= max)
	    {
	      max = map[i][j];
	      pos[0] = j - (max - 1);
	      pos[1] = i - (max - 1);
	    }
	  j--;
	}
      j = longueur - 1;
      i--;
    }
  pos[2] = max;
  return (pos);
}
