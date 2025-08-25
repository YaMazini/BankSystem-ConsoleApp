#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"

class clsWithdrawScreen : protected clsScreen
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

	static double _ReadWithdrawAmount(double AccountBalance)
	{
		cout << "\nPlease enter Withdraw Amount: ";
		double WithdrawAmount = clsInputValidate<double>::ReadPositiveNumber();

		while (WithdrawAmount > AccountBalance)
		{
			cout << "\nThe Withdraw Amount is greater than the Account Balance. \n";
			cout << "\nPlease enter Withdraw Amount: ";
			WithdrawAmount = clsInputValidate<double>::ReadPositiveNumber();
		}

		return WithdrawAmount;
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

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t   Withdraw Screen");

		clsBankClient Client = _FindClient();
		_PrintClient(Client);

		double WithdrawAmount = _ReadWithdrawAmount(Client.AccountBalance);

		char Answer = 'N';
		cout << "\nAre you sure you want to perform this transaction? Y/N? ";
		Answer = clsInputValidate<>::ReadChar();

		if (toupper(Answer) == 'Y')
		{
			Client.Withdraw(WithdrawAmount);
			cout << "\nAmount Withdrawed Successfully. \n";
			cout << "\nNew Balance is: " << Client.AccountBalance << endl;
		}
		else
		{
			cout << "\nWithdraw operation was Cancelled. \n";
		}
	}
};