#include <unistd.h>
extern void ft_is_negative(int);
int main(void) {
    ft_is_negative(-2147483648);
    return 0;
}
