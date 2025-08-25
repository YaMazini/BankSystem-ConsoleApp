#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"

class clsClientListScreen : protected clsScreen
{
private:
    static void _PrintClientListTableHeader()
    {
        cout << "\n\n __________________________________________________________________________________________________________________\n\n";
                  
        cout << " | " << left << setw(15) << "Account Number";
        cout << " | " << left << setw(25) << "Client Name";
        cout << " | " << left << setw(12) << "Phone";
        cout << " | " << left << setw(28) << "Email";
        cout << " | " << left << setw(10) << "Pin Code";
        cout << " | " << left << setw(12) << "Balance" << endl;
                  
        cout << " __________________________________________________________________________________________________________________\n\n";
    }              

    static void _PrintClientRecord(clsBankClient& Client)
    {
        cout << " | " << left << setw(15) << Client.AccountNumber();
        cout << " | " << left << setw(25) << Client.FullName();
        cout << " | " << left << setw(12) << Client.Phone;
        cout << " | " << left << setw(28) << Client.Email;
        cout << " | " << left << setw(10) << Client.PinCode;
        cout << " | " << left << setw(12) << Client.AccountBalance << endl;
    }


public :
	static void ShowClientsListScreen()
	{
        if (!_HasPermission(clsUser::enPermissions::ShowClientList_p))
        {
            return;
        }

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t  Client List Screen";
        string SubTitle = "\t\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        if (vClients.size() > 0)
        {
            _PrintClientListTableHeader();

            for (clsBankClient& Client : vClients)
            {
                _PrintClientRecord(Client);
            }

            cout << " __________________________________________________________________________________________________________________\n\n";
        }

        else
        {
            cout << "\n\n\t\t\t\t      |-: No Client Available In the System :-| \n";
        }
	}
};

