#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Forward declaration
void PrintArrayOfSums(int arr[3], short Rows);

int RandomNumber(int from = 1, int to = 100)
{
    int rand_num = rand() % (to - from + 1) + from;

    return rand_num;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            arr[i][j] = RandomNumber();
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cout << setw(3) << arr[i][j] << "    ";
        }
        cout << "\n";
    }
}

void PrintSumOfEachColumnOfMatrix(int arr[3][3], short Rows, short Cols)
{
    int SumsArr[3] = {};
    int ColSum = 0;
    for (int j = 0; j < Cols; j++) {
        for (int i = 0; i < Rows; i++) {
            ColSum += arr[i][j];
        }

        cout << "\nColumn " << (j + 1) << " Sum = " << ColSum << endl;
        SumsArr[j] = ColSum;
        ColSum = 0;
    }

    PrintArrayOfSums(SumsArr, Rows);
}

void PrintArrayOfSums(int arr[3], short Rows)
{
    cout << "\nThe array of Sums is: \n";
    for (int i = 0; i < Rows; i++) {
        cout << arr[i] << "   ";
    }
    cout << "\n";
}

int main()
{
    // Seed the random number generator in c++, call it only once.
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "The following is a 3x3 Random Matrix\n";
    PrintMatrix(arr, 3, 3);

    cout << "\nThe following are the sum of each column in Matrix\n";
    PrintSumOfEachColumnOfMatrix(arr, 3, 3);

}
