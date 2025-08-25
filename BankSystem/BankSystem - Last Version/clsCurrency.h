#pragma once
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsUtil.h"
#include <fstream>


class clsCurrency
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };

	enMode _Mode = enMode::EmptyMode;

	string _Country;
	string _Code;
	string _Name;
	double _Rate = 0;


	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	static clsCurrency _ConvertCurrencyLineToCurrencyObject(string Line, string Separator = "#//#")
	{
		vector <string> vCurrencyInfo = clsString::Split(Line, Separator);
		
		return clsCurrency(enMode::UpdateMode, vCurrencyInfo[0], vCurrencyInfo[1], vCurrencyInfo[2], stod(vCurrencyInfo[3]));
    }

	static string _ConvertCurrencyObjectToCurrencyLine(clsCurrency Currency, string Separator = "#//#")
	{
		string StrCurrency = "";

		StrCurrency += Currency.Country() + Separator;
		StrCurrency += Currency.Code() + Separator;
		StrCurrency += Currency.Name() + Separator;
		StrCurrency += to_string(Currency.Rate);

		return StrCurrency;
	}

	static vector<clsCurrency> _LoadDataFromFileToVector()
	{
		vector<clsCurrency> vCurrencies;
		fstream CurrencyFile;

		CurrencyFile.open("Currencies.txt", ios::in);

		if (CurrencyFile.is_open())
		{
			string Line;
			clsCurrency Currency = _GetEmptyCurrencyObject();

			while (getline(CurrencyFile, Line))
			{
				Currency = _ConvertCurrencyLineToCurrencyObject(Line);
				vCurrencies.push_back(Currency);
			}

			CurrencyFile.close();
		}

		return vCurrencies;
	}

	static void _SaveCurrenciesDataInFile(vector<clsCurrency> &vCurrencies)
	{
		fstream CurrenciesFile;
		CurrenciesFile.open("Currencies.txt", ios::out);

		if (CurrenciesFile.is_open())
		{
			for (clsCurrency& Currency : vCurrencies)
			{
				CurrenciesFile << _ConvertCurrencyObjectToCurrencyLine(Currency) << endl;
			}

			CurrenciesFile.close();
		}

	}

	void _Update()
	{
		vector <clsCurrency> vCurrencies = _LoadDataFromFileToVector();
		
		for (clsCurrency& Currency : vCurrencies)
		{
			if (Currency.Country() == this->Country())
			{
				Currency = *this;
				break;
			}
		}

		_SaveCurrenciesDataInFile(vCurrencies);
	}


public:

	clsCurrency(enMode Mode, string Country, string Code, string Name, double Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_Code = Code;
		_Name = Name;
		_Rate = Rate;
	}


	void SetMode(enMode Mode)
	{
		_Mode = Mode;
	}

	enMode GetMode()
	{
		return _Mode;
	}
	__declspec(property(get = GetMode, put = SetMode)) enMode Mode;

	string Country()
	{
		return _Country;
	}

	string Code()
	{
		return _Code;
	}

	string Name()
	{
		return _Name;
	}

	void UpdateRate(double Rate)
	{
		_Rate = Rate;
		_Update();
	}

	double GetRate()
	{
		return _Rate;
	}
	__declspec(property(get = GetRate, put = UpdateRate)) double Rate;


	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadDataFromFileToVector();
	}

	static clsCurrency FindByCountry(string Country)
	{
		vector <clsCurrency> vCurrencies = _LoadDataFromFileToVector();

		for (clsCurrency& Currency : vCurrencies)
		{
			if (clsString::ToLower(Currency.Country()) == clsString::ToLower(Country))
			{
				return Currency;
			}
		}
	
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCode(string Code)
	{
		vector <clsCurrency> vCurrencies = _LoadDataFromFileToVector();

		for (clsCurrency& Currency : vCurrencies)
		{
			if (clsString::ToLower(Currency.Code()) == clsString::ToLower(Code))
			{
				return Currency;
			}
		}

		return _GetEmptyCurrencyObject();
	}

	bool IsEmpty()
	{
		return this->Mode == enMode::EmptyMode;
	}

	static bool IsCurrencyExistsByCountry(string Country)
	{
		clsCurrency Currency = FindByCountry(Country);
		return !(Currency.IsEmpty());
	}

	static bool IsCurrencyExistsByCode(string Code)
	{
		clsCurrency Currency = FindByCode(Code);
		return !(Currency.IsEmpty());
	}

	double ConvertFromCurrencyToUSD(double ExchangeAmount)
	{
		return ExchangeAmount / this->Rate;
	}

	double ConvertFromUSDToCurrency(double USDAmount)
	{
		return USDAmount * this->Rate;
	}

	double ConvertToOtherCurrencies(double ExchangeAmount, clsCurrency &Currency2)
	{
		double USDAmount = ConvertFromCurrencyToUSD(ExchangeAmount);

		if (Currency2.Code() == "USD")
		{
			return USDAmount;
		}

		return Currency2.ConvertFromUSDToCurrency(USDAmount);
	}
};

