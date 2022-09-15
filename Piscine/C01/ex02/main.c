#include <unistd.h>

extern void ft_swap(int *a, int *b);

int main()
{
	int a = 7;
	int b = 8;
	ft_swap(&a, &b);

	char c = a + '0';
	char d = b + '0';
	write(1, &c, 1);
	write(1, &d, 1);
}
