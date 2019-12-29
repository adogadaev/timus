//============================================================================
// Name        : id1017.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : 1017. Staircases Time limit: 1.0 second Memory limit: 64 MB
//============================================================================

#include <cstring>
#include <iostream>
using namespace std;

// solution(n) = \sum_{i=2}^{l}{solution(n-i, i)} + 1

int64_t getStaircaseNumFast(unsigned int nCubes)
{
	int64_t answers[501][501];
	memset(answers, 0, 501*501*sizeof(int64_t));

	for (unsigned int i = 0; i < 501; i++)
		answers[i][i] = 1;
	for (unsigned int i = 1; i < 501; i++)
	{
		for (unsigned int j = i - 1; j >= 1; j--)
		{
			answers[i][j] = answers[i][j + 1] + answers[i - j][j + 1];
		}
	}

	return answers[nCubes][1];
}

int64_t getStaircaseNum(unsigned int nCubes, unsigned int prevHeight)
{
	if (nCubes < (2 * prevHeight + 3))
		return 1;
	int64_t total = 1;
	for (unsigned int i = prevHeight + 1; nCubes > 2*i; i++)
		total += getStaircaseNum(nCubes - i, i);
	return total;
}

int main() {
	unsigned int obj_num;
	cin >> obj_num;
	//int64_t answer = getStaircaseNum(obj_num, 0) - 1;
	int64_t answer = getStaircaseNumFast(obj_num) - 1;
	cout << answer;
	return 0;
}


/*
 * 2*x = (n^2 + n)
3 - 1
5 - 2
6 - 3
7 - 4
8 - 5
9 - 7
10 - 9
11 - 11
12 - 14
13 - 17
14 - 21
15 - 26   i
       i  i
i   i  i  i
i   ii i  i
ii  ii ii i
iii ii ii ii

          i
       i  i
i   i  i  i
i   i  i  i  i
i   ii i  i  ii
ii  ii ii i  ii
iii ii ii ii iii
 *
 */
