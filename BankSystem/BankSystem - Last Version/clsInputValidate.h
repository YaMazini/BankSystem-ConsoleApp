#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;

template <typename T = short>
class clsInputValidate
{
public:

    static bool IsNumberBetween(T Number, T From, T To)
    {
        return (Number >= From && Number <= To);
    }


    static T ReadNumber(string ErrorMsg = "Invalid Number, Enter again: ")
    {
        T Number = 0;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMsg;
        }

        return Number;
    }

    static T ReadNumberBetween(T From, T To, string ErrorMsg = "Number is not within range, Enter again: ")
    {
        T Number = 0;
        Number = ReadNumber("Invalid Input, Please Enter a number again: ");

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMsg;
            Number = ReadNumber("Invalid Input, Please Enter a number again: ");
        }

        return Number;
    }

    static T ReadPositiveNumber(string ErrorMsg = "Invalid Number, Please Enter a Positive Number: ")
    {
        T Number = 0;
        Number = ReadNumber("Invalid Input, Please Enter a number again: ");

        while (Number < 0)
        {
            cout << ErrorMsg;
            Number = ReadNumber("Invalid Input, Please Enter a number again: ");
        }

        return Number;
    }


    static string ReadString(string ErrorMsg = "Invalid input, enter again: ")
    {
        string S1 = "";
        do 
        {
            getline(cin >> ws, S1);
            if (S1.empty())
            {
                cout << ErrorMsg;
            }

        } while (S1.empty());

        return S1;
    }

    static char ReadChar(string ErrorMsg = "Invalid input, enter a single character: ") 
    {
        char Char;

        while (true)
        {
            cin >> Char;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (!isspace(Char))
            {
                return Char;
            }

            cout << ErrorMsg;
        }
    }


    static bool IsDateBetween(clsDate Date1, clsDate DateFrom, clsDate DateTo)
    {
        if (clsDate::IsDate1AfterDate2(DateFrom, DateTo))
        {
            clsDate::SwapDates(DateFrom, DateTo);
        }

        return (clsDate::IsDate1AfterDate2(Date1, DateFrom) && clsDate::IsDate1BeforeDate2(Date1, DateTo));
    }

    static bool IsValidDate(const clsDate& Date)
    {
        return clsDate::IsValidDate(Date);
    }
};
