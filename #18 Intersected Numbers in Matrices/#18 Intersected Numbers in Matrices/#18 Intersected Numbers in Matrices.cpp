#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>

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

void PrintIntersectedNumbers(vector<int> &Numbers)
{
	if (Numbers.size() > 0)
	{

		if (Numbers.size() == 1)
			cout << "Intersected Number is: \n";
		else
			cout << "Intersected Numbers are: \n";

		for (int & Number : Numbers)
		{
			cout << Number << "   ";
		}
	}
	else
		cout << "There are No Intersected Numbers! \n";
}

void CheckIntersectedNumbersInMatrices(int arr1[3][3], int arr2[3][3], short Rows, short Cols)
{
	vector<int> IntersectedNumbers;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (arr1[i][j] == arr2[i][j])
			{
				IntersectedNumbers.push_back(arr1[i][j]);
			}
		}
	}

	PrintIntersectedNumbers(IntersectedNumbers);
}

int main()
{
	// Seed the random number generator in c++, call it only once.
	srand((unsigned)time(NULL));

	int arr1[3][3], arr2[3][3];

	FillMatrixWithRandomNumbers(arr1, arr2, 3, 3);
	cout << "\nFirst matrix:\n";
	PrintMatrix(arr1, 3, 3);
	cout << "\nSecond matrix:\n";
	PrintMatrix(arr2, 3, 3);

	CheckIntersectedNumbersInMatrices(arr1, arr2, 3, 3);
}