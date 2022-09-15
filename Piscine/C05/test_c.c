#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

//#include "ex00/ft_iterative_factorial.c"
//#include "ex01/ft_recursive_factorial.c"
//#include "ex02/ft_iterative_power.c"
//#include "ex03/ft_recursive_power.c"
//#include "ex04/ft_fibonacci.c"
//#include "ex05/ft_sqrt.c"
//#include "ex06/ft_is_prime.c"
//#include "ex07/ft_find_next_prime.c"
#include "ex08/ft_ten_queens_puzzle.c"

int main()
{
	/* ex00 */
/*	assert(ft_iterative_factorial(0) == 1);
	assert(ft_iterative_factorial(-5) == 0);
	assert(ft_iterative_factorial(1) == 1);
	assert(ft_iterative_factorial(5) == 120);
*/
	// ex01 
/*	assert(ft_recursive_factorial(0) == 1);
	assert(ft_recursive_factorial(-5) == 0);
	assert(ft_recursive_factorial(1) == 1);
	assert(ft_recursive_factorial(5) == 120);
	assert(ft_recursive_factorial(10) == 3628800);
*/
   /*	 ex02 */
/*	assert(ft_iterative_power(0, 0) == 1);
	assert(ft_iterative_power(0, 15) == 0);
	assert(ft_iterative_power(7, -15) == 0);
	assert(ft_iterative_power(7, 7) == 823543);
*/
	/* ex03 */
/*	assert(ft_recursive_power(0, 0) == 1); 
	assert(ft_recursive_power(0, 15) == 0);
	assert(ft_recursive_power(7, -15) == 0);
	assert(ft_recursive_power(7, 7) == 823543);
*/	
	/* ex04 */
/*	assert(ft_fibonacci(-5) == -1);
	assert(ft_fibonacci(0) == 0);
	assert(ft_fibonacci(1) == 1);
	assert(ft_fibonacci(2) == 1);
	assert(ft_fibonacci(3) == 2);
	assert(ft_fibonacci(10) == 55);
*/
	/* ex05 */
/*	assert(ft_sqrt(-5) == 0);
	assert(ft_sqrt(0) == 0);
	assert(ft_sqrt(1) == 1);
	assert(ft_sqrt(15) == 0);
	assert(ft_sqrt(16) == 4);
	assert(ft_sqrt(81) == 9);
*/
	/* ex06 */
/*	assert(ft_is_prime(0) == 0);
	assert(ft_is_prime(1) == 0);
	assert(ft_is_prime(2) == 1);
	assert(ft_is_prime(3) == 1);
	assert(ft_is_prime(76) == 0);
	assert(ft_is_prime(97) == 1);
*/
	/* ex07 */
/*	assert(ft_find_next_prime(0) == 2);
	assert(ft_find_next_prime(54) == 59);
	assert(ft_find_next_prime(4) == 5);
	assert(ft_find_next_prime(90) == 97);
*/
	/* ex08 */
	assert(ft_ten_queens_puzzle() == 724); 
	
	return 0;
}
