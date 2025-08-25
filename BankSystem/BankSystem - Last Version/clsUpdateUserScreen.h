#pragma once
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsUpdateUserScreen : protected clsScreen
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

	static void _UpdateUser(clsUser& UpdatedUser)
	{
		cout << "\n\nUpdate User Info: ";
		cout << "\n__________________________\n";
		_ReadUserInfo(UpdatedUser);

		clsUser::enSaveResults SaveResults = UpdatedUser.Save();

		switch (SaveResults)
		{
		case clsUser::svSucceeded:
			cout << "\nUser Updated Successfully :-) \n";
			break;

		case clsUser::svFailedEmptyObject:
			cout << "\nError User was not saved because its Empty! :-| \n";
			break;

		case clsUser::svFailedUserNameExists:
			cout << "\nError User was not saved because UserName is used :-| \n";
			break;

		case clsUser::svFailedAdmin:
			cout << "\nYou Cant Update Admin Info :-| \n";
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

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\t  Update User Screen");

		clsUser UpdatedUser = _FindUser();
		_PrintUser(UpdatedUser);

		if (UpdatedUser.IsAdmin())
		{
			cout << "\n\nYou Cant Update Admin Info :-| \n";
			return;
		}

		char Answer = 'N';
		cout << "\n\nAre you sure you want to update this User? Y/N? ";
		Answer = clsInputValidate<>::ReadChar();

		if (toupper(Answer) == 'Y')
		{
			_UpdateUser(UpdatedUser);
			_PrintUser(UpdatedUser);
		}

		else
		{
			cout << "\nUpdate Cancelled!";
		}
	}
};

