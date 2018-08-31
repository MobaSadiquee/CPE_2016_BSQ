/*
** my.h for my.h in /home/sadiqu-m/delivery/C_prog_elem/CPE_2016_BSQ/include
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Mon Dec  5 13:10:12 2016 Sadiqu-m
** Last update Sun Dec 18 14:58:59 2016 Sadiqu-m
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

#ifndef BUFF_SIZE
# define BUFF_SIZE 1024 * 1024 * 5

void	my_putchar(char c);
void	my_putstr(char*str);
int	print_finalmap(int **map, int hauteur, int longueur, int *buf);
int	my_strlen(char *str);
int	my_error(char *str);
int     init_mem(char **str, int **size, int **buf);
int	*find_carre(int **map, int hauteur, int longueur);
int     **init_carre(int **map, int hauteur, int longueur);
int	**get_bin(char *str, int hauteur, int longueur);
int	*mesure_size(char *str);
int	**make_carre(int **map, int hauteur, int longueur);
int	check_xyz(int x, int y, int z);
int     BSQ(char *str, int *size, int *pos);
int     **transfert(int **src, int **dest, int y, int x);
int	free_mem(char *str, int *size, int *buf, int fd);
int     count_line(char *str, int z, int j);
int     count_col(char *str, int z, int i);
int     free_bsq(int **bin, int **map);
char	*my_realloc(char *str, int buff);
char	*my_strdup(char *dest, char *src);
char	*get_map(char *str, int fd);

#endif /* BUFF_SIZE */
#endif /* MY_H_ */
