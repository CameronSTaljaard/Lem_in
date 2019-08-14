
#include <lem_in.h>

void	intro(void)
{
	static int 		i = -1;
	static int		j = -1;
	const char		*dir[] = {"\033[1;34mTHE GOAL OF THIS PROJECT:",
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
		"QUICKEST WAY TO GET N ANTS FROM START TO END",
		"AT TURN 0 ALL ANTS ARE IN ROOM [START]",
		"ONLY ONE ANT PER ROOM THAT ISN'T [START] OR [END]",
		"AT EACH TURN, DISPLAY ONLY THE ANTS THAT HAVE MOVED",
		"ANTS CAN ONLY MOVE ONE ROOM PER TURN"};
	const char		*err[] = {"\033[0;32mLIST OF ERRORS ACCOUNTED FOR:",
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
		"FIRST LINE MUST BE A POSITIVE INTEGER",
		"ROOMS SHOULD BE FORMATTED CORRECTLY (NAME X Y)",
		"X AND Y SHOULD BE INTEGERS",
		"ROOM NAMES SHOULD NOT START WITH 'L'",
		"##start FOLLOWED BY [START] ROOM",
		"##end FOLLOWED BY [END] ROOM",
		"##start DECLARED EXACTLY ONCE",
		"##end DECLARED EXACTLY ONCE",
		"ROOM LINKS SHOULD BE FORMATTED CORRECTLY (NAME1-NAME2)",
		"NO ROOMS DECLARED AFTER ANY LINKS",
		"\n\033[1;32mLIST OF ERRORS UNACCOUNTED FOR:",
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
		"[START] AND [END] NOT INTERLINKED",
		"ROOMS HAVING THE SAME NAME",
		"ROOMS HAVING THE SAME CO-ORDINATES",
		"idk what else..."};

	while (++i < 7)
		ft_putendl(dir[i]);
	ft_putchar('\n');
	while (++j < 18)
		ft_putendl(err[j]);
	ft_putstr("\n\033[0;36m");
}

void	disp_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
	printf("\n\n");
}

void	disp_rooms(t_room *rooms)
{
	while (rooms)
	{
		ft_putstr_col_fd(GREEN, "Room: ", 1);
		ft_putendl_col_fd(GREEN, rooms->name, 1);

		ft_putstr("Location: ");
		ft_putnbr_col_fd(CYAN, rooms->pos.x, 1);
		ft_putchar(' ');
		ft_putnbr_col_fd(CYAN, rooms->pos.y, 1);
		ft_putendl("");
		ft_putstr("Links:");
		ft_putchar(' ');
		while (rooms->links)
		{
			ft_putstr_col_fd(CYAN, rooms->links->link, 1);
			ft_putchar(' ');
			rooms->links = rooms->links->next;
			(rooms->links) ? (ft_putstr("and ")) : NULL;
		}
		ft_putendl("");
		ft_putendl("");
		rooms = rooms->next;
	}
}