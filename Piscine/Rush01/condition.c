/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:40:10 by bena              #+#    #+#             */
/*   Updated: 2022/09/04 21:31:10 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// 특정 행, 열에서 쳐다봤을 때 보이는 건물의 숫자를 구해줍니다.
// reverse 인자값이 0이면, 왼쪽이나 위쪽에서 본 값을
// reverse 인자값이 1이면 오른쪽이나 아래쪽에서 본 값을 반환합니다.
int	num_of_building(int *row, int n, int reverse)
{
	int	i;
	int	height;
	int	count;
	int	selected_building;

	//알고리즘은 다음과 같습니다.
	//
	// 1 3 5 2 4 로 건물이 배치되어 있으면.
	// 왼쪽에서 보이는 건물 수는 3, 오른쪽에서 보이는 수는 2입니다.
	// 왼쪽에서 보이는 건물 수를 확인할 때
	// 첫번째 값부터 순서대로 확인합니다.
	// 그리고 발견한 건물중 가장 높은 건물의 높이를 height 변수에 저장해 둡니다.
	// height 변수보다 높은 건물이 발견되면 count 변수를 1 증가시킵니다.
	// height 값이 n과 같아지면 반복을 종료합니다. (이부분은 필수는 아니지만 연산 최적화를 위함)
	// height의 초기값은 0입니다. (1짜리 건물이 발견되어도 count가 1 늘어나면서 height가 1로 설정됨)
	// 마지막에 count 값을 반환하면 왼쪽에서 보이는 건물 숫자가 나옵니다.
	i = -1;
	height = 0;
	count = 0;

	//첫번째 위치 값부터 마지막 위치까지 반복하며 확인합니다.
	while (++i < n)
	{
		// reverse 가 0인 경우 0부터 1씩 증가시키며 비교합니다.
		if (reverse == 0)
			selected_building = row[i];
		// reverse 가 1인 경우 n - 1부터 1씩 감소시키며 비교합니다.
		if (reverse == 1)
			selected_building = row[n - 1 - i];
		// i값을 증가시키며 발견한 건물들보다 더 높은 건물이 발견되면, count 수를 증가시킵니다.
		if (height < selected_building)
		{
			//발견한 건물 중 가장 높은 건물의 높이를 height에 기록해 놓습니다.
			height = selected_building;
			//발견할 때마다 count 값을 증가시킵니다.
			count++;
			//height가 n이 되면 그보다 높은 건물을 발견할 경우는 존재하지 않습니다. 즉시 종료합니다.
			if (height == n)
				break ;
		}
	}
	return (count);
}
 

// index 위치의 행 또는 열을 number_of_building 함수를 이용하여 input 값과 비교합니다.
// horizontal 이 1이면 행을 비교하고 0이면 열을 비교합니다.
//
// 값이 일치하면 1을, 하나라도 일치하지 않으면 0을 반환합니다.
int	check_view(int *array, int **input, int index, int horizontal)
{
	int	n;

	//input 배열의 [4][0] 위치에는 n 값이 저장되어 있으므로 n값을 얻어옵니다.
	n = input[4][0];
	// input 배열에서 상 하 좌 우 순서대로 [0~3] 배열에 저장되어 있으므로
	// 상, 하는 [0], [1]
	// 좌, 우는 [2], [3] 입니다.
	// horizontal 이 1이면 2, 3값이 대입되어 index 위치의 행 양 끝의 input값을 읽고
	// 0이면 0, 1값이 대입되어 index 위치의 열 양 끝의 input 값을 읽습니다.
	if (num_of_building(array, n, 0) != input[horizontal * 2][index])
		return (0);
	if (num_of_building(array, n, 1) != input[horizontal * 2 + 1][index])
		return (0);
	return (1);
}

//숫자가 일치하는지 비교합니다.
//특정 열에 1~9까지 겹치지 않고 숫자가 존재하는지.
//그리고 각 행, 열의 보이는 건물 수가 input값과 일치하는지 확인합니다.
int	check_validity(int **data, int **input, int row, int column)
{
	int	i;
	//n은 최대 9까지 가능하므로 배열 크기를 9로 선언합니다.
	int	temp_row[9];
	int	temp_column[9];
	int	n;

	// input 배열의 [4][0] 위치에는 n값이 저장되어 있습니다.
	n = input[4][0];
	i = -1;
	//각 행, 열에서 같은 숫자가 존재하는지 반복문으로 확인합니다.
	while (++i < n)
	{
		//행 위치를 고정한 상태에서 열 인덱스 i만 변경하며 조건을 비교합니다.
		//같은 행 안에 동일한 숫자가 있는지 확인할 것입니다.
		//자기 자신과 비교하면 안되므로 column != i 조건을 넣었습니다.
		if (data[row][column] == data[row][i] && column != i)
			return (0);
		//열 위치를 고정한 상태에서 행 인덱스 i만 변경하며 조건을 비교합니다.
		//같은 열 안에 동일한 숫자가 있는지 확인할 것입니다.
		//자기 자신과 비교하면 안되므로 row != i 조건을 넣었습니다.
		if (data[row][column] == data[i][column] && row != i)
			return (0);
		//같은 숫자가 발견되면 0을 반환하며 즉시 종료합니다.
		//
		//
		//위에서 값을 확인하는 동안 input값과 보이는 건물 숫자를 비교하기 위해 사용할
		//행 배열, 열 배열을 동시에 만듭니다.
		temp_row[i] = data[row][i];
		temp_column[i] = data[i][column];
	}
	//반복문이 종료되면 temp_row에는 row위치의 행이 저장되어 있고
	//temp_column에는 column 위치의 열이 저장되어 있습니다.
	//
	//check_view 함수를 이용하여 row 행의 값을 input 값과 비교합니다.
	if (column == n - 1)
		if (!check_view(temp_row, input, row, 1))
			return (0);
	//check_view 함수를 이용하여 column 열의 값을 input 값과 비교합니다.
	if (row == n - 1)
		if (!check_view(temp_column, input, column, 0))
			return (0);
	//input값과 하나라도 일치하지 않는다면 0을 반환할 것입니다.
	//
	//
	//위 검사들을 모두 통과해내면 유효한 값이므로 1을 반환합니다.
	return (1);
}


//다음 두 함수는 put_building 함수에서 탐색할 위치의 순서를 담고 있습니다.
//설명보다는 그림이 이해가 빠르므로 그림을 첨부하겠습니다.
//
//행, 열을 교차로 검색합니다. 행 순서대로 검색하는 것보다 훨씬 최적화된 결과를 보여줍니다.
//
// 다음 그림과 같은 순서로 검색합니다.
//
// 01 02 03 04 05
// 06 10 11 12 13
// 07 14 17 18 19
// 08 15 20 22 23
// 09 16 21 24 25
//
// →→→→→
// ↓→→→→
// ↓↓→→→
// ↓↓↓→→
// ↓↓↓↓☆
//
// 
int	get_next_row(int n, int row, int column)
{
	// row <= column 은 위 그림에서 오른쪽 화살표가 적혀있는 위치들입니다.
	if (row <= column)
	{
		//마지막 열 위치까지 전까지는 행 값은 동일합니다.
		if (column < n - 1)
			return (row);
		//마지막 열이 되면 다음 위치는 행 값이 1 증가합니다.
		if (column == n - 1)
			return (row + 1);
	}
	// row > column 은 위 그림에서 아래쪽 화살표가 적혀있는 위치들입니다.
	if (row > column)
	{
		//마지막 행 전까지는 행 값이 1씩 증가합니다.
		if (row < n - 1)
			return (row + 1);
		//마지막 행이 되면 다음 행의 위치는 열 값 + 1이 됩니다.
		if (row == n - 1)
			return (column + 1);
	}
	return (0);
}

int	get_next_column(int n, int row, int column)
{
	// row <= column 은 위 그림에서 오른쪽 화살표가 적혀있는 위치들입니다.
	if (row <= column)
	{
		//마지막 열 전까지는 열 값이 1씩 증가합니다.
		if (column < n - 1)
			return (column + 1);
		//마지막 열이 되면 다음 열 값은 현재의 행 값과 같아집니다.
		if (column == n - 1)
			return (row);
	}
	// row > column 은 위 그림에서 아래쪽 화살표가 적혀있는 위치들입니다.
	if (row > column)
	{
		// 마지막 행 전까지는 열 위치는 동일합니다.
		if (row < n - 1)
			return (column);
		// 마지막 행이 되면 다음 열의 위치는 한칸 오른쪽으로 이동합니다.
		if (row == n - 1)
			return (column + 1);
	}
	return (0);
}
