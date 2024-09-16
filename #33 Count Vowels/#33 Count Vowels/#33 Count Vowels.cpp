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

bool isVowel(char Letter)
{
	Letter = tolower(Letter);

	return ((Letter == 'a') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u') || (Letter == 'e'));
}

short CountLetter(string S)
{
	short counter = 0;

	for (short i = 0; i < S.length(); i++)
	{
		if (isVowel(S[i]))
			counter++;
	}

	return counter;
}



int main()
{
	string S = ReadString();
	short VowelCount = CountLetter(S);

	if (VowelCount > 0) {
		cout << "Number of Vowels: " << VowelCount << endl;
	}
	else {
		cout << "There is No Vowel";
	}

	system("pause>0");
}
