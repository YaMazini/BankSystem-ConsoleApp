#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"

#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{
private:

	enum enManageUsersMenuOption 
	{
		ShowListUsers_Option = 1,
		AddNewUser = 2,
		DeleteUser_Option = 3,
		UpdateUserInfo_Option = 4,
		FindUser_Option = 5,
		MainMenu_Option = 6
	};

	static short _ReadManageUsersMenuOption()
	{
		short Option = 0;
		Option = clsInputValidate<>::ReadNumberBetween(1, 6);
		return Option;
	}

	static void _DrawManageUsersMenuScreen()
	{
		cout << endl << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t    [1] List Users.\n";
		cout << setw(37) << left << "" << "\t    [2] Add New User.\n";
		cout << setw(37) << left << "" << "\t    [3] Delete User.\n";
		cout << setw(37) << left << "" << "\t    [4] Update User.\n";
		cout << setw(37) << left << "" << "\t    [5] Find User.\n";
		cout << setw(37) << left << "" << "\t    [6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
	}

	static void _GoBackToManageUsersMenuScreen()
	{
		cout << "\n\n\t Press any key to go back to Manage Users Menu...";
		system("pause > 0");
		ShowManageUsersMenuScreen();
	}


	static void _ShowListUserScreen()
	{
		clsUsersListScreen::ShowUsersListScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	
	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserInfoScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}


	static void _PerformManageUsersMenuOption(enManageUsersMenuOption ManageUsersMenuOption)
	{
		switch (ManageUsersMenuOption)
		{
		case clsManageUsersScreen::enManageUsersMenuOption::ShowListUsers_Option:

			system("cls");
			_ShowListUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;

		case clsManageUsersScreen::enManageUsersMenuOption::AddNewUser:

			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;

		case clsManageUsersScreen::enManageUsersMenuOption::DeleteUser_Option:

			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;

		case clsManageUsersScreen::enManageUsersMenuOption::UpdateUserInfo_Option:

			system("cls");
			_ShowUpdateUserInfoScreen();
			_GoBackToManageUsersMenuScreen();
			break;

		case clsManageUsersScreen::enManageUsersMenuOption::FindUser_Option:

			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;

		case clsManageUsersScreen::enManageUsersMenuOption::MainMenu_Option:
			//Do Nothing here the MainMenu Will Handle it :-)
			break;

		default:

			_GoBackToManageUsersMenuScreen();
			break;
		}
	}


public:

	static void ShowManageUsersMenuScreen()
	{
		system("cls");

		if (!_HasPermission(clsUser::enPermissions::ManageUsers_p))
		{
			return;
		}

		_DrawScreenHeader("\t Manage Users Screen");
		_DrawManageUsersMenuScreen();

		cout << setw(37) << left << "" << "  Choose what do you want to do [1 to 6]:  ";
		_PerformManageUsersMenuOption((enManageUsersMenuOption)_ReadManageUsersMenuOption());
	}
};

