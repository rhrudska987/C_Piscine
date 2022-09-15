#include<unistd.h>

extern void ft_putstr(char *str);

int main(void)
{
	char *str = "Hello World!";
	ft_putstr(str);
}
