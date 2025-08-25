#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"

class clsFindClientScreen : protected clsScreen
{
private:

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

	static void ShowFindClientScreen()
	{
        if (!_HasPermission(clsUser::enPermissions::FindClient_p))
        {
            return;
        }


		_DrawScreenHeader("\t  Find Client Screen");

		cout << "\nPlease Enter Account Number: ";
		string AccountNumber = clsInputValidate<>::ReadString();

        clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
            cout << "\nClient Found :-) \n";
		}

        else
        {
            cout << "\nClient is Not Found :-| \n";
        }

        _PrintClient(Client);
	}
};
