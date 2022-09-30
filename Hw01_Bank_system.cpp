#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstring>


#define MAX_NAME 20
#define MAX_ACCOUNT 15

using namespace std;

enum {MAKE_ACCOUNT = 1, DEPOSIT, WITHDRAW, CHECK_BALANCE, DELETE_ACCOUNT, FORMAT_DATA, EXIT = 9};

class Account_info
{
private:
    struct User_info {
        unsigned int user_id;
        char user_name[MAX_NAME];
        char account_number[MAX_ACCOUNT];
        int balance;
    } ;
        int deposit;
        int withdraw;
        vector <User_info> vec_user_info;
        FILE* DBdata;
public:
    Account_info();
    virtual ~Account_info();
    void Load_member_info();
    void Main_menu();
    void Make_user_account();
    void Deposit_money();
    void Withdraw_money();
    void Check_balance();
    void Delete_user_account();
    void Update_DB();
    void Format_memory_and_DB();
};

Account_info::Account_info()
{
   Load_member_info();
}

Account_info::~Account_info()
{
    
}

void Account_info::Load_member_info()
{
     User_info user_info;

    DBdata = fopen("Bank_member_info.bin", "r");

    if(DBdata == NULL)
    {
        fprintf(stderr, "file open error!\n");
        return;
    }
    while(fread(&user_info, sizeof(user_info), 1, DBdata))
    {
        vec_user_info.push_back(user_info);
    }
    fclose(DBdata);
}

void Account_info::Main_menu()
{   
    int select;

    cout << "Hello, this is ROK Seoul Bank!" << endl;
    cout << "Choose Service for you" << endl;
    cout << endl;
    cout << "1. Make Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Check_your_account(Inclde balance)" << endl;
    cout << "5. Delete Account" << endl;
    cout << "6. Memory and DB format" << endl;
    cout << endl;
    cout << "Input_number(Exit : 9) : ";
    
    cin >> select;
    cout << endl;

    switch (select)
    {
    case MAKE_ACCOUNT:
        Make_user_account();
        break;
    case DEPOSIT:
        Deposit_money();
        break;
    case WITHDRAW:
        Withdraw_money();
        break;
    case CHECK_BALANCE:
        Check_balance();
        break;
    case DELETE_ACCOUNT:
        Delete_user_account();
        break;
    case FORMAT_DATA:
        Format_memory_and_DB();
        break;
    case EXIT:
        exit(0);
        break;
    default:
        cout << "Please input number(1~5)!\nReturn to the first screen..." << endl;
        system("sleep 2s");
        select = MAKE_ACCOUNT;
        break;
    }
    system("clear");
}

void Account_info::Make_user_account()
{
    jump:
    char press_key;

    remake:

    User_info user_info;
    vector<User_info>::iterator itr;
    system("clear");
    cout << "Make account! Input your infomation" << endl;

    itr = vec_user_info.begin();
    if( itr->user_id != 1) user_info.user_id = 1;
    else user_info.user_id = vec_user_info.size()+1;

    user_info.balance = 0;

    cout << "Name : ";
    cin >> user_info.user_name;
    cout << "User_account_number(Phone_number, 000-0000-0000) : ";
    cin >> user_info.account_number;
    
    for (itr = vec_user_info.begin(); itr != vec_user_info.end(); itr++)
    {
        cout << endl;

        if(strcmp(itr->account_number, user_info.account_number) == 0)
        {
            cout << "==============Overlap Account==============" << endl;
            cout << "Id : " << itr->user_id << " " << "Name : " << itr->user_name << " " << "Account_number : " << itr->account_number 
            << " " << endl;
            cout << "===========================================" << endl;
            cout << "Overlap member information! Retry Enter information!" << endl;
            cout << endl;
            cout << "Enter any key, continue... : ";
            cin >> press_key;

            goto remake;
        }
    }
    
    cout << endl;

    cout << "Id : " << user_info.user_id << " / " << "Name : " << user_info.user_name << " / " << "Account_number : " << 
    user_info.account_number << " / " << "Balance : " << user_info.balance << " won" << endl;

    cout << endl;

    cout << "Is the entered information correct?(y/n)" << endl;
    cin >> press_key;
    if(press_key == 'y') vec_user_info.emplace_back(user_info);
    else goto jump;

    cout << endl;
    cout << "Complete your account!" << endl;
    cout << endl;

    Update_DB();

    cout << "press any key, return to the first page..." << endl;
    cin >> press_key;
}

void Account_info::Deposit_money()
{
    system("clear");
    string buff;
    char press_key;

    cout << "This is deposit mode! Enter your account number" << endl;
    cout << "Account number(000-0000-0000) : ";
    cin >> buff;

    cout << endl;
    cout << endl;

    vector<User_info>::iterator itr;
    for (itr = vec_user_info.begin(); itr != vec_user_info.end(); itr++)
    {
        if(itr->account_number == buff)
        {
            cout << "==============Check Account==============" << endl;
            cout << "Id : " << itr->user_id << " " << "Name : " << itr->user_name << " " << "Account_number : " << itr->account_number 
            << " " << "Balance : " << itr->balance << "won" << endl;
            cout << "=========================================" << endl;
        }
    }

    cout << "Is the entered information correct?(y/n)" << endl;
    cin >> press_key;
    if(press_key == 'y')
    {
        cout << "Enter the hoped deposit amount : " << endl;

        for (itr = vec_user_info.begin(); itr != vec_user_info.end(); itr++)
        {
            if(itr->account_number == buff)
            {
            cin >> deposit;
            itr->balance += deposit; 
            cout << endl;
            
            cout << "Deposit complete!" << endl;

            cout << "=================Account=================" << endl;
            cout << "Id : " << itr->user_id << " " << "Name : " << itr->user_name << " " << "Account_number : " << itr->account_number 
            << " " << "Balance : " << itr->balance << "won" << endl;
            cout << "=========================================" << endl;
            }
        }
        cout << endl;

        Update_DB();

        cout << "press any key, return to the first page..." << endl    ;
        cin >> press_key;
    }
}

