#pragma once
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static clsCurrency _FindCurrencyByCode(string Title)
	{
		cout << "\n" << Title;
		string Code = clsInputValidate<>::ReadString();

		while (!clsCurrency::IsCurrencyExistsByCode(Code))
		{
			cout << "\nCurrency Not Found! Choose another one: ";
			Code = clsInputValidate<>::ReadString();
		}

		return clsCurrency::FindByCode(Code);
	}

	static double _ReadExchangeAmount()
	{
		double ExchangeAmount = 0;
		cout << "\nEnter Amount to Exchange: ";
		ExchangeAmount = clsInputValidate<double>::ReadPositiveNumber();

		return ExchangeAmount;
	}

	static void _ShowCalculationResult(clsCurrency Currency1, clsCurrency Currency2, double ExchangeAmount)
	{
		_PrintCurrencyCard(Currency1, "\n\nConvert From: \n");

		double USDAmount = Currency1.ConvertFromCurrencyToUSD(ExchangeAmount);
		cout << ExchangeAmount << " " << Currency1.Code() << " = "
			<< USDAmount << " USD \n\n";

		if (Currency2.Code() != "USD")
		{
			double Currency2Amount = Currency2.ConvertFromUSDToCurrency(USDAmount);

			_PrintCurrencyCard(Currency2, "\nConvert To: \n");

			cout << ExchangeAmount << " " << Currency1.Code() << " = "
				<< Currency2Amount << Currency2.Code() << "\n\n";
		}
	}
	
	static void _PrintCurrencyCard(clsCurrency& Currency, string Title)
	{
		cout << Title;
		cout << "_____________________________________________\n\n";

		cout << "Country   : " << Currency.Country() << endl;
		cout << "Code      : " << Currency.Code() << endl;
		cout << "Name      : " << Currency.Name() << endl;
		cout << "Rate (1$) : " << Currency.Rate << endl;

		cout << "_____________________________________________\n\n";
	}


public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Answer = 'N';

		do
		{
			system("cls");

		    _DrawScreenHeader("     Currency Calculator Screen");
		    
		    clsCurrency Currency1 = _FindCurrencyByCode("\nPlease Enter Currency1 Code: ");
		    clsCurrency Currency2 = _FindCurrencyByCode("Please Enter Currency2 Code: ");
		    
			double ExchangeAmount = _ReadExchangeAmount();

			_ShowCalculationResult(Currency1, Currency2, ExchangeAmount);
		    
			cout << "\nDo you want to perform another Calculation? Y/N? ";
			Answer = clsInputValidate<>::ReadChar();

		} while (toupper(Answer) == 'Y');
	}
};

