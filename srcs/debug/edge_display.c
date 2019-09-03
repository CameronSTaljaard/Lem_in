#include <lem_in.h>

void	print_tab(char **tab, int size)
{
	int		y;
	int		x;

	y = -1;
	x = -1;
	while(++y < size)
	{
		while (++x < size)
		{
			tab[y][x] = '0';
			ft_putchar(tab[y][x]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		x = -1;
	}
}