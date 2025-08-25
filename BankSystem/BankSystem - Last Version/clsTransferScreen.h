#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

#include "Global.h"

class clsTransferScreen : protected clsScreen
{
private:

	static clsBankClient _ReadClient(string Msg)
	{
		cout << "\n" << Msg;

		string AccountNumber = clsInputValidate<>::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is Not Found, choose another one: ";
			AccountNumber = clsInputValidate<>::ReadString();
		}

		return clsBankClient::Find(AccountNumber);
	}

	static double _ReadAmount(double SourceClientBalance)
	{
		double TransferAmount = 0;
		cout << "\nEnter Transfer Amount: ";
		TransferAmount = clsInputValidate<double>::ReadNumberBetween(0, SourceClientBalance,
			"\nAmount Exceeds the available Balance, Enter another Amount: ");

		return TransferAmount;
	}

	static void _TransferAmount(clsBankClient& SourceClient, clsBankClient& DestinationClient, double TransferAmount)
	{
		SourceClient.Transfer(DestinationClient, TransferAmount, CurrentUser.UserName);

		cout << "\nTransfer Done Successfully :-) \n";
		_PrintClientCard(SourceClient);
		_PrintClientCard(DestinationClient);
	}

	static void _PrintClientCard(clsBankClient& Client)
	{
		cout << "\nClient Card: ";
		cout << "\n____________________________________\n";

		cout << "\nFull Name  : " << Client.FullName();
		cout << "\nAcc Number : " << Client.AccountNumber();
		cout << "\nBalance    : " << Client.AccountBalance;

		cout << "\n____________________________________\n";
	}


public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t    Transfer Screen");

		clsBankClient SourceClient = _ReadClient("\nPlease enter Account Number to Transfer From: ");
		_PrintClientCard(SourceClient);

		clsBankClient DestinationClient = _ReadClient("\nPlease enter Account Number to Transfer To  : ");
		_PrintClientCard(DestinationClient);

		double TransferAmount = _ReadAmount(SourceClient.AccountBalance);

		char Answer = 'N';
		cout << "\nAre you sure you want to perform this operation? Y/N? ";
		Answer = clsInputValidate<>::ReadChar();


		if (toupper(Answer) == 'Y')
		{
			_TransferAmount(SourceClient, DestinationClient, TransferAmount);
		}
	
		else
		{
			cout << "\nTransfer Operation was Cancelled! \n";
		}
	}
};

