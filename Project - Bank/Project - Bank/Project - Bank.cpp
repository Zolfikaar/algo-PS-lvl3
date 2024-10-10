#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;
const string ClientsFileName = "Clients.txt";

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

// function decleration

void BackToMainMenu();
void HandleUserChoice(short userChoice);
void HandleTransactions(short userChoice);

/***********************************************************************/
/*****************  Show Client List Functions  ************************/
/***********************************************************************/
vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable

	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}

	return vString;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData;
	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]); // cast string to double
	return Client;
}

void PrintClientRecord(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(20) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(vector<sClient> vClients)
{
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "________________________________________\n"
			 << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "________________________________________\n"
			 << endl;

	for (sClient Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}

	cout << "\n_______________________________________________________";
	cout << "________________________________________\n"
			 << endl;
}

vector<sClient> LoadCleintsDataFromFile(string FileName = ClientsFileName)
{
	vector<sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in); // read Mode
	if (MyFile.is_open())
	{
		string Line;
		sClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}

/***********************************************************************/
/*******************  Add New Client Functions  ************************/
/***********************************************************************/

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

sClient ReadNewClient()
{
	sClient Client;

	cout << "Enter Account Number: ";
	// using std::ws to extract all white spaces characters from the buffer of the cin function.
	getline(cin >> ws, Client.AccountNumber);

	cout << "Enter PinCode: ";
	getline(cin, Client.PinCode);

	cout << "Enter Client Name: ";
	getline(cin, Client.Name);

	cout << "Enter Client Phone Number: ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance: ";
	cin >> Client.AccountBalance;

	return Client;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;

		MyFile.close();
	}
}

