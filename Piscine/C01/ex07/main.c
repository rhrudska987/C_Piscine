#include <unistd.h>

extern void ft_rev_int_tab(int *tab, int size);

int main(void)
{
	int tab[5] = {1, 2, 3, 4, 5};
	ft_rev_int_tab(tab, 5);
	char a = tab[0] + '0';
	char b = tab[1] + '0';
	char c = tab[2] + '0';
	char d = tab[3] + '0';
	char e = tab[4] + '0';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	write(1, &d, 1);
	write(1, &e, 1);
}
