#include <unistd.h>
#include <stdio.h>

extern void ft_sort_int_tab(int *tab, int size);

int main(void)
{
	int tab[9] = {1, 6, 38, 43, 86, 97, 109, -3, 0};
	ft_sort_int_tab(tab, 9);
	for(int i = 0; i<9; i++)
	{
		printf("%d", tab[i]);
	}
}
