#include <iostream>
#include <string>

using namespace std;

char Vowels[5] = { 'a', 'i', 'o', 'u', 'e' };

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

bool isVowel(char Letter)
{
	char insensitiveVowel = tolower(Letter);

	for (char Vowel : Vowels)
		if (Vowel == insensitiveVowel)
			return true;
		else
			return false;
}

int main()
{

	char Letter = ReadCharacter();

	if(isVowel(Letter))
		cout << "Yes, The Letter " << Letter << " is Vawel" << endl;
	else
		cout << "No, The Letter " << Letter << " is NOT Vawel" << endl;

	system("pause>0");
}
