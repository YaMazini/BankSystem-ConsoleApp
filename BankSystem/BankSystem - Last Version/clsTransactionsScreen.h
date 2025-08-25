#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"

#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogListScreen.h"


class clsTransactionsScreen : protected clsScreen
{
private:

	enum enTransactionMenuOption
	{
		Deposit_Option = 1,
		Withdraw_Option = 2,
		Totalbalances_Option = 3,
		Transfer_Option = 4,
		TransferLog_Option = 5,
		MainMenu_Option = 6
	};

	static short _ReadTransactionsMenuOption()
	{
		short Option = 0;
		Option = clsInputValidate<>::ReadNumberBetween(1, 6);

		return Option;
	}

	static void _DrawTransactionsMenuScreen()
	{
		cout << setw(37) << left << "\t" << "\n\t\t\t\t      ==========================================\n";
		cout << setw(37) << left << "\t" << "\t   Transaction Menu \n";
		cout << setw(37) << left << "" << " ==========================================\n";

		cout << setw(37) << left << "" << "\t    [1] Deposit." << endl;
		cout << setw(37) << left << "" << "\t    [2] Withdraw." << endl;
		cout << setw(37) << left << "" << "\t    [3] Total Balances." << endl;
		cout << setw(37) << left << "" << "\t    [4] Transfer." << endl;
		cout << setw(37) << left << "" << "\t    [5] Transfer Log." << endl;
		cout << setw(37) << left << "" << "\t    [6] Main Menu." << endl;

		cout << setw(37) << left << "" << " ==========================================\n";
	}

	static void _GoBackToTransactionsMenuScreen()
	{
		cout << "\n\n\t Press any key to go back to Transactions Menu...";
		system("pause > 0");
		ShowTransactionsMenuScreen();
	}


	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}
	
	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogListScreen::ShowTransferLogListScreen();
	}


	static void _PerformTransactionsMenuOption(enTransactionMenuOption TransactionsMenuOption)
	{
		switch (TransactionsMenuOption)
		{
		case clsTransactionsScreen::enTransactionMenuOption::Deposit_Option:

			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenuScreen();
			break;
		
		case clsTransactionsScreen::enTransactionMenuOption::Withdraw_Option:

			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenuScreen();
			break;
		
		case clsTransactionsScreen::enTransactionMenuOption::Totalbalances_Option:

			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenuScreen();
			break;
		
		case clsTransactionsScreen::enTransactionMenuOption::Transfer_Option:

			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenuScreen();
			break;

		case clsTransactionsScreen::enTransactionMenuOption::TransferLog_Option:

			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenuScreen();
			break;

		case clsTransactionsScreen::enTransactionMenuOption::MainMenu_Option:
			
			//do nothing here the main screen will handle it :-)
			break;
		
		default:
			_GoBackToTransactionsMenuScreen();
			break;
		}


	}


public:

	static void ShowTransactionsMenuScreen()
	{
		system("cls");

		if (!_HasPermission(clsUser::enPermissions::Transactions_p))
		{
			return;
		}

		_DrawScreenHeader("\t  Transaction Screen");

		_DrawTransactionsMenuScreen();
		cout << setw(37) << left << "" << "  Choose what do you want to do [1 to 6]: ";

		_PerformTransactionsMenuOption((enTransactionMenuOption)_ReadTransactionsMenuOption());
	}
};

