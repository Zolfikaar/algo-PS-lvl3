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

void PrintAllWordsInString(string S)
{
	string delim = " "; // delimeter
	string word;
	short pos = 0;

	cout << "\nString words are:\n";

	// use find function to get the position of the delimeter
	while ((pos = S.find(delim)) != string::npos)
	{
		word = S.substr(0, pos); // store the word

		if (word != "")
		{
			cout << word << endl;
		}

		S.erase(0, pos + delim.length()); // erase until position and move to next word
	}

	if (S != "")
		cout << S << endl; // print last word in the string
}

int main()
{
	PrintAllWordsInString(ReadString());

	system("pause>0");
}
