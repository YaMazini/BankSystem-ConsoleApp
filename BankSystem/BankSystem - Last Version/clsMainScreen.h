#pragma once
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"

#include "Global.h"

#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"

#include "clsTransactionsScreen.h"

#include "clsCurrencyExchangeScreen.h"

#include "clsManageUsersScreen.h"

#include "clsLoginRegisterScreen.h"

#include "clsExitScreen.h"

//#include "clsLoginScreen.h"


class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenuOption
	{
		ClientList_Option = 1,
		AddNewClient_Option = 2,
		DeleteClient_Option = 3,
		UpdateClientInfo_Option = 4,
		FindClient_Option = 5,
		Transactions_Option = 6,
		CurrencyExchange_Option = 7,
		ManageUsers_Option = 8,
		LoginRegister_Option = 9,
		Logout_Option = 10,
		Exit_Option = 11
	};

	static short _ReadMainMenuOption()
	{
		short Option = 0;
		Option = clsInputValidate<short>::ReadNumberBetween(1, 11, "\nInvalid Number, Enter Again: ");
		return Option;
	}

	static void _DrawMainMenuScreen()
	{
		cout << setw(37) << left << "" << "\n\t\t\t\t     ============================================\n";
		cout << setw(37) << left << "" << "\t\t      Main Menue\n";
		cout << setw(37) << left << "" << "============================================\n";

		cout << setw(37) << left << "\t" << "[1] Show Client List." << endl;
		cout << setw(37) << left << "\t" << "[2] Add New Client." << endl;
		cout << setw(37) << left << "\t" << "[3] Delete Client." << endl;
		cout << setw(37) << left << "\t" << "[4] Update Client Info." << endl;
		cout << setw(37) << left << "\t" << "[5] Find Client." << endl;
		cout << setw(37) << left << "\t" << "[6] Transactions." << endl;
		cout << setw(37) << left << "\t" << "[7] Currency Exchange." << endl;
		cout << setw(37) << left << "\t" << "[8] Manage Users." << endl;
		cout << setw(37) << left << "\t" << "[9] Login Register." << endl;
		cout << setw(37) << left << "\t" << "[10] Logout." << endl;
		cout << setw(37) << left << "\t" << "[11] Exit." << endl;

		cout << setw(37) << left << "" << "=============================================\n";
	}

	static void _GoBackToMainMenuScreen()
	{
		cout << "\n\n\t Press any key to go back to Main Menu...";
		system("pause > 0");
		ShowMainMenu();
	}


	static void _ShowClientListScreen()
	{
		clsClientListScreen::ShowClientsListScreen();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::AddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientInfoScreen()
	{
		clsUpdateClientScreen::UpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsScreen()
	{
		clsTransactionsScreen::ShowTransactionsMenuScreen();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyExchangeScreen::ShowCurrencyExchangeMenuScreen();
	}

	static void _ShowManageUsersScreen()
	{
		clsManageUsersScreen::ShowManageUsersMenuScreen();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowLogoutScreen()
	{
		CurrentUser = clsUser::Find("", "");
		
		//clsLoginScreen::ShowLoginScreen(); //This will lead to a Circular Reference
		                                     //it happens when two or more files, classes, or modules depend on each other in a way that creates a loop.                            
					

		//It will go back to The main.
	}

	static void _ShowExitScreen()
	{
		clsExitScreen::ShowExitScreen();
	}


	static void _PerformMainMenuOption(enMainMenuOption MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case clsMainScreen::enMainMenuOption::ClientList_Option:

			system("cls");
			_ShowClientListScreen();
			_GoBackToMainMenuScreen();
			break;

		case clsMainScreen::enMainMenuOption::AddNewClient_Option:

			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenuScreen();
			break;

		case clsMainScreen::enMainMenuOption::DeleteClient_Option:

			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenuScreen();
			break;

		case clsMainScreen::enMainMenuOption::UpdateClientInfo_Option:
			
			system("cls");
			_ShowUpdateClientInfoScreen();
			_GoBackToMainMenuScreen();
			break;

		case clsMainScreen::enMainMenuOption::FindClient_Option:
			
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenuScreen();
			break;

		case clsMainScreen::enMainMenuOption::Transactions_Option:
			
			system("cls");
			_ShowTransactionsScreen();
			_GoBackToMainMenuScreen();
			break;

		case clsMainScreen::enMainMenuOption::CurrencyExchange_Option:

			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenuScreen();
			break;

		case clsMainScreen::enMainMenuOption::ManageUsers_Option:

			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenuScreen();
			break;

		case clsMainScreen::enMainMenuOption::LoginRegister_Option:

			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenuScreen();
			break;

		case clsMainScreen::enMainMenuOption::Logout_Option:

			system("cls");
			_ShowLogoutScreen();
			break;

		case clsMainScreen::enMainMenuOption::Exit_Option:
			
			system("cls");
			_ShowExitScreen();
			exit(0);
			break;

		default:

			system("cls");
			_GoBackToMainMenuScreen();
			break;
		}
	}


public:

	static void ShowMainMenu()
	{
		system("cls");

		_DrawScreenHeader("\t     Main Screen");
		_DrawMainMenuScreen();

		cout << setw(37) << left << "" << "  Choose what do you want to do [1 to 11]: ";
		_PerformMainMenuOption((enMainMenuOption)_ReadMainMenuOption());
	}
};

