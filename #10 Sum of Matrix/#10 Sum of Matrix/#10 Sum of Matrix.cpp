#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int from = 1, int to = 100)
{
    int rand_num = rand() % (to - from + 1) + from;

    return rand_num;
}

static void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
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

void PrintSumOfMatrix(int arr[3][3], short Rows, short Cols)
{
    int MatrixSum = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            MatrixSum += arr[i][j];
        }

    }
    cout << MatrixSum;
}

int main()
{
    // Seed the random number generator in c++, call it only once.
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "\n Random Matrix\n";
    PrintMatrix(arr, 3, 3);

    cout << "\nSum of Matrix\n";
    PrintSumOfMatrix(arr, 3, 3);

}
