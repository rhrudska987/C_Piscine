/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:40:10 by bena              #+#    #+#             */
/*   Updated: 2022/09/04 21:42:58 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//헤더 부분입니다. 나머지 c파일에 선언된 함수들을 불러옵니다.
//
//함수 목록
//ft_putchar : 문자를 출력해주는 함수입니다 (C00 01번 문제)
//check_validity : n x n 행렬 data에서 해당하는 위치의 값이 올바른 값인지 검사해줍니다.
//get_next_row : 특정 위치(row, column)에서 다음으로 값을 입력할 위치의 row를 반환합니다.
//get_next_column : 특정 위치(row, column)에서 다음으로 값을 입력할 위치의 column을 반환합니다.
//get_linear_data : 프로그램 실행 시 입력하는 문자열을 정수형 배열로 변환해줍니다.
//			(반환된 배열의 첫번째 값은 몇개의 숫자를 입력했는지 개수를 표시합니다.)
//get_data : get_linear_data로 얻어진 정수형 배열을 4 x n 사이즈의 2차원 배열로 변환합니다.
//		[4][0] 배열 위치에 n 값을 저장합니다. (4 x n 사이즈에 [4][0] 까지 총 4n + 1의 크기를 가짐)
//gen_matrix : 0으로 채워진 n x n 크기의 정수 2차원 배열을 생성하여 반환합니다.
//remove_matrix : 행 개수가 n인 2차원 배열을 free 명령어로 메모리 할당을 해제합니다.
//put_building : 특정 위치에서 1~9까지의 값을 대입하며 check_validity 함수를 통해 올바른 숫자가 놓여있는지 확인합니다.
//		올바른 숫자가 놓여져 있을 경우 get_next_row, get_next_column 함수로 반환되는 위치에 재귀함수를 호출합니다.
//calc_matrix : get_data로 얻어진 데이터로부터 문제를 풀이하고 답을 출력합니다. 해가 없을 경우 Error를 반환합니다.
//main : 메인 함수입니다, get_data 함수로 받은 입력값을 calc_matrix에 넣어 함수를 실행합니다.
#include <unistd.h>

void	ft_putchar(char c);
int		check_validity(int **data, int **input, int row, int column);
int		get_next_row(int n, int row, int column);
int		get_next_column(int n, int row, int column);
int		*get_linear_data(char *input_string);
int		**get_data(int *linear_data);
int		**gen_matrix(int n);
void	remove_matrix(int **data, int n);

int	put_building(int **data, int **input, int row, int column)
{
	int	i;
	int	n;
	int	next_row;
	int	next_column;


	i = 0;
	//input[4][0]의 위치에는 n값을 담고 있습니다. 이로부터 n값을 얻어냅니다.
	n = input[4][0];
	//재귀 호출시 사용할 다음 위치의 좌표를 계산합니다.
	next_row = get_next_row(n, row, column);
	next_column = get_next_column(n, row, column);
	//이제 row, column 위치에 1부터 9까지 값을 대입하며 해를 찾을 것입니다.
	while (++i <= n)
	{
		//row, column 위치에 값을 넣습니다.
		data[row][column] = i;
		//넣어진 값이 유효한 값인지 check_validity 함수로 검사합니다.
		if (check_validity(data, input, row, column))
		{
			//유효하다면 다음 위치(next_row, next_column)에서 동일하게 값을 찾습니다.
			//만약에 현재 위치가 마지막 위치(n - 1, n - 1)이라면 1을 리턴하며 종료합니다.
			if (row == n - 1 && column == n - 1)
				return (1);
			if (put_building(data, input, next_row, next_column))
				return (1);
		}
	}
	//1~9까지 값을 모두 대입해도 해를 찾지 못한경우 반복문이 끝나면서 0을 반환할 것입니다.
	//
	//이때 값만 그냥 반환하면 안되며, 반복문이 끝난 시점에서는 row, column 위치에 9가 대입되어 있기 때문에
	//반환하기 전에 0으로 값을 초기화 해줍니다.
	data[row][column] = 0;
	return (0);
}

void	calc_matrix(int **data, int **input, int n)
{
	int		i;
	int		j;

	// put_building 함수로 0,0 위치부터 값을 찾습니다.
	// n x n 행렬이 모두 완성되는 해를 찾으면 1를 반환하고 해가 없으면 0을 반환합니다.
	if (put_building(data, input, 0, 0))
	{
		//해를 찾은경우 n x n 행렬을 출력합니다.
		i = -1;
		while (++i < n)
		{
			j = -1;
			while (++j < n)
			{
				ft_putchar(data[i][j] + '0');
				if (j < n - 1)
					ft_putchar(' ');
			}
			ft_putchar('\n');
		}
		return ;
	}
	//해를 찾지 못해 if문 조건에서 0이 반환된 경우 Error 메세지가 출력됩니다.
	write(2, "Error\n", 6);
}

int	main(int ac, char **av)
{
	int	n; // 출력할 배열의 크기입니다, n x n 사이즈의 답을 구합니다.
	int	**data;
	int	**input;

	// 인자값이 2개가 아닌경우 에러를 출력하고 프로그램을 종료합니다. (파일이름, 입력한 인풋 문자열)
	if (ac != 2)
	{
		write(2, "Invalid Input\n", 14);
		return (0);
	}
	// 입력한 문자열을 정수형 배열로 변환합니다. 이때 비정상적인 인풋값인 경우 input[4]에 널 포인터를 넣습니다.
	input = get_data(get_linear_data(av[1]));
	// input[4] 위치에 널 포인터가 위치한다면, 입력된 값에 문제가 있는 상태입니다.
	if (input[4] == 0)
	{
		write(2, "Invalid Input\n", 14);
		//에러를 출력하고 input 배열을 remove_matrix 함수로 초기화합니다 (free)
		remove_matrix(input, 5);
		return (0);
	}
	// 널 포인터가 없다면 반환된 input[4][0] 위치에는 n의 크기가 기록되어 있습니다.
	n = input[4][0];
	// n x n 크기의 0으로 가득한 정수형 2차원 배열을 생성합니다.
	data = gen_matrix(n);
	// 계산을 시작합니다. 답을 찾는다면 정답이 출력되고 해가 없다면 Error 메세지를 출력합니다.
	calc_matrix(data, input, n);
	// 계산이 모두 끝나면 data와 input 배열을 둘다 초기화합니다.
	remove_matrix(data, n);
	remove_matrix(input, 5);
	return (0);
}
