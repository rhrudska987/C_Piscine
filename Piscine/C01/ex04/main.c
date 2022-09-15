#include <unistd.h>

extern void ft_ultimate_div_mod(int *a, int *b);

int main(void)
{
	int a = 10;
	int b = 6;

	ft_ultimate_div_mod(&a, &b);

	char c = a + '0';
	char d = b + '0';
	write(1, &c, 1);
	write(1, &d, 1);
}

