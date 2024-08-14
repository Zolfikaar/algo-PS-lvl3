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

void PrintSumOfEachRowOfMatrix(int arr[3][3], short Rows, short Cols)
{
    int RowSum = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            RowSum += arr[i][j];
        }
        
        cout << "\nRow " << (i + 1) << " Sum = " << RowSum << endl;
        RowSum = 0;
    }
}

int main()
{
    // Seed the random number generator in c++, call it only once.
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "\nThe following is a 3x3 Random Matrix\n";
    PrintMatrix(arr, 3, 3);

    cout << "\nThe following are the sum of each row in Matrix\n";
    PrintSumOfEachRowOfMatrix(arr, 3, 3);

}
