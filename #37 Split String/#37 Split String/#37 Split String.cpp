#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
	string S1;
	cout << "Please Enter Your String\n";
	getline(cin, S1);
	return S1;
}

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

int main()
{
	vector <string> vString;

	vString = SplitString(ReadString(), " ");

	cout << "Tokens = " << vString.size() << endl;

	for (string& S : vString)
		cout << S << endl;

	system("pause>0");
}
