#pragma once
#include "clsUser.h"
#include <iomanip>
#include "clsScreen.h"

class clsLoginRegisterScreen :protected clsScreen
{

private:

    static void _PrintLoginRegisterTableHeader()
    {
        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";

        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n" << endl;

    }

    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
    }

public:

    static void ShowLoginRegisterScreen()
    {
        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

        string Title = "     Login Register List Screen";
        string SubTitle = "\t\t   (" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);
      
        if (vLoginRegisterRecord.size() > 0)
        {
            _PrintLoginRegisterTableHeader();

            for (clsUser::stLoginRegisterRecord &LoginRecord : vLoginRegisterRecord)
            {
                _PrintLoginRegisterRecordLine(LoginRecord);
                cout << endl;
            }

            cout << setw(8) << left << "" << "________________________________________________________________________________________________\n" << endl;
        }

        else
        {
            cout << "\t\t\t\tNo Logins Available In the System!";
        }
    }
};
