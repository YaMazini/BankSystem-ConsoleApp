#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"



class clsDepositScreen : protected clsScreen
{
private:

	static clsBankClient _FindClient()
	{
		cout << "\nPlease enter Account Number: ";
		string AccountNumber = clsInputValidate<>::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist. \n";
			cout << "\nPlease enter Account Number: ";
			AccountNumber = clsInputValidate<>::ReadString();
		}

		return clsBankClient::Find(AccountNumber);
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

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t    Deposit Screen");

		clsBankClient Client = _FindClient();
		_PrintClient(Client);

		cout << "\nPlease enter Deposit Amount: ";
		double DepositAmount = clsInputValidate<double>::ReadPositiveNumber();

		char Answer = 'N';
		cout << "\nAre you sure you want to perform this transaction? Y/N? ";
		Answer = clsInputValidate<>::ReadChar();

		if (toupper(Answer) == 'Y')
		{
			Client.Deposit(DepositAmount);

			cout << "\nAmount Deposited Successfully. \n";
			cout << "\nNew Balance is: " << Client.AccountBalance << endl;
		}
		else
		{
			cout << "\nDeposit operation was Cancelled. \n";
		}
	}
};
