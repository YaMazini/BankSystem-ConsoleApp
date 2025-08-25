#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"

#include <iomanip>


class clsCurrenciesListScreen : protected clsScreen
{
private:

	static void _DrawCurrenciesListTableHeader()
	{
		cout << "\n\n      _____________________________________________________________________________________________________________\n\n";
					  
		cout << "      | " << left << setw(26) << "Country";
		cout << "      | " << left << setw(2) << "Code";
		cout << "     | " << left << setw(40) << "Name";
		cout << "      | " << left << setw(14) << "Rate - (1$)" << endl;
				       
		cout << "      _____________________________________________________________________________________________________________\n\n";

	}

	static void _PrintCurrencyRecord(clsCurrency& Currency)
	{
		cout << "      | " << left << setw(26) << Currency.Country();
		cout << "      | " << left << setw(2) << Currency.Code();
		cout << "      | " << left << setw(40) << Currency.Name();
		cout << "      | " << left << setw(14) << Currency.Rate << endl;
	}


public:

	static void ShowCurrenciesListScreen()
	{
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\tCurrencies List Screen";
		string SubTitle = "\t\t   (" + to_string(vCurrencies.size()) + ") Currency.";

		_DrawScreenHeader(Title, SubTitle);

		if (vCurrencies.size() > 0)
		{
			_DrawCurrenciesListTableHeader();

			for (clsCurrency& Currency : vCurrencies)
			{
				_PrintCurrencyRecord(Currency);
			}

			cout << "      _____________________________________________________________________________________________________________\n\n";
		}

		else
		{
			cout << "\n\n\t\t\t\t   |-: No Currency is Available In the System :-| \n";
		}
	}
};

