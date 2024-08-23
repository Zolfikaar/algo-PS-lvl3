#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int from = 1, int to = 100)
{
    int rand_num = rand() % (to - from + 1) + from;

    return rand_num;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            arr[i][j] = RandomNumber(0,1);
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

bool IsIdentityMatrix(int arr[3][3], short Rows, short Cols)
{
    
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            //check for diagonal elements  || // check for the rest elements
            if ((i == j && arr[i][j] != 1) || (i != j && arr[i][j] != 0)) {
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

    //int arr[3][3] = { {1,2,3}, {0,1,0}, {0,0,1} };
    int arr[3][3] = { {1,0,0}, {0,1,0}, {0,0,1} };

    //FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "\n3x3 Random Matrix\n";
    PrintMatrix(arr, 3, 3);

    if (IsIdentityMatrix(arr, 3, 3)) {
        cout << "\nYes, Matrix is Identity\n";
    }
    else {
        cout << "\nNo, Matrix is NOT Identity!\n";
    }
}
