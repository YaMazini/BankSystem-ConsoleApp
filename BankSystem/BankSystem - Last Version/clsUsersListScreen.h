#pragma once
#include "clsUser.h"
#include "clsScreen.h"

class clsUsersListScreen : protected clsScreen
{
private:

    static void _PrintUserListTableHeader()
    {
        cout << "\n\n     _______________________________________________________________________________________________________________\n\n";
         
        cout << "     | " << left << setw(10) << "UserName";
        cout << "     | " << left << setw(15) << "FullName";
        cout << "     | " << left << setw(10) << "Phone";
        cout << "     | " << left << setw(20) << "Email";
        cout << "     | " << left << setw(8) << "Password";
        cout << "     | " << left << setw(12) << "Permissions" << endl;
                       
        cout << "     _______________________________________________________________________________________________________________\n\n";
    }

    static void _PrintUserRecordLine(clsUser &User)
    {
        cout << "     | " << left << setw(10) << User.UserName;
        cout << "     | " << left << setw(15) << User.FullName();
        cout << "     | " << left << setw(10) << User.Phone;
        cout << "     | " << left << setw(20) << User.Email;
        cout << "     | " << left << setw(8) << User.Password;
        cout << "     | " << left << setw(12) << User.Permissions << endl;
    }


public:

	static void ShowUsersListScreen()
	{
		vector <clsUser> vUsers = clsUser::GetUsersList();

		string Title = "\t   Users List Screen";
		string SubTitle = "\t\t     (" + to_string(vUsers.size()) + ") User(s).";

		_DrawScreenHeader(Title, SubTitle);

        if (vUsers.size() > 0)
        {
            _PrintUserListTableHeader();

            for (clsUser& User : vUsers)
            {
                _PrintUserRecordLine(User);
            }

            cout << "     _______________________________________________________________________________________________________________\n\n";
        }


        else
        {
            cout << "\n\n\t\t\t\t      |-: No Client Available In the System :-| \n";
        }

	}
};
