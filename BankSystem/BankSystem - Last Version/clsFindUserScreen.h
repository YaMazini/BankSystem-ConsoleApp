#pragma once
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsFindUserScreen : protected clsScreen
{
private:

	static void _PrintUser(clsUser& User)
	{
		cout << "\nUser Card: ";
		cout << "\n_______________________________________";
		cout << "\nFirsName    : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFullName    : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUserName    : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n_______________________________________";
	}


public:

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\t   Find User Screen");

		cout << "\nPlease Enter UserName: ";
		string UserName = clsInputValidate<>::ReadString();

		if (clsUser::IsUserExists(UserName))
		{
			clsUser User = clsUser::Find(UserName);

			cout << "\nUser Found :-) \n";
			_PrintUser(User);
		}

		else
		{
			cout << "\nUser is Not Found! \n";
		}
	}
};

