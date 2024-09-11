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

short CountCapitalLetters(string S)
{
	short counter = 0;

	for (short i = 0; i < S.length(); i++)
	{
		if (isupper(S[i]))
			counter++;
	}

	return counter;
}

short CountSmallLetters(string S)
{
	short counter = 0;

	for (short i = 0; i < S.length(); i++)
	{
		if (islower(S[i]))
			counter++;
	}

	return counter;
}

int main()
{
	// PrintStringInfo(ReadString());
	string S = "Hello World, This Is C++ Course";
	cout << S;
	cout << "\nString Length = " << S.length();
	cout << "\nCapital Letters Count = " << CountCapitalLetters(S);
	cout << "\nSmall Letters Count = " << CountSmallLetters(S);

	system("pause>0");
}
