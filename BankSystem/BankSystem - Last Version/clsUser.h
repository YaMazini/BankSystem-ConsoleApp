#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"

using namespace std;

class clsUser : public clsPerson
{
public: struct stLoginRegisterRecord
{
	string DateTime;
	string UserName;
	string Password;
	short Permissions = 0;
};

private:

	enum enMode { EmptyMode = 1, UpdateMode = 2, AddNewMode = 3 };

	enMode _Mode = enMode::EmptyMode;
	string _UserName;
	string _Password;
	int _Permissions = 0;

	bool _MarkedForDelete = false;

	static short _EncryptionKey;

	static clsUser _GetEmptyUsersObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsUser _ConvertLineToUserObject(string Line, string Separator = "#//#")
	{
		vector <string> vUser = clsString::Split(Line, Separator);

		return clsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2],
			vUser[3], vUser[4], clsString::Decrypt(vUser[5], _EncryptionKey), stoi(vUser[6]));
	}

	static string _ConvertUserObjectToLine(clsUser& User, string Separator = "#//#")
	{
		string S1 = "";

		S1 += User.FirstName + Separator;
		S1 += User.LastName + Separator;
		S1 += User.Email + Separator;
		S1 += User.Phone + Separator;
		S1 += User.UserName + Separator;
		S1 += clsString::Encrypt(User.Password, _EncryptionKey) + Separator;
		S1 += to_string(User.Permissions);

		return S1;
	}

	static vector <clsUser> _LoadUsersDataFromFileToVector()
	{
		vector <clsUser> vUsers;

		fstream UsersFile;
		UsersFile.open("Users.txt", ios::in);

		if (UsersFile.is_open())
		{
			string Line;
			clsUser User = _GetEmptyUsersObject();
			while (getline(UsersFile, Line))
			{
				User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}

			UsersFile.close();
		}

		return vUsers;
	}

	static void _SaveUsersDataInFile(vector <clsUser>& vUsers)
	{
		fstream UsersFile;
		UsersFile.open("Users.txt", ios::out);

		if (UsersFile.is_open())
		{
			for (clsUser& User : vUsers)
			{
				if (User.MarkedForDelete == false)
				{
					UsersFile << _ConvertUserObjectToLine(User) << endl;
				}
			}

			UsersFile.close();
		}
	}

	static void _AddNewUserLineToFile(string Line)
	{
		fstream UsersFile;
		UsersFile.open("Users.txt", ios::out | ios::app);

		if (UsersFile.is_open())
		{
			UsersFile << Line << endl;

			UsersFile.close();
		}

		UsersFile.close();
	}

	void _AddNew()
	{
		_AddNewUserLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _Update()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFileToVector();

		for (clsUser& User : vUsers)
		{
			if (User.UserName == UserName)
			{
				User = *this;
				break;
			}
		}

		_SaveUsersDataInFile(vUsers);
	}


	string _ConvertLoginRegisterRecordToLine(string Separator = "#//#")
	{
		string StrLogin = "";

		StrLogin += clsDate::GetSystemDateTimeString() + Separator;
		StrLogin += UserName + Separator;
		StrLogin += clsString::Encrypt(Password, _EncryptionKey) + Separator;
		StrLogin += to_string(Permissions);

		return StrLogin;
	}

	static stLoginRegisterRecord _ConvertLineToLoginRegisterRecord(string Line, string Separator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;
		vector <string> vLoginRecord = clsString::Split(Line, Separator);
	
		LoginRegisterRecord.DateTime = vLoginRecord[0];
		LoginRegisterRecord.UserName = vLoginRecord[1];
		LoginRegisterRecord.Password = clsString::Decrypt(vLoginRecord[2], _EncryptionKey);
		LoginRegisterRecord.Permissions = stoi(vLoginRecord[3]);

		return LoginRegisterRecord;
	}

	static vector <stLoginRegisterRecord> _LoadLoginsDataFromFileToVector()
	{
		vector <stLoginRegisterRecord> vLoginRegisterRecord;

		fstream LoginRegister;
		LoginRegister.open("LoginRegister.txt", ios::in);


		if (LoginRegister.is_open())
		{
			string Line;
			stLoginRegisterRecord LoginInfo;

			while (getline(LoginRegister, Line))
			{
				LoginInfo = _ConvertLineToLoginRegisterRecord(Line);

				vLoginRegisterRecord.push_back(LoginInfo);
			}

			LoginRegister.close();
		}
	
		return vLoginRegisterRecord;
	}

	void _AddNewLoginLineToFile(string Line)
	{
		fstream LoginsFile;
		LoginsFile.open("LoginRegister.txt", ios::out | ios::app);

		if (LoginsFile.is_open())
		{
			LoginsFile << Line << endl;

			LoginsFile.close();
		}
	}



