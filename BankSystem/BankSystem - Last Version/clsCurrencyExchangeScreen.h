#pragma once
#include "clsInputValidate.h"
#include "clsScreen.h"

#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen : protected clsScreen
{
private:

	enum enCurrencyExchangeOption
	{
		ListCurrencies_Option = 1,
		FindCurrency_Option = 2,
		UpdateRate_Option = 3,
		CurrencyCalculator_Option = 4,
		MainMenu = 5,
	};

	static void _DrawCurrencyExchangeMenuScreen()
	{
		cout << setw(37) << left << "\t" << "\n\t\t\t\t      ==========================================\n";
		cout << setw(37) << left << "\t" << "\tCurrency Exchange Menu \n";
		cout << setw(37) << left << "" << " ==========================================\n";

		cout << setw(37) << left << "" << "\t    [1] List Currencies." << endl;
		cout << setw(37) << left << "" << "\t    [2] Find Currency." << endl;
		cout << setw(37) << left << "" << "\t    [3] Update Rate." << endl;
		cout << setw(37) << left << "" << "\t    [4] Currency Calculator." << endl;
		cout << setw(37) << left << "" << "\t    [5] Main Menu." << endl;

		cout << setw(37) << left << "" << " ==========================================\n";
	}

	static short _ReadCurrencyExchangeMenuOption()
	{
		short Option = 0;
		Option = clsInputValidate<>::ReadNumberBetween(1, 5);
		return Option;
	}

	static void _GoBackToCurrencyExchangeMenuScreen()
	{
		cout << "\n\n\t Press any key to go back to Currency Exchange Menu...";
		system("pause > 0");
		ShowCurrencyExchangeMenuScreen();
	}


	static void _ShowListCurrenciesScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}


	static void _PerformCurrencyExchangeOption(enCurrencyExchangeOption CurrencyExchangeOption)
	{
		switch (CurrencyExchangeOption)
		{
		case clsCurrencyExchangeScreen::ListCurrencies_Option:

			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenuScreen();
			break;

		case clsCurrencyExchangeScreen::FindCurrency_Option:

			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenuScreen();
			break;

		case clsCurrencyExchangeScreen::UpdateRate_Option:

			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenuScreen();
			break;

		case clsCurrencyExchangeScreen::CurrencyCalculator_Option:

			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenuScreen();
			break;

		case clsCurrencyExchangeScreen::MainMenu:
			//do nothing here the main menu will handle it.
			break;

		default:
			_GoBackToCurrencyExchangeMenuScreen();
			break;
		}
	}


public:

	static void ShowCurrencyExchangeMenuScreen()
	{
		if (!_HasPermission(clsUser::enPermissions::CurrencyExchange_p))
		{
			return;
		}

		system("cls");

		_DrawScreenHeader("   Currency Exchange Main Screen");
		_DrawCurrencyExchangeMenuScreen();

		cout << setw(37) << left << "" << "  Choose what do you want to do [1 to 5]: ";
		_PerformCurrencyExchangeOption((enCurrencyExchangeOption)_ReadCurrencyExchangeMenuOption());
	}
};

