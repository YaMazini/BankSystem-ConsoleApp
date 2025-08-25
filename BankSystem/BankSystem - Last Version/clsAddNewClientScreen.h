#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"


class clsAddNewClientScreen : protected clsScreen
{
private:

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

    static clsBankClient _GetNewClientObject()
    {
        cout << "\nPlease Enter Account Number: ";
        string AccountNumber = clsInputValidate<>::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is Already Used, choose another one: ";
            AccountNumber = clsInputValidate<>::ReadString();
        }

        return clsBankClient::GetAddNewClientObject(AccountNumber);
    }

    static void _SaveClient(clsBankClient::enSaveResults SaveResult)
    {
        switch (SaveResult)
        {
        case clsBankClient::svSucceeded:
            cout << "\nAccount Added Successfully :-) \n";
            break;

        case clsBankClient::svFailedEmptyObject:
            cout << "\nError account was not saved because its Empty :-( \n";
            break;

        case clsBankClient::svFailedAccNumExists:
            cout << "\nAccount Number is Already Used :-| \n";
            break;

        default:
            cout << "\nUnexpected Error \n";
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

    static void AddNewClientScreen()
    {
        if (!_HasPermission(clsUser::enPermissions::AddNewClient_p))
        {
            return;
        }

        _DrawScreenHeader("\tAdd New Client Screen");

        clsBankClient NewClient = _GetNewClientObject();
        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult = NewClient.Save();

        _SaveClient(SaveResult);
        _PrintClient(NewClient);
    }
};
