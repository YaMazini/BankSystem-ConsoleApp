#pragma once
#include "clsScreen.h"
#include "Global.h"


class clsExitScreen : protected clsScreen
{
public:

	static void ShowExitScreen()
	{
        CurrentUser = clsUser::Find("", "");

        cout << "\n\n";
        
        cout << "\t\t\t\t\t+========================================+\n";
        cout << "\t\t\t\t\t|                                        |\n";
        cout << "\t\t\t\t\t|       PROGRAM ENDED SUCCESSFULLY       |\n";
        cout << "\t\t\t\t\t|        Latest Updates Are Saved        |\n";
        cout << "\t\t\t\t\t|                                        |\n";
        cout << "\t\t\t\t\t+========================================+\n";
       
        cout << "\nPress any key to exit...";
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\a";

        system("pause > 0");
	}
};

