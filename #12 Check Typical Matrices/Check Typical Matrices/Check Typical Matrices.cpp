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
	int counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			counter++;
			arr1[i][j] = counter; // RandomNumber(1, 10);
			arr2[i][j] = counter; // RandomNumber(1, 10);
		}
	}
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

bool CheckMatricesTypicalEquality(int arr1[3][3], int arr2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (arr1[i][j] != arr2[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	// Seed the random number generator in c++, call it only once.
	srand((unsigned)time(NULL));
	int arr1[3][3], arr2[3][3], ResultArr[3][3];

	FillMatrixWithRandomNumbers(arr1, arr2, 3, 3);
	cout << "\nFirst matrix:\n";
	PrintMatrix(arr1, 3, 3);
	cout << "\nSecond matrix:\n";
	PrintMatrix(arr2, 3, 3);

	if (CheckMatricesTypicalEquality(arr1, arr2, 3, 3))
	{
		cout << "\nYes, The matrices are equal\n";
	}
	else
	{
		cout << "\nNo, The matrices are Not equal\n";
	}

	system("pause>0");
}