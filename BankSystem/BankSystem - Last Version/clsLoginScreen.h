#pragma once
#include "clsMainScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

#include "clsScreen.h"


class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFailed = false;
		short Trials = 3;
		string UserName = "";
		string Password = "";

		do
		{
			if (LoginFailed)
			{
				cout << "\n Invalid UserName/Password! \n";
				cout << "You have " << Trials << " Trial(s) to login.\n";
			}

			cout << "\nEnter UserName: ";
			UserName = clsInputValidate<>::ReadString();
			cout << "Enter Password: ";
			Password = clsInputValidate<>::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

			Trials--;

			if (Trials == 0)
			{
				cout << "\n\t\t\t\t\tYou are Locked after 3 Failed Trials.\n\n";
				return false;
			}

		} while (LoginFailed);

		CurrentUser.RegisterLogin();
		return true;
	}


public:

	static bool ShowLoginScreen()
	{
		_DrawScreenHeader("\t     Login Screen");

		if (_Login())
		{
			clsMainScreen::ShowMainMenu();

			return true;
		}

		return false;
	}
};

