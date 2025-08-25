#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"


class clsTotalBalancesScreen : protected clsScreen
{
private:

    static void _PrintClientBalancesTableHeader()
    {
        cout << "\n\n\t\t___________________________________________________________________________________\n\n";
                
        cout << "\t\t| " << left << setw(20) << "Account Number";
        cout << "\t\t| " << left << setw(25) << "Client Name";
        cout << "\t\t| " << left << setw(15) << "Balance" << endl;
             
        cout << "\t\t___________________________________________________________________________________\n\n";
    }

    static void _PrintClientRecordBalanceLine(clsBankClient& Client)
    {
        cout << "\t\t| " << left << setw(20) << Client.AccountNumber();
        cout << "\t\t| " << left << setw(25) << Client.FullName();
        cout << "\t\t| " << left << setw(15) << Client.AccountBalance << endl;
    }

public: 

    static void ShowTotalBalancesScreen()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t Balances List Screen";
        string Subtitle = "\t\t   (" + to_string(vClients.size()) + ") Client(s). ";

        _DrawScreenHeader(Title, Subtitle);

        if (vClients.size() > 0)
        {
            double TotalBalances = clsBankClient::GetTotalBalances();

            _PrintClientBalancesTableHeader();

            for (clsBankClient Client : vClients)
            {
                _PrintClientRecordBalanceLine(Client);
            }

            cout << "\t\t___________________________________________________________________________________\n\n";
            cout << "\n\t\t\t\t\t\tTotal Balances: " << TotalBalances << endl;
            cout << "\n\t\t\t\t  ( " << clsUtil::NumberToText((int)TotalBalances) << ")" << endl;
        }

        else
        {
            cout << "\n\n\t\t\t\t      |-: No Client Available In the System :-| \n";
        }
    }
};