void AddNewClient()
{
	sClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddClients()
{
	char AddMore = 'Y';

	do
	{
		system("cls");
		cout << "Adding New Client:\n\n";

		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more client? [Y, N]: ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}

/***********************************************************************/
/********************  Delete Client Functions  ************************/
/***********************************************************************/

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

/***********************************************************************/
/********************  Update Client Functions  ************************/
/***********************************************************************/

sClient ChangeClientRecord(string AccountNumber)
{
	sClient Client;
	Client.AccountNumber = AccountNumber;
	cout << "\n\nEnter PinCode? ";
	getline(cin >> ws, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;
	return Client;
}

vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); // overwrite
	string DataLine;
	if (MyFile.is_open())
	{
		for (sClient C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				// we only write records that are not marked for delete.
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vClients;
}

void UpdateClientByAccountNumber()
{
	vector<sClient> vClients = LoadCleintsDataFromFile();
	string AccountNumber = ReadAccountNumber();
	sClient Client;
	char Answer = 'n';
	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
		cout << "\n\nAre you sure you want update this client? y/n? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			for (sClient &C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}
			SaveCleintsDataToFile(ClientsFileName, vClients);
			cout << "\n\nClient Updated Successfully.";
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		// return false;
	}
}

/***********************************************************************/
/********************  Find Client Functions  **************************/
/***********************************************************************/

bool FindClient(string AccountNumber, sClient &Client)
{
	vector<sClient> vClients = LoadCleintsDataFromFile();
	for (sClient C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

void FindClientByAccountNumber()
{
	sClient Client;
	string AccountNumber = ReadAccountNumber();
	if (FindClient(AccountNumber, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") does not exist!";
	}
}

/***********************************************************************/
/******************  Transactions Menu Functions  **********************/
/***********************************************************************/

sClient FindClientToUpdateBalance(string AccountNumber)
{
	vector<sClient> vClients = LoadCleintsDataFromFile();
	for (sClient C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			return C;
		}
	}
}

void MakeDeposit()
{
	cout << "------------------------------------------\n";
	cout << "\t Deposit Screen \n";
	cout << "------------------------------------------\n";

	// Load all clients from the file
	vector<sClient> vClients = LoadCleintsDataFromFile();
	string AccountNumber = ReadAccountNumber();
	sClient Client;

	// Check if the client exists
	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		// Get the deposit amount from the user
		double DepositeAmount;
		cout << "\n\nPlease enter deposit amount: ";
		cin >> DepositeAmount;

		// Confirm the transaction
		char ConfirmTransaction;
		cout << "\nAre you sure you want to perform this transaction? (y/n): ";
		cin >> ConfirmTransaction;

		// If the user confirms, update the balance and save changes
		if (ConfirmTransaction == 'y' || ConfirmTransaction == 'Y')
		{
			// Update the client's account balance
			Client.AccountBalance += DepositeAmount;

			// Update the client record in the vector
			for (sClient &C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C.AccountBalance = Client.AccountBalance; // Save the updated balance
					break;
				}
			}

			// Save the updated clients list back to the file
			SaveCleintsDataToFile(ClientsFileName, vClients);
			cout << "\nTransaction completed successfully. The new balance is: " << Client.AccountBalance << endl;
			cout << "\nPress any key to return to Transaction Menu Screen...\n";
			system("pause>0");
		}
		else
		{
			cout << "\nTransaction canceled.\n";
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") does not exist!" << endl;
	}
}

void MakeWithdraw()
{
	cout << "------------------------------------------\n";
	cout << "\t Withdraw Screen \n";
	cout << "------------------------------------------\n";

	// Load all clients from the file
	vector<sClient> vClients = LoadCleintsDataFromFile();
	string AccountNumber = ReadAccountNumber();
	sClient Client;

	// Check if the client exists
	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		// Get the deposit amount from the user
		double WithdrawAmount;
		cout << "\n\nPlease enter withdraw amount: ";
		cin >> WithdrawAmount;

		// Confirm the transaction
		char ConfirmTransaction;
		cout << "\nAre you sure you want to perform this transaction? (y/n): ";
		cin >> ConfirmTransaction;

		// If the user confirms, update the balance and save changes
		if (ConfirmTransaction == 'y' || ConfirmTransaction == 'Y')
		{
			if (WithdrawAmount <= Client.AccountBalance)
			{

				// Update the client's account balance
				Client.AccountBalance -= WithdrawAmount;

				// Update the client record in the vector
				for (sClient &C : vClients)
				{
					if (C.AccountNumber == AccountNumber)
					{
						C.AccountBalance = Client.AccountBalance; // Save the updated balance
						break;
					}
				}

				// Save the updated clients list back to the file
				SaveCleintsDataToFile(ClientsFileName, vClients);
				cout << "\nTransaction completed successfully. The new balance is: " << Client.AccountBalance << endl;
				cout << "\nPress any key to return to Transaction Menu Screen...\n";
				system("pause>0");
			}
			else
			{
				cout << "\n\nAmount exeeds the balance, you can withdraw up to: " << Client.AccountBalance << endl;
				cout << "\n\nPress any key to return...";
				system("pause>0");
				system("cls");
				MakeWithdraw();
			}
		}
		else
		{
			cout << "\nTransaction canceled.\n";
			cout << "\n\nPress any key to return...";
			system("pause>0");
			system("cls");
			MakeWithdraw();
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") does not exist!" << endl;
	}
}

void ShowTotalBalance()
{
	cout << "------------------------------------------\n";
	cout << "\t Total Balance Screen \n";
	cout << "------------------------------------------\n";

	double TotalBalance = 0;

	vector<sClient> vClients = LoadCleintsDataFromFile();

	for (sClient &C : vClients)
	{
		TotalBalance += C.AccountBalance;
	}

	PrintAllClientsData(vClients);

	cout << "The Total Balance is: " << TotalBalance << endl;
}

void ShowTransactionsMenu()
{
	system("cls");
	cout << "------------------------------------------\n";
	cout << "\t Transactions Menu Screen \n";
	cout << "------------------------------------------\n";

	cout << "[1] Deposit.\n";
	cout << "[2] Withdraw.\n";
	cout << "[3] Total Balance.\n";
	cout << "[4] Main Menu.\n";

	cout << "------------------------------------------\n";

	short userChoice;
	cout << "Choose what to do? [1 to 4]: ";
	cin >> userChoice;
	HandleTransactions(userChoice);
}

void HandleTransactions(short userChoice)
{
	system("cls");
	switch (userChoice)
	{
	case 1:
		MakeDeposit();
		ShowTransactionsMenu();
		break;

	case 2:
		MakeWithdraw();
		ShowTransactionsMenu();
		break;

	case 3:
		ShowTotalBalance();
		cout << "\n\nPress any key to return to main menu...";
		system("pause>0");
		ShowTransactionsMenu();
		break;

	case 4:
		BackToMainMenu();
		break;

	default:
		cout << "Invalid option selected!" << endl;
		ShowTransactionsMenu();
		break;
	}
}

/***********************************************************************/
/***********************  General Functions  ***************************/
/***********************************************************************/
void ShowEndScreen()
{
	cout << "\n------------------------------------\n";
	cout << "\nProgram Ends.\n";
	cout << "\n------------------------------------\n";
}

void HandleUserChoice(short userChoice)
{
	system("cls");
	switch (userChoice)
	{
	case 1:
		PrintAllClientsData(LoadCleintsDataFromFile());
		cout << "\n\nPress any key to return to main menu...";
		system("pause>0");
		BackToMainMenu();
		break;

	case 2:
		AddClients();
		cout << "\n\nPress any key to return to main menu...";
		system("pause>0");
		BackToMainMenu();
		break;

	case 3:
		DeleteClientByAccountNumber();
		cout << "\n\nPress any key to return to main menu...";
		system("pause>0");
		BackToMainMenu();
		break;

	case 4:
		UpdateClientByAccountNumber();
		cout << "\n\nPress any key to return to main menu...";
		system("pause>0");
		BackToMainMenu();
		break;

	case 5:
		FindClientByAccountNumber();
		cout << "\n\nPress any key to return to main menu...";
		system("pause>0");
		BackToMainMenu();
		break;

	case 6:
		ShowTransactionsMenu();
		BackToMainMenu();
		break;

	case 7:
		ShowEndScreen();
		break;

	default:
		cout << "Invalid option selected!" << endl;
		BackToMainMenu();
		break;
	}
}

void ShowMainMenu()
{
	cout << "------------------------------------------\n";
	cout << "\t Main Menu Screen \n";
	cout << "------------------------------------------\n";

	cout << "[1] Show Client List.\n";
	cout << "[2] Add New Client.\n";
	cout << "[3] Delete Client.\n";
	cout << "[4] Update Client Info.\n";
	cout << "[5] Find Client.\n";
	cout << "[6] Transactions.\n";
	cout << "[7] Exit.\n";
	cout << "------------------------------------------\n";

	short userChoice;
	cout << "Choose what to do? [1 to 7]: ";
	cin >> userChoice;
	HandleUserChoice(userChoice);
}

void BackToMainMenu()
{
	system("cls");
	ShowMainMenu();
}

int main()
{
	ShowMainMenu();
	return 0;
}