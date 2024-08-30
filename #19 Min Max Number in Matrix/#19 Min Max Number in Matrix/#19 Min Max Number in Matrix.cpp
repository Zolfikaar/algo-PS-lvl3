#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "    ";
        }
        cout << "\n";
    }
}

void CheckMinMaxInMatrix(int arr[3][3], short Rows, short Cols)
{
    int Min = arr[0][0], Max = arr[0][0];

    for (int i = 0; i < Rows; i++) {

        for (int j = 0; j < Cols; j++) {

            if (arr[i][j] < Min)
                Min = arr[i][j];

            if (arr[i][j] > Max)
                Max = arr[i][j];
        }
    }

    cout << "\nMin Number: \n" << Min;
    cout << "\nMax Number: \n" << Max;

}



int main()
{
    int arr[3][3] = { {9, 30, 1}, {44, 4, 65}, {2, 99, 200} };

    cout << "\n3x3 Random Matrix\n";
    PrintMatrix(arr, 3, 3);

    CheckMinMaxInMatrix(arr, 3, 3);
}