public:

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string UserName, string Password, short Permessions) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permessions;
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

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(short Permissions)
	{
		_Permissions = Permissions;
	}

	short GetPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) short Permissions;

	void SetMarkedForDelete(bool MarkedForDelete)
	{
		_MarkedForDelete = MarkedForDelete;
	}

	bool GetMarkedForDelete()
	{
		return _MarkedForDelete;
	}

	__declspec(property(get = GetMarkedForDelete, put = SetMarkedForDelete)) bool MarkedForDelete;


	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFileToVector();
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static clsUser Find(string UserName)
	{
		fstream UsersFile;
		UsersFile.open("Users.txt", ios::in);

		if (UsersFile.is_open())
		{
			string Line;
			clsUser User = _GetEmptyUsersObject();

			while (getline(UsersFile, Line))
			{
				User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName)
				{
					UsersFile.close();
					return User;
				}
			}

			UsersFile.close();
		}

		return _GetEmptyUsersObject();
	}

	static clsUser Find(string UserName, string Password)
	{
		fstream UsersFile;
		UsersFile.open("Users.txt", ios::in);

		if (UsersFile.is_open())
		{
			string Line;
			clsUser User = _GetEmptyUsersObject();

			while (getline(UsersFile, Line))
			{
				User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName && User.Password == Password)
				{
					UsersFile.close();
					return User;
				}
			}

			UsersFile.close();
		}

		return _GetEmptyUsersObject();
	}

	bool IsEmpty()
	{
		return (Mode == enMode::EmptyMode);
	}

	static bool IsUserExists(string UserName)
	{
		clsUser User = Find(UserName);
		return (!User.IsEmpty());
	}

	static bool IsValid(string UserName, string Password)
	{
		if (IsUserExists(UserName))
		{
			clsUser User = Find(UserName);
			return User.Password == Password;
		}
	}

	static bool IsAdmin(string UserName)
	{
		return UserName == "Admin";
	}

	bool IsAdmin()
	{
		return IsAdmin("Admin");
	}

	bool Delete()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFileToVector();

		for (clsUser& User : vUsers)
		{
			if (User.UserName == UserName)
			{
				User.MarkedForDelete = true;
				_SaveUsersDataInFile(vUsers);

				*this = _GetEmptyUsersObject();

				return true;
			}
		}

		return false;
	}


	enum enSaveResults
	{
		svSucceeded = 1,
		svFailedEmptyObject = 2,
		svFailedUserNameExists = 3,
		svFailedAdmin = 4
	};

	enSaveResults Save()
	{
		switch (Mode)
		{
		case clsUser::EmptyMode:
			if (IsEmpty())
			{
				return enSaveResults::svFailedEmptyObject;
			}


		case clsUser::UpdateMode:
			if (IsAdmin())
			{
				return enSaveResults::svFailedAdmin;
			}

			if (IsEmpty())
			{
				return enSaveResults::svFailedEmptyObject;
			}
			
			else
			{
				_Update();
				return enSaveResults::svSucceeded;
			}
			

		case clsUser::AddNewMode:
			if (IsAdmin())
			{
				return enSaveResults::svFailedAdmin;
			}

			if (IsUserExists(UserName))
				return enSaveResults::svFailedUserNameExists;

			else
			{
				Mode = enMode::UpdateMode;
				_AddNew();
				return enSaveResults::svSucceeded;
			}
			
		default:
			return enSaveResults::svFailedEmptyObject;
		}
	}

	enum enPermissions
	{ 
		All_p = -1 ,
		ShowClientList_p = 1, 
		AddNewClient_p = 2,
		DeleteClient_p = 4,
	    UpdateClientInfo_p = 8,
		FindClient_p = 16,
		Transactions_p = 32,
		CurrencyExchange_p = 64,
		ManageUsers_p = 128,
		LoginRegister_p = 256
	};

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::All_p)
			return true;
	
		if ((this->Permissions & short(Permission)) == Permission)
			return true;

		return false;
	}


	void RegisterLogin()
	{
		_AddNewLoginLineToFile(_ConvertLoginRegisterRecordToLine());
	}

	static vector <stLoginRegisterRecord> GetLoginRegisterList()
	{
		return _LoadLoginsDataFromFileToVector();
	}
};

short clsUser::_EncryptionKey = 3;