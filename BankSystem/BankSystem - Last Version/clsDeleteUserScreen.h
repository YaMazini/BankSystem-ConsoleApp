#pragma once
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsDeleteUserScreen : protected clsScreen
{
private:

	static clsUser _FindUser()
	{
		cout << "\nPlease Enter UserName: ";
		string UserName = clsInputValidate<>::ReadString();

		while (!clsUser::IsUserExists(UserName))
		{
			cout << "\nUser is not found, choose another one: ";
			UserName = clsInputValidate<>::ReadString();
		}

		return clsUser::Find(UserName);
	}

	static void _DeleteUser(clsUser &User)
	{
		if (User.IsAdmin())
		{
			cout << "\nYou Cant Delete The Admin :-| \n";
			return;
		}

		if (User.Delete())
		{
			cout << "\nUser Deleted Successfully :-) \n";
			
		}

		else
		{
			cout << "\nError User was not Deleted :-| \n";
		}
	}

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

	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\t  Delete User Screen");

		clsUser User = _FindUser();
		_PrintUser(User);
		
		if (User.IsAdmin())
		{
			cout << "\n\nYou Cant Delete the Admin :-| \n";
			return;
		}

		char Answer = 'N';
		cout << "\n\nAre you sure you want to delete this User? Y/N? ";
		Answer = clsInputValidate<>::ReadChar();

		if (toupper(Answer) == 'Y')
		{
			_DeleteUser(User);
			_PrintUser(User);
		}

		else
		{
			cout << "\nDeletion Cancelled!";
		}
	}
};

