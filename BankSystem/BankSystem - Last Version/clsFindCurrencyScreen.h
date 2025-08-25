#pragma once
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:

	static clsCurrency FindCurrencyByCountry()
	{
		string Country = clsInputValidate<>::ReadString();

		if (clsCurrency::IsCurrencyExistsByCountry(Country))
		{
			cout << "\nCurrency Found :-)\n";
		}

		else
		{
			cout << "\nCurrency Not Found :-|\n";
		}

		return clsCurrency::FindByCountry(Country);
	}

	static clsCurrency FindCurrencyByCode()
	{
		string Code = clsInputValidate<>::ReadString();

		if (clsCurrency::IsCurrencyExistsByCode(Code))
		{
			cout << "\nCurrency Found :-)\n";
		}

		else
		{
			cout << "\nCurrency Not Found :-|\n";
		}

		return clsCurrency::FindByCode(Code);
	}

	static void _PrintCurrencyCard(clsCurrency& Currency)
	{
		cout << "\nCurrency Card: \n";
		cout << "_____________________________________________\n\n";
		cout << "Country   : " << Currency.Country() << endl;
		cout << "Code      : " << Currency.Code() << endl;
		cout << "Name      : " << Currency.Name() << endl;
		cout << "Rate (1$) : " << Currency.Rate << endl;
		cout << "_____________________________________________\n\n";
	}


public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen");

		short Choice = 1;
		cout << "\n\nFind By: [1]Code or [2]Country? ";
		Choice = clsInputValidate<>::ReadNumberBetween(1, 2);

		if (Choice == 1)
		{
			cout << "\nPlease Enter Currency Code: ";
			clsCurrency Currency = FindCurrencyByCode();
			if (!Currency.IsEmpty())
			{
				_PrintCurrencyCard(Currency);
			}
		}

		else
		{
			cout << "\nPlease Enter Currency Country: ";
			clsCurrency Currency = FindCurrencyByCountry();
			if (!Currency.IsEmpty())
			{
				_PrintCurrencyCard(Currency);
			}
		}
	}
};

