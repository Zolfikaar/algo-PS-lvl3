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

void PrintAllVowelsInString(string S)
{
	cout << "Vowels in string are: \n";
	for (short i = 0; i < S.length(); i++)
	{
		if (isVowel(S[i]))
			cout << S[i] << "  ";
	}

}



int main()
{
	string S = ReadString();
	PrintAllVowelsInString(S);


	system("pause>0");
}
