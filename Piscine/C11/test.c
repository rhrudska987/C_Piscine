/*
	by. hyunjunk & haeem
*/
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdalign.h>
#include <time.h>
#include <immintrin.h>

#include "ex00/ft_foreach.c"
#include "ex01/ft_map.c"
#include "ex02/ft_any.c"
#include "ex03/ft_count_if.c"
#include "ex04/ft_is_sort.c"
#include "ex06/ft_sort_string_tab.c"
#include "ex07/ft_advanced_sort_string_tab.c"

void	ex00_func(int x)
{
	printf("%d ", x + 1);
}

int	ex01_func(int x)
{
	return (x - 1);
}

int ex02_func(char* x)
{
	return x[1] == 'm' ? 1 : 0;
}

int ex03_func(char* x)
{
	return x[1] == 'm' ? 1 : 0;
}

int ex04_func(int x,int y)
{
	return x - y;
}

int ex07_func(char* x, char* y)
{
	return strcmp(x, y);
}

int ex07_func_rev(char* x, char* y)
{
	return -strcmp(x, y);
}

int main()
{

	/* ex00 */
	printf("-ex00-\n");
	int ex00_arr[] = { 5, 4, 3, 2, 1 };
	printf("6 5 4 3 2\n");
	ft_foreach(ex00_arr, 5, ex00_func);
	printf("\n\n");

	/* ex01 */
	printf("-ex01-\n");
	int  ex01_arr[] = { 5, 4, 3, 2, 1 };
	int* ex01_ret;
	printf("4 3 2 1 0\n");
	ex01_ret = ft_map(ex01_arr, 5, ex01_func);
	for (int i = 0; i < 5; i++)
		printf("%d ", ex01_ret[i]);
	printf("\n\n");

	/* ex02 */
	printf("-ex02-\n");
	char* ex02_str1 = (char*)"hyunjunk";
	char* ex02_str2 = (char*)"haeem";
	char* ex02_str3 = (char*)"tmp";
	char* ex02_str4 = (char*)"trp";
	char* ex02_arr[] = { ex02_str1, ex02_str2, ex02_str4, ((char*)0)};
	assert(ft_any((char**)ex02_arr, ex02_func) == 0);
	char* ex02_arr2[] = { ex02_str1, ex02_str2, ex02_str3, ex02_str3, ((char*)0) };
	assert(ft_any((char**)ex02_arr2, ex02_func) == 1);
	printf("== test success ==\n\n");

	/* ex03 */
	printf("-ex03-\n");
	assert(ft_count_if((char**)ex02_arr, 3, ex03_func) == 0);
	assert(ft_count_if((char**)ex02_arr2, 4, ex03_func) == 2);
	printf("== test success ==\n\n");

	/* ex04 */
	printf("-ex04-\n");
	int	ex04_arr1[] = { 1, 2, 3, 4, 5 };
	int ex04_arr2[] = { 2, 3, 3, 4, 1 };
	int ex04_arr3[] = { 5, 5, 5, 4, 1 };
	int ex04_arr4[] = { 1, 2, 3, 2, 1 };
	int ex04_arr5[] = { -5, 1, 5, 128, 128 };
	assert(ft_is_sort(ex04_arr1, 5, ex04_func) == 1);
	assert(ft_is_sort(ex04_arr2, 5, ex04_func) == 0);
	assert(ft_is_sort(ex04_arr3, 5, ex04_func) == 1);
	assert(ft_is_sort(ex04_arr4, 5, ex04_func) == 0);
	assert(ft_is_sort(ex04_arr5, 5, ex04_func) == 1);
	int ex04_arr6[] = {26, 23, -9, -15, -17, 18, 19, 25, 28 ,39};
	assert(ft_is_sort(ex04_arr6, 10, ex04_func) == 0);
	printf("== test success ==\n\n");

	/* ex05 */
	printf("-ex05-\n");
	printf("이건 우리도 몰?루\n\n");

	/* ex06 */
	printf("-ex06-\n");
	/* Intentional remove const_trait for check DEEP_COPY(read only memory) */
	char* ex06_str1 = (char*)"abd";
	char* ex06_str2 = (char*)"abc";
	char* ex06_str3 = (char*)"a";
	char* ex06_str4 = (char*)"ab";
	alignas(16) 
	char* ex06_arr1[] = { ex06_str1, ex06_str2, ex06_str3, ex06_str4, ((char*)0) }; 
	ft_sort_string_tab((char**)ex06_arr1);
	/* Original code (필요시 꺼내드세요)
	assert(ex06_arr1[0] == ex06_str3); // "a"
	assert(ex06_arr1[1] == ex06_str4); // "ab"
	assert(ex06_arr1[2] == ex06_str2); // "abc"
	assert(ex06_arr1[3] == ex06_str1); // "abd"
	*/
	{ /* 심심하다... 위 코드와 동일합니다  */
		const __m128i x_ex06_arr_p1 = _mm_load_si128((const __m128i*)ex06_arr1);
		const __m128i x_ex06_arr_p2 = _mm_load_si128((const __m128i*)ex06_arr1 + 1);
		const __m128i x_ex06_answer_p1 = _mm_set_epi64x((int64_t)ex06_str4, (int64_t)ex06_str3);
		const __m128i x_ex06_answer_p2 = _mm_set_epi64x((int64_t)ex06_str1, (int64_t)ex06_str2);
		const __m128i x_ex06_compare_p1 = _mm_cmpeq_epi64(x_ex06_arr_p1, x_ex06_answer_p1);
		const __m128i x_ex06_compare_p2 = _mm_cmpeq_epi64(x_ex06_arr_p2, x_ex06_answer_p2);
		const int32_t x_ex06_compare_mask_p1 = _mm_movemask_epi8((__m128i)x_ex06_compare_p1);
		const int32_t x_ex06_compare_mask_p2 = _mm_movemask_epi8((__m128i)x_ex06_compare_p2);
		assert((uint32_t)((x_ex06_compare_mask_p1 << 16) | x_ex06_compare_mask_p2) == 0xFFFFFFFF);
	}
	printf("== test success ==\n\n");

	/* ex07 */
	printf("-ex07-\n");
	ft_advanced_sort_string_tab((char**)ex06_arr1, ex07_func);
	assert(ex06_arr1[0] == ex06_str3);
	assert(ex06_arr1[1] == ex06_str4);
	assert(ex06_arr1[2] == ex06_str2);
	assert(ex06_arr1[3] == ex06_str1);
	ft_advanced_sort_string_tab((char**)ex06_arr1, ex07_func_rev);
	assert(ex06_arr1[3] == ex06_str3); // "abd"
	assert(ex06_arr1[2] == ex06_str4); // "abc"
	assert(ex06_arr1[1] == ex06_str2); // "ab"
	assert(ex06_arr1[0] == ex06_str1); // "a"
	printf("== test success ==\n\n");

	return (0);
}