void Account_info::Withdraw_money()
{
    system("clear");
    string buff;
    char press_key;

    cout << "This is withdraw mode! Enter your account number" << endl;
    cout << "Account number(000-0000-0000) : ";
    cin >> buff;

    cout << endl;
    cout << endl;

    vector<User_info>::iterator itr;
    for (itr = vec_user_info.begin(); itr != vec_user_info.end(); itr++)
    {
        if(itr->account_number == buff)
        {
            cout << "==============Check Account==============" << endl;
            cout << "Id : " << itr->user_id << " " << "Name : " << itr->user_name << " " << "Account_number : " << itr->account_number 
            << " " << "Balance : " << itr->balance << "won" << endl;
            cout << "=========================================" << endl;
        }
    }

    cout << "Is the entered information correct?(y/n)" << endl;
    cin >> press_key;
    if(press_key == 'y')
    {
        cout << "Enter the hoped withdraw amount : " << endl;

        for (itr = vec_user_info.begin(); itr != vec_user_info.end(); itr++)
        {
            if(itr->account_number == buff)
            {
            withdraw_return:
            cin >> withdraw;
            if(itr->balance < withdraw)
            {
                cout << "Insufficient balance. Please re-enter the amount" << endl;
                system("sleep 2s");
                system("clear");
                goto withdraw_return;
            }
            itr->balance -= withdraw; 
            cout << endl;
            
            cout << "Withdraw complete!" << endl;

            cout << "=================Account=================" << endl;
            cout << "Id : " << itr->user_id << " " << "Name : " << itr->user_name << " " << "Account_number : " << itr->account_number 
            << " " << "Balance : " << itr->balance << "won" << endl;
            cout << "=========================================" << endl;
            }
        }
        cout << endl;

        Update_DB();

        cout << "press any key, return to the first page..." << endl    ;
        cin >> press_key;
    }    
}

void Account_info::Check_balance()
{
    system("clear");
    string buff;
    char press_key;

    cout << "Check your account! Enter your account number" << endl;
    cout << "Account number(000-0000-0000) : ";
    cin >> buff;

    cout << endl;
    cout << endl;

    vector<User_info>::iterator itr;
    for (itr = vec_user_info.begin(); itr != vec_user_info.end(); itr++)
    {
        if(itr->account_number == buff)
        {
            cout << "==============Check Account==============" << endl;
            cout << "Id : " << itr->user_id << " " << "Name : " << itr->user_name << " " << "Account_number : " << itr->account_number 
            << " " << "Balance : " << itr->balance << "won" << endl;
            cout << "========================================" << endl;
        }
    }
    cout << endl;

    Update_DB();

    cout << "press any key, return to the first page..." << endl    ;
    cin >> press_key;
}

void Account_info::Delete_user_account()
{
    here:
    system("clear");
    string buff;
    char press_key;

    cout << "Delete account mode! Enter your account number" << endl;
    cout << "Account number(000-0000-0000) : ";
    cin >> buff;

    cout << endl;
    cout << endl;

    vector<User_info>::iterator itr;
    for (itr = vec_user_info.begin(); itr != vec_user_info.end(); itr++)
    {
        if(itr->account_number == buff)
        {
            cout << "==============Check Account==============" << endl;
            cout << "Id : " << itr->user_id << " " << "Name : " << itr->user_name << " " << "Account_number : " << itr->account_number 
            << " " << "Balance : " << itr->balance << "won" << endl;
            cout << "========================================" << endl;

            cout << endl;

            cout << "Really delete?(y/n)" << endl;
            cin >> press_key;
            if(press_key == 'y') 
            {
                vec_user_info.erase(itr);
                cout << endl;

                cout << "Complete!!" << endl;
                break;
            }
            if(press_key == 'n')
            {
                goto here;
            }
            else
            {
                cout << "Enter 'y' or 'n'" << endl;
                system("sleep 2s");
                goto here;
            }
        }
    }

    Update_DB();

    cout << "press any key, return to the first page..." << endl    ;
    cin >> press_key;    
}

void Account_info::Update_DB()
{
    User_info user_info;

    DBdata = fopen("Bank_member_info.bin", "w");
    FILE* DBdata2 = fopen("Bank_member_info.txt", "w");
    if(DBdata == NULL)
    {
        fprintf(stderr, "file open error!\n");
        return;
    }
    for(const auto &user_info : vec_user_info)
    {
        fwrite(&user_info, sizeof(user_info), 1, DBdata);
        fprintf(DBdata2, "%d %s %s %d\n", user_info.user_id, user_info.user_name, user_info.account_number, user_info.balance);
    }
    fclose(DBdata);
    fclose(DBdata2);
}

void Account_info::Format_memory_and_DB()
{
    vec_user_info.clear();

    Update_DB();
}

int main()
{
    Account_info* account_info = new Account_info();

    while(1)
    {
        account_info->Main_menu();
    }

    return 0;
}