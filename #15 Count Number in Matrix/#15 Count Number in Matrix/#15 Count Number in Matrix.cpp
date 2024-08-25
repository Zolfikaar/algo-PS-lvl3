#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int ReadNumber()
{
    int Number = 0;
    do
    {
        cout << "\nEnter a number to count in matrix: ";
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

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

int CountNumberInMatrix(int Number, int arr[3][3], short Rows, short Cols)
{
    int NumberCount = 0;

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (arr[i][j] == Number)
            {
                NumberCount++;
            }
        }
    }

    return NumberCount;
}

int main()
{
    // int arr[3][3] = { {1,2,3}, {0,1,0}, {0,0,1} };
    // int arr[3][3] = { {9,0,0}, {0,9,0}, {0,0,9} };
    int arr[3][3] = {{10, 0, 10}, {0, 10, 0}, {10, 0, 10}};

    cout << "\n3x3 Random Matrix\n";
    PrintMatrix(arr, 3, 3);

    int NumberToCount = ReadNumber();
    int CountResult = CountNumberInMatrix(NumberToCount, arr, 3, 3);

    cout << "Number " << NumberToCount << " count in the matrix is: " << CountResult << endl;
}
