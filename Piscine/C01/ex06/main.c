#include<unistd.h>

extern int ft_strlen(char *str);

int main(void)
{
	char *str = "Hello Wod";
	int len = ft_strlen(str);
	char c = len + '0';
	write(1, &c, 1);
}
