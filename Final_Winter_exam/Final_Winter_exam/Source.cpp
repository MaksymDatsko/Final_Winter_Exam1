
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
        cout << "Введiть логiн ";
        cin >> userIn.login;
        cout << "Введiть пароль ";
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
        flag ? cout << "Ви успiшно зайшли в систему. " << userIn.login << "!\n"
            : cout << "Помилка, вам потрiбно попробовати ще раз\n";
        cout << n;
        int m = 0;
        cout << "Виберiть пункт" << n;
        cout << "1. Зробити i загрузити тест тестувальника." << n;
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
        cout << "Ввeдiть логiн ";
        cin >> userIn.login;
        cout << "Введiть пароль ";
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
        flag ? cout << "Ви успiшно зайшли в систему " << userIn.login << "!\n"
            : cout << "Помилка, вам потрiбно попробувати ще раз\n";
    }

    void menu()
    {
        cout << "Привiт, тестувальник!" << n;
        cout << "Щоб зайти нажмiть(y).Щоб зареєструватись  (n) ";
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
            cout << "Iмя тестувальника? ";
            cin >> dataUser.name;
            for (i = 0; dataUser.name[i]; i++)
            {
                if (dataUser.name[i] >= '0' && dataUser.name[i] <= '9')
                {
                    cout << "Iмя не може бути цифрами i з спеціальними знаками" << n <<
                        "Iмя може бути тiльки буквами англiйського алфавiту" << n
                        << "Будь ласка,повторiть!" << n;
                    break;
                }
                if (dataUser.name[i] >= 'Aa' && dataUser.name[i] <= 'Zz'
                    || dataUser.name[i] >= 'Аа' && dataUser.name[i] <= 'Яя');
            }
        } while (dataUser.name[i]);

        do
        {
            cout << "Назва вулицi? ";
            cin >> dataUser.adress;
            for (i = 0; dataUser.adress[i]; i++)
            {
                if (dataUser.adress[i] >= '0' && dataUser.adress[i] <= '9')
                {
                    cout << "В назвi вулицi мають бути тiльки букви" << n << "Повторiть спробу" << n;
                    break;
                }
            }   if (dataUser.adress[i] >= 'Aa' && dataUser.adress[i] <= 'Zz'
                || dataUser.adress[i] >= 'Аа' && dataUser.adress[i] <= 'Яя');
        } while (dataUser.adress[i]);

        do
        {
            cout << "Номер квартири? ";
            cin >> dataUser.House_number;
            for (i = 0; i < dataUser.House_number[i]; i++)
            {
                if (!isdigit(dataUser.House_number[i]))
                {
                    cout << "Номер квартири може мати тiльки цифри!" << n <<
                        "Попробуйте ще раз!" << n;;
                    break;
                }
                if (isdigit(dataUser.House_number[i]));
            }
        } while (dataUser.House_number[i]);

        do
        {
            cout << "Ваш номер телефону? ";
            cin >> dataUser.num;
            for (i = 0; i < dataUser.num[i]; i++)
            {
                if (!isdigit(dataUser.num[i]))
                {
                    cout << "Номер телефону може мати тільки цифри!" << n <<
                        "Попробуйте ще раз!" << n;;
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
        cout << "Регiстрацiя пройшла успiшно " << dataUser.login << "!" << n;
    }
private:
};

void Selection_menu_output() 
{
    Reg_user reg_stud, reg_adm;

    int m = 0;
    cout << "Виберiть необходний пункт меню" << n <<
        "Як ви хочет зайти в систему?" << n <<
        "1. Тестувальник" << n << "2. Адмiнiстратор" << n;
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