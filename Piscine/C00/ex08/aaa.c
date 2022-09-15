#include <unistd.h>
void    ft_print_combn(int n);
void    combn_one(char arr[], int n);
void    combn_two(char arr[], int n, int l);
void    reset_arr(char arr[], int n, int l);
void    ft_print_combn(int n)
{
    char    arr[10];
    int     i;
    i = 0;
    while (i < n)
    {
        arr[i] = i + '0';
        i++;
    }
    combn_one(arr, n);
}
void    combn_one(char arr[], int n)
{
    int l;
    l = n - 1;
    if (l == 0)
    {
        while (arr[l] < '9')
        {
            write(1, arr, n);
            write(1, ", ", 2);
            arr[l] += 1;
        }
        write(1, arr, n);
    }
    else
    {
        combn_two(arr, n, l);
    }
}
void    combn_two(char arr[], int n, int l)
{
    while (arr[0] != (10 - n) + '0')
    {
        while (arr[l] <= '9')
        {
            write(1, arr, n);
            write(1, ", ", 2);
            arr[l] += 1;
        }
        reset_arr(arr, n, l);
    }
    write(1, arr, n);
}
void    reset_arr(char arr[], int n, int l)
{
    int check;
    while (l >= 0)
    {
        if (arr[l] > (10 - n + l) + '0')
        {
            arr[l - 1] += 1;
            check = l;
        }
        l--;
    }
    l = n - 1;
    while (check <= l)
    {
        arr[check] = arr[check - 1] + 1;
        check++;
    }
}
