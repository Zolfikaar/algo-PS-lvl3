#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClientInfo
{
    string AccountNumber;
    string PinCode;
    string ClientName;
    string ClientPhoneNum;
    double AccountBalance;
};

string ConvertRecordToLine(sClientInfo Client, string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.ClientName + Seperator;
    stClientRecord += Client.ClientPhoneNum + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

sClientInfo ReadNewClient()
{
    sClientInfo Client;

    cout << "Enter Account Number: ";
    // using std::ws to extract all white spaces characters from the buffer of the cin function.
    getline(cin >> ws, Client.AccountNumber);

    cout << "Enter PinCode: ";
    getline(cin, Client.PinCode);

    cout << "Enter Client Name: ";
    getline(cin, Client.ClientName);

    cout << "Enter Client Phone Number: ";
    getline(cin, Client.ClientPhoneNum);

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
    sClientInfo Client;
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
        cout << "\nClient Added Successfully, do you want to add more client";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

int main()
{
    AddClients();
    system("pause>0");
    return 0;
}