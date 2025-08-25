#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsDate.h"
#include "Global.h"
using namespace std;

class clsScreen
{
protected:

	static void _ShowUserAndDate()
	{
		cout << "\n\t\t\t\t\t Date: " << clsDate::GetSystemDateHoursMinutesString();
		cout << "\n\t\t\t\t\t User: " << CurrentUser.UserName << endl;
		cout << "\t\t\t\t\t Name: " << CurrentUser.FullName() << endl;
	}

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t " << Title << endl;

		if (SubTitle != "")
		{
			cout << "\t\t\t\t" << SubTitle << endl;
		}

		cout << "\t\t\t\t\t______________________________________\n";

		_ShowUserAndDate();
	}

	static bool _HasPermission(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			_DrawScreenHeader(" Access Denied! Contact your Admin.");
			return false;
		}

		else
		{
			return true;
		}
	}
};

