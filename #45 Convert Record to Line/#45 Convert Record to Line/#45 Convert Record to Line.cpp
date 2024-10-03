#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct sClientInfo
{
    string AccountNumber;
    string PinCode;
    string ClientName;
    string ClientPhoneNum;
    double AccountBalance;
};


sClientInfo ReadNewClient()
{
    sClientInfo Client;

    cout << "Please, Enter Account Number: ";
    getline(cin,Client.AccountNumber);

    cout << "Please, Enter PinCode: ";
    getline(cin,Client.PinCode);

    cout << "Please, Enter Client Name: ";
    getline(cin,Client.ClientName);

    cout << "Please, Enter Client Phone Number: ";
    getline(cin,Client.ClientPhoneNum);

    cout << "Please, Enter Account Balance: ";
    cin >> Client.AccountBalance;

    cout << "Client Record for saveing is:";
    return Client;
    
}

string ConvertRecordToLine(sClientInfo Client, string Seperator = "//")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.ClientName + Seperator;
    stClientRecord += Client.ClientPhoneNum + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

int main()
{
    cout << "\nPlease, Enter Client Data: \n\n";
    sClientInfo Client;
    Client = ReadNewClient();

    cout << "\n\nClient Record for saveing is: \n";
    cout << ConvertRecordToLine(Client, "#//#");
    system("pause>0");
}