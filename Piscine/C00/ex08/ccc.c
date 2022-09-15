#include <unistd.h>

 

void	push(char stack[], int *top, char data)

{

	stack[*top] = data;

	*top = *top + 1;

}

void	print_stack(char stack[], int n)

{

	write(1, stack, n);

	if (stack[0] != 10 - n + '0')

		write(1, ", ", 2);

}

 

void	ascending_sorting(char stack[], int *top, int n, int start)

{
	int		i;

	i = start;
	while (i <= 9)
	{
		if (stack[0] > 10 - n + '0')
			break ;
		push(stack, top, '0' + i);
		if (*top == n)
		{
			print_stack(stack, n);
			*top = *top -1;
		}
		else
		{
			ascending_sorting(stack, top, n, i + 1);
			*top = *top -1;
		}
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	stack[10];
	int		top;
 
	top = 0;
	ascending_sorting(stack, &top, n, 0);
}
