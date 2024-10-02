#include <iostream>
using namespace std;

string RemovePunctuations(string S1)
{
    string S2 = "";

    for (short i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i])) {
            S2 += S1[i];
        }
    }

    return S2;
}

int main()
{
    string S = "Hi, this is some random text, it's good thing!";
    cout << "Original String: \n";
    cout << S << endl;
    cout << "Punctuations Removed: \n";
    cout << RemovePunctuations(S);
    system("pause>0");
}