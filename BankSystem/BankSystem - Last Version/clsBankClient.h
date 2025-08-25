#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

using namespace std;


class clsBankClient : public clsPerson
{
public: struct stTransferLogRecord
    {
        string DateTime;
        string SourceAccNum;
        string DestiAccNum;
        double TransferAmount = 0;
        double SourceBalance = 0;
        double DestiBalance = 0;
        string UserName;
    };


private:
    enum enMode { EmptyMode = 1, UpdateMode = 2, AddNewMode = 3};

    enMode _Mode = enMode::EmptyMode;
    string _AccountNumber;
    string _PinCode;
    double _AccountBalance = 0;
    bool _MarkedForDelete = false;

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);;
    }

    static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
    {
        vector <string> vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2]
            , vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
        string ClientRecord = "";

        ClientRecord += Client.FirstName + Seperator;
        ClientRecord += Client.LastName + Seperator;
        ClientRecord += Client.Email + Seperator;
        ClientRecord += Client.Phone + Seperator;
        ClientRecord += Client.AccountNumber() + Seperator;
        ClientRecord += Client.PinCode + Seperator;
        ClientRecord += to_string(Client.AccountBalance);

        return ClientRecord;
    }

    static vector <clsBankClient> _LoadDataFromFileToVector()
    {
        vector <clsBankClient> vClients;

        fstream ClientsFile;
        ClientsFile.open("Clients.txt", ios::in);

        if (ClientsFile.is_open())
        {
            string Line;
            while (getline(ClientsFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                vClients.push_back(Client);
            }

            ClientsFile.close();
        }

        return vClients;
    }

    static void _SaveClientsDataInFile(vector<clsBankClient>& vClients)
    {
        fstream ClientsFile;
        ClientsFile.open("Clients.txt", ios::out);

        if (ClientsFile.is_open())
        {
            for (clsBankClient& Client : vClients)
            {
                if (Client.MarkedForDelete == false)
                {
                    ClientsFile << _ConvertClientObjectToLine(Client) << endl;
                }
            }

            ClientsFile.close();
        }
    }
    
    static void _AddDataLineToFile(string DataLine)
    {
        fstream File;
        File.open("Clients.txt", ios::out | ios::app);

        if (File.is_open())
        {
            File << DataLine << endl;

            File.close();
        }
    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadDataFromFileToVector();

        for (clsBankClient& _Client : _vClients)
        {
            if (_Client.AccountNumber() == AccountNumber())
            {
                _Client = *this;
                break;
            }
        }

        _SaveClientsDataInFile(_vClients);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }


    string _ConvertTransferInfoToLine(clsBankClient DestinationClient, double TransferAmount, string UserName, string Separator = "#//#")
    {
        string TransferLine = "";

        TransferLine += clsDate::GetSystemDateTimeString() + Separator;
        TransferLine += AccountNumber() + Separator;
        TransferLine += DestinationClient.AccountNumber() + Separator;
        TransferLine += to_string(TransferAmount) + Separator;
        TransferLine += to_string(AccountBalance) + Separator;
        TransferLine += to_string(DestinationClient.AccountBalance) + Separator;
        TransferLine += UserName;

        return TransferLine;
    }

    static stTransferLogRecord _ConvertLineToTransferLogRecord(string Line, string Separator = "#//#")
    {
        vector <string> StrTransfer = clsString::Split(Line, Separator);
        stTransferLogRecord TransferLogRecord;

        TransferLogRecord.DateTime = StrTransfer[0];
        TransferLogRecord.SourceAccNum = StrTransfer[1];
        TransferLogRecord.DestiAccNum = StrTransfer[2];
        TransferLogRecord.TransferAmount = stod(StrTransfer[3]);
        TransferLogRecord.SourceBalance = stod(StrTransfer[4]);
        TransferLogRecord.DestiBalance = stod(StrTransfer[5]);
        TransferLogRecord.UserName = StrTransfer[6];

        return TransferLogRecord;
    }

    void _AddNewTransferDataLineToFile(string DataLine)
    {
        fstream TransferFile;
        TransferFile.open("TransferLog.txt", ios::out | ios::app);

        if (TransferFile.is_open())
        {
            TransferFile << DataLine << endl;

            TransferFile.close();
        }
    }

    void _RegisterTransferLog(clsBankClient DestinationClient, double TransferAmount, string UserName)
    {
        _AddNewTransferDataLineToFile(_ConvertTransferInfoToLine(DestinationClient, TransferAmount, UserName));
    }

    static vector <stTransferLogRecord> _LoadTransferDataFromFileToVector()
    {
        vector <stTransferLogRecord> vTransferLogRecord;

        fstream TransferFile;
        TransferFile.open("TransferLog.txt", ios::in);

        if (TransferFile.is_open())
        {
            string Line;
            stTransferLogRecord Transfer;

            while (getline(TransferFile, Line))
            {
                Transfer = _ConvertLineToTransferLogRecord(Line);
                vTransferLogRecord.push_back(Transfer);
            }

            TransferFile.close();
        }

        return vTransferLogRecord;
    }


public:

    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone
        , string AccountNumber, string PinCode, float AccountBalance)
        : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }

    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(double AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    double GetAccountBalance()
    {
        return _AccountBalance;
    }

    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

    void SetMarkedForDelete(bool MarkedForDelete)
    {
        _MarkedForDelete = MarkedForDelete;
    }

    bool GetMarkedForDelete()
    {
        return _MarkedForDelete;
    }

    __declspec(property(get = GetMarkedForDelete, put = SetMarkedForDelete)) bool MarkedForDelete;


    static clsBankClient Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static vector <clsBankClient> GetClientsList()
    {
        return _LoadDataFromFileToVector();
    }

    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = _LoadDataFromFileToVector();
        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {
            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client = Find(AccountNumber);
        return (!Client.IsEmpty());
    }

    bool Delete()
    {
        vector <clsBankClient> vClients = _LoadDataFromFileToVector();
 
        for (clsBankClient& Client : vClients)
        {
            if (Client.AccountNumber() == AccountNumber())
            {
                Client.MarkedForDelete = true;
                _SaveClientsDataInFile(vClients);

                *this = _GetEmptyClientObject();

                return true;
            }
        }

        return false;
    }

    enum enSaveResults { svSucceeded = 1, svFailedEmptyObject = 2, svFailedAccNumExists = 3 };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case clsBankClient::UpdateMode:
            if (!IsEmpty())
            {
                _Update();
                return enSaveResults::svSucceeded;
            }
            break;

        case clsBankClient::AddNewMode:
            if (IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFailedAccNumExists;
            }
            else
            {
                _AddNew();
                _Mode = clsBankClient::UpdateMode;
                return enSaveResults::svSucceeded;
            }
            break;

        case clsBankClient::EmptyMode:
            if (IsEmpty())
            {
                return enSaveResults::svFailedEmptyObject;
            }
            break;

        default:
            return enSaveResults::svFailedEmptyObject;
        }

        return enSaveResults::svFailedEmptyObject;
    }

    void Deposit(double DepositAmount)
    {
        AccountBalance += DepositAmount;
        Save();
    }

    void Withdraw(double WithdrawAmount)
    {
        AccountBalance -= WithdrawAmount;
        Save();
    }


    void Transfer(clsBankClient& DestinationClient, double TransferAmount, string UserName)
    {
        this->Withdraw(TransferAmount);
        DestinationClient.Deposit(TransferAmount);
        _RegisterTransferLog(DestinationClient, TransferAmount, UserName);
    }   
    
    static vector <stTransferLogRecord> GetTransfersLogList()
    {
        return _LoadTransferDataFromFileToVector();
    }
};
