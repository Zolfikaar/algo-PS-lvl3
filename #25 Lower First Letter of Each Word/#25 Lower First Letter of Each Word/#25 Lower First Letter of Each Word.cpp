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

void PrintFirstLetterOfEachWord(string S1)
{
	bool isFirstLetter = true;

	cout << "\nString before convertion:\n";
	cout << S1;

	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			S1[i] = tolower(S1[i]);
		}

		isFirstLetter = (S1[i] == ' ' ? true : false);
	}

	cout << "\nString after convertion:\n";
	cout << S1;
}

int main()
{
	//PrintFirstLetterOfEachWord(ReadString());
	string S = "hello World, this is C++ Course";
	PrintFirstLetterOfEachWord(S);
}
