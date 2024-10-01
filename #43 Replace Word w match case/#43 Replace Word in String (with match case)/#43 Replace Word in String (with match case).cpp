#include <iostream>
#include <vector>
using namespace std;

vector <string> SplitString(string S, string Delim)
{
	vector <string> vString;

	short pos = 0;
	string sWord;

	// use find function to get the position of the delimeter
	while ((pos = S.find(Delim)) != string::npos)
	{
		sWord = S.substr(0, pos); // store the word

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S.erase(0, pos + Delim.length()); // erase until position and move to next word
	}

	if (S != "")
		vString.push_back(S); // print last word in the string

	return vString;
}

string LowerAllString(string Word)
{
	string sWord = "";
	for (char L : Word)
		sWord = tolower(L);

	return sWord;
}

string ReplaceWordInString(string S1, string Word, string WordToReplaceWith, bool isMatch = true)
{
	vector <string> vString;
	string S2 = "";

	vString = SplitString(S1, " ");

	for (string& item : vString) {
		if (isMatch) {

			if (item == Word) {
				item = WordToReplaceWith;
			}

		}
		else
		{
			if (LowerAllString(item) == LowerAllString(Word)) {
				item = WordToReplaceWith;
			}
		}
		
		S2 += item + " ";
	}

	S2 = S2.substr(0, S2.length() - 1); // Remove last space
	return S2;
}

int main()
{
	// To read string from console directlly, we can replace this string with ReadString() function from previuse tasks.
	string S = "Mohammed Ali Hassan Ali";
	cout << "String after replaceing (with match case): \n";
	cout << ReplaceWordInString(S, "ali", "USA") << endl;
	cout << "String after replaceing (without match case): \n";
	cout << ReplaceWordInString(S, "ali", "USA",false);
	system("pause>0");
}