#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"

#include <iomanip>
using namespace std;


class clsTransferLogListScreen : protected clsScreen
{
private:

	static void _PrintTransferLogTableHeader()
	{
		cout << "\n\n   ______________________________________________________________________________________________________________\n\n";

		cout << "   | " << left << setw(19) << "Date/Time";
		cout << "   | " << left << setw(10) << "Source Acc";
		cout << "   | " << left << setw(10) << "Desti. Acc";
		cout << "   | " << left << setw(10) << "Amount";
		cout << "   | " << left << setw(10) << "S. Balance";
		cout << "   | " << left << setw(10) << "D. Balance";
		cout << "   | " << left << setw(8) << "User" << endl;
				      
		cout << "   ______________________________________________________________________________________________________________\n\n";
	}			     

	static void _PrintTransferLogRecord(clsBankClient::stTransferLogRecord Transfer)
	{
		cout << "   | " << left << setw(18) << Transfer.DateTime;
		cout << "   | " << left << setw(10) << Transfer.SourceAccNum;
		cout << "   | " << left << setw(10) << Transfer.DestiAccNum;
		cout << "   | " << left << setw(10) << Transfer.TransferAmount;
		cout << "   | " << left << setw(10) << Transfer.SourceBalance;
		cout << "   | " << left << setw(10) << Transfer.DestiBalance;
		cout << "   | " << left << setw(8) << Transfer.UserName << endl;
	}			     


public:

	static void ShowTransferLogListScreen()
	{
		vector <clsBankClient::stTransferLogRecord> vTransferLogRecord;
		vTransferLogRecord = clsBankClient::GetTransfersLogList();

		string Title = "      Transfer Log List Screen";
		string Subtitle = "\t\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, Subtitle);

		if (vTransferLogRecord.size() > 0)
		{
			_PrintTransferLogTableHeader();

			for (clsBankClient::stTransferLogRecord& Transfer : vTransferLogRecord)
			{
				_PrintTransferLogRecord(Transfer);
			}

			cout << "   ______________________________________________________________________________________________________________\n\n";
		}

		else
		{
			cout << "\n\n\t\t\t\t    |-: No Transfer is Available In the System :-| \n";
		}
	}
};

