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

char InvertedCharacterCase(char Letter)
{
	return islower(Letter) ? toupper(Letter) : tolower(Letter);
}

short CountLetter(string S, char Letter, bool MatchCase = true)
{
	short counter = 0;

	for (short i = 0; i < S.length(); i++)
	{
		if (MatchCase)
		{
			if (S[i] == Letter)
				counter++;
		}
		else 
		{
			if (tolower(S[i]) == tolower(Letter))
				counter++;
		}
		
	}

	return counter;
}

int main()
{
	string S = ReadString();
	char Letter = ReadCharacter();

	cout << "Letter '" << Letter << "' Count = " << CountLetter(S, Letter) << endl;
	cout << "Letter '" << Letter << "' Or '" << InvertedCharacterCase(Letter) << "' Count = " << CountLetter(S, Letter,false);

	system("pause>0");
}
