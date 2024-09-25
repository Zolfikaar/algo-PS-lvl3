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

string TrimLeft(string S)
{
	for (short i = 0; i < S.length(); i++)
	{
		if(S[i] != ' ')
			return S.substr(i, S.length() - i );
	}
			
	return "";
}

string TrimRight(string S)
{
	for (short i = S.length(); i > 0 ; i--)
	{
		if (S[i] != ' ')
			return S.substr(0,i + i);
	}

	return "";
}

string Trim(string S)
{
	return (TrimLeft(TrimRight(S)));
}

int main()
{
	string S = "    Tholfikar Mohammed     ";
	cout << "String       :" << S << endl;
	cout << "Trim Left: " << TrimLeft(S) << endl;
	cout << "Trim Left: " << TrimRight(S) << endl;
	cout << "Trim Left: " << Trim(S) << endl;
	system("pause>0");
}
