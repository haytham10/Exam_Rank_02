#include <unistd.h>

int	main(int ac ,char **av)
{
	int	used[256] = {0};
	if (ac == 3)
	{
		char *s2 = av[2];
		char *s1 = av[1];

		while (*s2)
		{
			if (used[(int) *s2] == 0)
				used[(int) *s2] = 1;
			s2++;
		}
		while (*s1)
		{
			if (used[(int) *s1] == 1)
			{
				write (1,s1,1);
				used[(int) *s1] = 0;
			}
			s1++;
		}
	}
	write (1,"\n",1);
	return (0);
}
