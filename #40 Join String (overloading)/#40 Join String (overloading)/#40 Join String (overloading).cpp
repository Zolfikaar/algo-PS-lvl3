#include <iostream>
#include <vector>
using namespace std;

string JoinString(vector <string> vString, string Delim)
{
    string S1;

    for (string& s : vString)
        S1 = S1 + s + Delim;

    return S1.substr(0, S1.length() - Delim.length());
}

string JoinString(string arrString[], string Delim, int Length)
{
    string S1;

    for (int i = 0; i < Length; i++)
        S1 = S1 + arrString[i] + Delim;

    return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
    string arr[] = { "Mohammed", "Ahmed", "Hassan", "Ali" };
    vector <string> vString{ "Mohammed", "Ahmed", "Hassan", "Ali" };

    cout << "Vector after join \n";
    cout << JoinString(vString, " ") << endl;

    cout << "Array after join \n";
    cout << JoinString(arr, ",", 4);
    system("pause>0");
}