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

bool IsPalindromeMatrix(int arr[3][3], short Rows, short Cols)
{

    for (int i = 0; i < Rows; i++) {

        for (int j = 0; j < Cols / 2; j++) {

            if (arr[i][j] != arr[i][Cols - 1 - j])
                return false;
            
        }
    } 

    return true;
}

int main()
{
    int arr[3][3] = { {1, 2, 1}, {5, 5, 5}, {7, 3, 7} };

    cout << "\n3x3 Random Matrix\n";
    PrintMatrix(arr, 3, 3);

    if (IsPalindromeMatrix(arr, 3, 3))
        cout << "\nMatrix is Palindrome \n";
    else 
        cout << "\nMatrix is NOT Palindrome! \n";
    
    
}
