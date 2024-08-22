#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int from = 1, int to = 100)
{
	int rand_num = rand() % (to - from + 1) + from;

	return rand_num;
}

void FillMatrixWithRandomNumbers(int arr1[3][3], int arr2[3][3], short Rows, short Cols)
{

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr1[i][j] = RandomNumber(1, 10);
			arr2[i][j] = RandomNumber(1, 10);
		}
	}
}

int SumOfMatrix(int arr[3][3], short Rows, short Cols)
{
	int ArrSum = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			ArrSum += arr[i][j];
		}
	}

	return ArrSum;
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << arr[i][j] << "   ";
		}
		cout << "\n";
	}
}

bool CheckMatricesEquality(int arr1[3][3], int arr2[3][3], short Rows, short Cols)
{
	return (SumOfMatrix(arr1, Rows, Cols) == SumOfMatrix(arr2, Rows, Cols));
}
int main()
{
	// Seed the random number generator in c++, call it only once.
	srand((unsigned)time(NULL));
	int arr1[3][3], arr2[3][3], ResultArr[3][3];

	FillMatrixWithRandomNumbers(arr1, arr2, 3, 3);
	cout << "\nThe following is the first matrix:\n";
	PrintMatrix(arr1, 3, 3);
	cout << "\nThe following is the second matrix:\n";
	PrintMatrix(arr2, 3, 3);


	if (CheckMatricesEquality(arr1, arr2, 3, 3)) {
		cout << "\nYes, The two matrices are equal\n";
	}
	else {
		cout << "\nNo, The two matrices are Not equal\n";
	}

	system("pause>0");
}