#pragma once
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsAddNewUserScreen : protected clsScreen
{
private:

	static clsUser _FindUser()
	{
		cout << "\nPlease Enter UserName: ";
		string UserName = clsInputValidate<>::ReadString();

		while (clsUser::IsUserExists(UserName))
		{
			if (clsUser::IsAdmin(UserName))
			{
				cout << "\nYou Cant Update the Admin :-|, Please choose another UserName: ";
			}
			else
			{
				cout << "\nUserName is Already Used, Choose another one: ";
			}

			UserName = clsInputValidate<>::ReadString();
		}

		return clsUser::GetAddNewUserObject(UserName);
	}

	static short _ReadPermissionsToSet()
	{
		short Permissions = 0;
		char Answer = 'N';

		cout << "\nDo you Want to give full access? Y/N? ";
		Answer = clsInputValidate<>::ReadChar();

		if (toupper(Answer) == 'Y')
		{
			return (short)clsUser::enPermissions::All_p;  //returns -1 All Permissions
		}


		cout << "\nDo you want to give access to: \n";

		cout << "\nShow Client List? Y/N? ";
		Answer = clsInputValidate<>::ReadChar();

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::ShowClientList_p;
		}

		cout << "\nAdd New Client? Y/N? ";
		Answer = clsInputValidate<>::ReadChar();

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::AddNewClient_p;
		}

		cout << "\nDelete Client? Y/N? ";
		Answer = clsInputValidate<>::ReadChar();

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::DeleteClient_p;
		}

		cout << "\nUpdate Client Info? Y/N? ";
		Answer = clsInputValidate<>::ReadChar();

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::UpdateClientInfo_p;
		}

		cout << "\nFind Client? Y/N? ";
		Answer = clsInputValidate<>::ReadChar();

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::FindClient_p;
		}

		cout << "\nTransactions? Y/N? ";
		Answer = clsInputValidate<>::ReadChar();

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::Transactions_p;
		}

		cout << "\nCurrency Exchange? Y/N? ";

		Answer = clsInputValidate<>::ReadChar();
		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::CurrencyExchange_p;
		}


		cout << "\nManage Users? Y/N? ";
		Answer = clsInputValidate<>::ReadChar();

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::ManageUsers_p;
		}

		cout << "\nLogin Register? Y/N? ";
		Answer = clsInputValidate<>::ReadChar();

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::LoginRegister_p;
		}

		
		if (Permissions == 511)   // Returns All_p if the NewUser Has all Permissions.
		{
			return -1;        
		}

		return Permissions;
	}

	static void _ReadUserInfo(clsUser& User)
	{
		char Answer = 'N';

		cout << "\nEnter FirsName: ";
		User.FirstName = clsInputValidate<>::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate<>::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate<>::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate<>::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate<>::ReadString();

		cout << "\nEnter Permissions: ";
		User.Permissions = _ReadPermissionsToSet();
	}

	static void _AddNewUser(clsUser::enSaveResults SaveResult)
	{
		switch (SaveResult)
		{
		case clsUser::svSucceeded:
			cout << "\nUser Accessed Successfully :-) \n";

			break;

		case clsUser::svFailedEmptyObject:
			cout << "\nError User was not saved because its Empty! :-| \n";
			break;

		case clsUser::svFailedUserNameExists:
			cout << "\nError User was not saved because UserName is used :-| \n";
			break;

		case clsUser::svFailedAdmin:
			cout << "\nYou Cant Add another Admin :-| \n";
			break;

		default:
			cout << "\nUnexpected Error!";
			break;
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

	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t Add New User Screen");

		clsUser NewUser = _FindUser();
		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult = NewUser.Save();
       
		_AddNewUser(SaveResult);
		_PrintUser(NewUser);
	}
};

