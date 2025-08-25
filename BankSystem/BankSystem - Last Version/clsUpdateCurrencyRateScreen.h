#pragma once
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:

	static clsCurrency _FindCurrencyByCode()
	{
		cout << "\n\nPlease Enter Currency Code: ";
		string Code = clsInputValidate<>::ReadString();

		while (!clsCurrency::IsCurrencyExistsByCode(Code))
		{
			cout << "\nCurrency Not Found! Choose another one: ";
			Code = clsInputValidate<>::ReadString();
		}

		return clsCurrency::FindByCode(Code);
	}

	static void _UpdateCurrencyRate(clsCurrency &Currency)
	{
		cout << "\nUpdate Currency Rate: \n";
		cout << "________________________________\n";

		double Rate = 0;
		cout << "\nEnter New Rate: ";
		Rate = clsInputValidate<double>::ReadPositiveNumber();

		Currency.Rate = Rate;
		cout << "\nCurrency Rate Updated Successfully :-)\n";
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

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("    Update Currency Rate Screen");
		
		clsCurrency Currency = _FindCurrencyByCode();
		_PrintCurrencyCard(Currency);

		char Answer = 'N';
		cout << "\nAre you sure you want to update this rate of this Currency? Y/N? ";
		Answer = clsInputValidate<>::ReadChar();

		if (toupper(Answer) == 'Y')
		{
			_UpdateCurrencyRate(Currency);
			_PrintCurrencyCard(Currency);
		}

		else
		{
			cout << "\nUpdate Cancelled!\n";
		}
	}
};

