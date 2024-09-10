#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string S1;
	cout << "Please Enter Your String\n";
	getline(cin, S1);
	return S1;
}

void PrintInvertedString(string S1)
{

	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ')
		{
			S1[i] = S1[i] == tolower(S1[i]) ? toupper(S1[i]) : tolower(S1[i]);
		}
	}

	cout << "\nUpper String:\n";
	cout << S1;
}



int main()
{
	// PrintInvertedString(ReadString());
	string S = "hello World, this is C++ Course";
	cout << "\nString before convertion:\n";
	cout << S;
	PrintInvertedString(S);
}
