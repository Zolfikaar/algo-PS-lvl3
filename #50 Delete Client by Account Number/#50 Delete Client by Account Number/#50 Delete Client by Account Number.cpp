#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable

	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (!sWord.empty())
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}

	if (!S1.empty())
	{
		vString.push_back(S1); // it adds last word of the string.
	}

	return vString;
}

string ReadAccountNumber()
{
	string AccNum = "";
	cout << "Please, Enter Account Number: ";
	cin >> AccNum;
	return AccNum;
}

void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nName : " << Client.Name;
	cout << "\nPhone : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData = SplitString(Line, Seperator);
	if (vClientData.size() == 5)
	{ // Ensure that we have all fields
		Client.AccountNumber = vClientData[0];
		Client.PinCode = vClientData[1];
		Client.Name = vClientData[2];
		Client.Phone = vClientData[3];
		Client.AccountBalance = stod(vClientData[4]); // cast string to double
	}
	return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

bool FindClientByAccountNumber(string AccountNumber, const vector<sClient> &vClients, sClient &Client)
{
	for (const sClient &C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

char ReadUserChoice(string msg)
{
	char choice = 'Y';
	cout << msg;
	cin >> choice;
	return choice;
}

// Function to write all clients' data back to the file
void UpdateClientsDataToFile(string FileName, const vector<sClient> &vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); // Write Mode
	if (MyFile.is_open())
	{
		for (const sClient &client : vClients)
		{
			MyFile << ConvertRecordToLine(client) << endl;
		}
		MyFile.close();
	}
	else
	{
		cout << "Error: Could not open file for writing!" << endl;
	}
}

// Function to confirm and delete a client from the vector
bool ConfirmDelete(string AccountNumber, vector<sClient> &vClients)
{
	auto it = find_if(vClients.begin(), vClients.end(), [&](const sClient &C)
										{ return C.AccountNumber == AccountNumber; });

	if (it != vClients.end())
	{
		char choice = ReadUserChoice("\nAre you sure you want to delete this client? (Y,N): ");
		if (toupper(choice) == 'Y')
		{
			vClients.erase(it); // Remove client from the vector
			return true;
		}
	}
	return false;
}

vector<sClient> LoadClientsDataFromFile(string FileName)
{
	vector<sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in); // read Mode
	if (MyFile.is_open())
	{
		string Line;
		while (getline(MyFile, Line))
		{
			sClient Client = ConvertLinetoRecord(Line);
			if (!Client.AccountNumber.empty())
			{ // Ensure valid record
				vClients.push_back(Client);
			}
		}
		MyFile.close();
	}
	else
	{
		cout << "Error: Could not open file for reading!" << endl;
	}
	return vClients;
}

void DeleteClientByAccountNumber()
{
	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName); // Load all clients
	sClient Client;
	string AccountNumber = ReadAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
		if (ConfirmDelete(AccountNumber, vClients))
		{
			UpdateClientsDataToFile(ClientsFileName, vClients); // Update the file with the new data
			cout << "\nClient Deleted Successfully!" << endl;
		}
		else
		{
			cout << "\nDeletion Canceled!" << endl;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!" << endl;
	}
}

int main()
{
	DeleteClientByAccountNumber();
	system("pause>0");
	return 0;
}