
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <map>
#include <list>
#include <Windows.h>
using namespace std;
const char n = '\n';
void login(), registr(), menu(), statusCheck();
void statusCheck()
{

}
class Reg_user 
{
public:
    struct log_adm
    {
        char login[255];
        char password[255];
    };

    void login_adm()
    {
        log_adm userIn, readIn;
        cout << "����i�� ���i� ";
        cin >> userIn.login;
        cout << "����i�� ������ ";
        cin >> userIn.password;
        ifstream in("user.dat", ios::binary);
        bool flag = false;
        while (!in.eof())
        {
            in.read(reinterpret_cast<char*>(&readIn), sizeof(log_adm)); 
            if (strcmp(userIn.login, readIn.login) == 0 && strcmp(userIn.password, readIn.password) == 0);
            {
                flag = true;
                break;
            }
        }
        in.close();
        flag ? cout << "�� ���i��� ������ � �������. " << userIn.login << "!\n"
            : cout << "�������, ��� ����i��� ����������� �� ���\n";
        cout << n;
        int m = 0;
        cout << "�����i�� �����" << n;
        cout << "1. ������� i ��������� ���� �������������." << n;
        switch (m)
        {
        case 1:
            ofstream fout; 
            fout.open("Test for the tested.txt"); 
            fout << "";

        }
    }

    void To_make_a_test() 
    {

    }

    struct log_users 
    {
        string name; 
        string adress; 
        string House_number; 
        string num; 
        char login[255]; 
        char password[255]; 
     };

    void login()
    {
        log_users userIn, readIn;
        cout << "��e�i�� ���i� ";
        cin >> userIn.login;
        cout << "����i�� ������ ";
        cin >> userIn.password;
        ifstream in("user.dat", ios::binary);
        bool flag = false;
        while (!in.eof())
        {
            in.read(reinterpret_cast<char*>(&readIn), sizeof(log_users)); 
            if (strcmp(userIn.login, readIn.login) == 0 && strcmp(userIn.password, readIn.password) == 0);
            {
                flag = true;
                break;
            }
        }
        in.close();
        flag ? cout << "�� ���i��� ������ � ������� " << userIn.login << "!\n"
            : cout << "�������, ��� ����i��� ����������� �� ���\n";
    }

    void menu()
    {
        cout << "����i�, ������������!" << n;
        cout << "��� ����� ����i��(y).��� ��������������  (n) ";
        char temp;
        cin >> temp;
        if (temp == 'y')
        {
            login();
        }
        else if (temp == 'n')
        {
            registr();
        }
    }

    void registr() 
    {
        log_users dataUser;
        char i; 
        do
        {
            cout << "I�� �������������? ";
            cin >> dataUser.name;
            for (i = 0; dataUser.name[i]; i++)
            {
                if (dataUser.name[i] >= '0' && dataUser.name[i] <= '9')
                {
                    cout << "I�� �� ���� ���� ������� i � ������������ �������" << n <<
                        "I�� ���� ���� �i���� ������� ����i������� �����i��" << n
                        << "���� �����,������i��!" << n;
                    break;
                }
                if (dataUser.name[i] >= 'Aa' && dataUser.name[i] <= 'Zz'
                    || dataUser.name[i] >= '��' && dataUser.name[i] <= '��');
            }
        } while (dataUser.name[i]);

        do
        {
            cout << "����� �����i? ";
            cin >> dataUser.adress;
            for (i = 0; dataUser.adress[i]; i++)
            {
                if (dataUser.adress[i] >= '0' && dataUser.adress[i] <= '9')
                {
                    cout << "� ����i �����i ����� ���� �i���� �����" << n << "������i�� ������" << n;
                    break;
                }
            }   if (dataUser.adress[i] >= 'Aa' && dataUser.adress[i] <= 'Zz'
                || dataUser.adress[i] >= '��' && dataUser.adress[i] <= '��');
        } while (dataUser.adress[i]);

        do
        {
            cout << "����� ��������? ";
            cin >> dataUser.House_number;
            for (i = 0; i < dataUser.House_number[i]; i++)
            {
                if (!isdigit(dataUser.House_number[i]))
                {
                    cout << "����� �������� ���� ���� �i���� �����!" << n <<
                        "���������� �� ���!" << n;;
                    break;
                }
                if (isdigit(dataUser.House_number[i]));
            }
        } while (dataUser.House_number[i]);

        do
        {
            cout << "��� ����� ��������? ";
            cin >> dataUser.num;
            for (i = 0; i < dataUser.num[i]; i++)
            {
                if (!isdigit(dataUser.num[i]))
                {
                    cout << "����� �������� ���� ���� ����� �����!" << n <<
                        "���������� �� ���!" << n;;
                    break;
                }
                if (isdigit(dataUser.num[i]));
            }
        } while (dataUser.num[i]);

        ofstream out("users.dat", ios_base::binary | ios_base::app);
        cout << "ENTER LOGIN ";
        cin >> dataUser.login;
        cout << "ENTER PASSWORD";
        cin >> dataUser.password;
        out.close();
        cout << "���i�����i� ������� ���i��� " << dataUser.login << "!" << n;
    }
private:
};

void Selection_menu_output() 
{
    Reg_user reg_stud, reg_adm;

    int m = 0;
    cout << "�����i�� ���������� ����� ����" << n <<
        "�� �� ����� ����� � �������?" << n <<
        "1. ������������" << n << "2. ���i�i�������" << n;
    cin >> m;
    switch (m)
    {
    case 1: reg_stud.menu();
        break;
    case 2: reg_adm.login_adm();
        break;
    }
}

int main()
{
    setlocale(0, "");
    system("Color F0");

    Selection_menu_output();
}