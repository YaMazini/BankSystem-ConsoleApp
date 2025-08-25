#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"


class clsDeleteClientScreen : protected clsScreen
{
private:
   
    static clsBankClient _FindClient()
    {
        cout << "\nPlease Enter Account Number: ";
        string AccountNumber = clsInputValidate<>::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is Not Found, choose another one: ";
            AccountNumber = clsInputValidate<>::ReadString();
        }

        return clsBankClient::Find(AccountNumber);
    }

    static void _DeleteClient(clsBankClient& Client)
    {
        if (Client.Delete())
        {
            cout << "\nClient Deleted Successfully :-) \n";

        }

        else
        {
            cout << "\nError Client Was not Deleted :-( \n";
        }
    }

    static void _PrintClient(clsBankClient& Client)
    {
        cout << "\nClient Card:";
        cout << "\n_______________________________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc Number  : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n_______________________________________\n";
    }



public:

    static void ShowDeleteClientScreen()
    {
        if (!_HasPermission(clsUser::enPermissions::DeleteClient_p))
        {
            return;
        }

        _DrawScreenHeader("\t Delete Client Screen");

        clsBankClient Client = _FindClient();
        _PrintClient(Client);

        char Answer = 'N';
        cout << "\nAre you sure you want to delete this client? Y/N? ";
        Answer = clsInputValidate<>::ReadChar();

        if (toupper(Answer) == 'Y')
        {
            _DeleteClient(Client);
            _PrintClient(Client);
        }

        else
        {
            cout << "\nDeletion Cancelled!";
        }

    }
};

