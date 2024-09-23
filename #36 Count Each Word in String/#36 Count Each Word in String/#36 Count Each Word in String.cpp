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

short CountAllWordsInString(string S)
{
	string delim = " "; // delimeter
	string word;
	short pos = 0;
	short Counter = 0;

	// use find function to get the position of the delimeter
	while ((pos = S.find(delim)) != string::npos)
	{
		word = S.substr(0, pos); // store the word

		if (word != "")
		{
			Counter++;
		}

		S.erase(0, pos + delim.length()); // erase until position and move to next word
	}

	if (S != "")
		Counter++; // print last word in the string

	return Counter;
}

int main()
{
	cout << "The number of words in the string is: " <<  CountAllWordsInString(ReadString());

	system("pause>0");
}
