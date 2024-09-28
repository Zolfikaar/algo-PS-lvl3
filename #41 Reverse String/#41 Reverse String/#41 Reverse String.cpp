#include <iostream>
#include <vector>
using namespace std;

vector <string> SplitString(string S, string Delim)
{
	vector <string> vString;

	short pos = 0;
	string sWord;

	// use find function to get the position of the delimeter
	while ((pos = S.find(Delim)) != string::npos)
	{
		sWord = S.substr(0, pos); // store the word

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S.erase(0, pos + Delim.length()); // erase until position and move to next word
	}

	if (S != "")
		vString.push_back(S); // print last word in the string

	return vString;
}

string ReverseString(string S1)
{
    vector <string> vString;
    string S2 = "";

	vString = SplitString(S1, " ");

    // declare vector iterator
    vector <string>::iterator itr = vString.end();

    while (itr != vString.begin())
    {
        --itr;
        S2 += *itr + " ";
    }

    S2 = S2.substr(0, S2.length() - 1); // Remove last space
    return S2;
}

int main()
{
    string S = "Mohammed Ahmed Hassan Ali";

    cout << "String after reverse: \n";
    cout << ReverseString(S);
    system("pause>0");
}