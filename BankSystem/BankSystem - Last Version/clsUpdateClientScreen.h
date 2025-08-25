#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"


class clsUpdateClientScreen : protected clsScreen
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

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate<>::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate<>::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate<>::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate<>::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate<>::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate<double>::ReadPositiveNumber();
    }

    static void _UpdateClient(clsBankClient::enSaveResults SaveResult)
    {
        switch (SaveResult)
        {
        case clsBankClient::svSucceeded:
            cout << "\nAccount Updated Successfully :-) \n";

            break;

        case clsBankClient::svFailedEmptyObject:
            cout << "\nError account was not saved because its Empty :-( \n";
            break;

        default:
            cout << "\nUnexpected Error\n";
            break;
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

    static void UpdateClientScreen()
    {
        if (!_HasPermission(clsUser::enPermissions::UpdateClientInfo_p))
        {
            return;
        }

        _DrawScreenHeader("\t Update Client Screen");

        clsBankClient Client = _FindClient();
        _PrintClient(Client);

        cout << "\nUpdate Client Info: " << endl;
        cout << "-------------------------------\n";
        _ReadClientInfo(Client);

        clsBankClient::enSaveResults SaveResult = Client.Save();

        _UpdateClient(SaveResult);
        _PrintClient(Client);
    }
};

