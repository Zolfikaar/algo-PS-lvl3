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

char ReadCharacter()
{
	char C1;
	cout << "Please Enter a Character:\n";
	cin >> C1;
	return C1;
}

short CountLetterInString(string S, char C)
{
	short counter = 0;

	for (short i = 0; i < S.length(); i++)
	{
		if (S[i] == C)
			counter++;
	}

	return counter;
}

int main()
{
	string S = ReadString();
	char Letter = ReadCharacter();
	short Count = CountLetterInString(S, Letter);
	
	cout << "Letter " << Letter << " Count = " << Count;

	system("pause>0");
}
