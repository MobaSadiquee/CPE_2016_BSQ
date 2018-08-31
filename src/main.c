/*
** main.c for main in /home/sadiqu-m/delivery/C_prog_elem/CPE_2016_BSQ/src
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Mon Dec  5 13:14:19 2016 Sadiqu-m
** Last update Sun Dec 18 14:58:34 2016 Sadiqu-m
*/

#include "my.h"

int	BSQ(char *str, int *size, int *buf)
{
  int	**bin;
  int	**map;
  int	hauteur;
  int	longueur;

  if ((size = mesure_size(str)) == NULL)
    {
      my_error("[Can't handle one col]\n");
      return (84);
    }
  if (size[0] == 0 || size[1] == 0)
    {
      my_error("[Map error]\n");
      return (84);
    }
  hauteur = size[0];
  longueur = size[1];
  bin = get_bin(str, hauteur, longueur);
  map = make_carre(bin, hauteur, longueur);
  buf = find_carre(map, hauteur, longueur);
  print_finalmap(map, hauteur, longueur, buf);
  free_bsq(bin, map);
  return (0);
}

int	free_bsq(int **bin, int **map)
{
  free(bin);
  free(map);
  return (0);
}

int	init_mem(char **str, int **size, int **buf)
{
  if ((*str = malloc(sizeof(char *))) == NULL)
    return (84);
  if ((*buf = malloc(sizeof(int *) * 4)) == NULL)
    return (84);
  if ((*size = malloc(sizeof(int *) * 2)) == NULL)
    return (84);
  return (0);
}

int	free_mem(char *str, int *size, int *buf, int fd)
{
  free(buf);
  free(size);
  free(str);
  close(fd);
  return (0);
}

int	main(int ac, char **av)
{
  char	*str;
  int	fd;
  int	*buf;
  int	*size;

  fd = 0;
  if (ac != 2)
      my_error("Usage : [Binary] [File]\n");
  else
    {
      if ((init_mem(&str, &size, &buf)) == 84)
      	return (84);
      buf[3] = 0;
      if ((fd = open(av[1], O_RDONLY)) == -1)
	{
	  my_error("File don't existe\n");
	  return (84);
	}
      if ((str = get_map(str, fd)) == NULL)
	return (84);
      if ((BSQ(str, size, buf)) == 84)
	return (84);
      free_mem(str, size, buf, fd);
    }
  return (0);
}
