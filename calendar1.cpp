// calendar1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<iomanip>
#include <math.h>
using namespace std;

int option;
int year, month, day;
int days_per_mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
string jan_to_dec[13] = { " ","一","二","三","四","五","六","七","八","九","十","十一","十二" };
string mon_to_sun[7] = { "日","一","二","三","四","五","六" };

void updateFeb(int year);
void showYear();
void showMonth();
void showDay();
void menu();

void updateFeb(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        days_per_mon[2] = 29;
    return;
}

void showYear()
{
    cout << "请输入年份：";
    cin >> year;
    cout << "\n";
   
    int days = 1;
    int s = year - 1 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + days;
    s %= 7;
    int k;
    cout << year << "年份的日历如下：\n";
    
    for (int y = 1; y <= 12; y++)
    {
        cout << setw(16) << jan_to_dec[y] << "月份的月历如下：\n";
        cout << setw(6) << "日" << setw(6) << "一" << setw(6) << "二" << setw(6) << "三" << setw(6) << "四" << setw(6) << "五" << setw(6) << "六\n";
        k = 0;
        while (k < s)
        {
            cout << setw(6) << " ";
            k++;
        }
        for (int j = 1; j <= days_per_mon[y]; j++)
        {
            cout << setw(6) << j;
            s = (s + 1) % 7;
            if (s == 0)
                cout << "\n";
        }
        cout << "\n";
        cout << "\n";
    }
    cout << "\n";
    cout << "按任意数字键返回主菜单：";
    cin >> k;
    system("cls");
    menu();

}
void showMonth()
{
    cout << "请输入年份：";
    cin >> year;
    cout << "\n";
    cout << "请输入月份：";
    cin >> month;
    cout << "\n";
    
    updateFeb(year);
    int days = 1;
    int i = 1;
    while (i < month)
    {
        days += days_per_mon[i];
        i++;
    }
    int s = year - 1 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + days;
    s %= 7;

    cout << month << "月份的月历如下：\n";
    cout << setw(6) << "日" << setw(6) << "一" << setw(6) << "二" << setw(6) << "三" << setw(6) << "四" << setw(6) << "五" << setw(6) << "六\n";

    int k = 0;
    while (k < s)
    {
        cout << setw(6) << " ";
        k++;
    }
    for (int j = 1; j <= days_per_mon[month]; j++)
    {
        cout << setw(6) << j;
        s = (s + 1) % 7;
        if (s == 0)
            cout << "\n";
    }
    cout << "\n";
    cout << "按任意数字键返回主菜单：";
    cin >> k;
    system("cls");
    menu();
}
void showDay()
{
    cout << "请输入年份：";
    cin >> year;
    cout << "\n";
    cout << "请输入月份：";
    cin >> month;
    cout << "\n";
    cout << "请输入日期：";
    cin >> day;
    cout << "\n";

    updateFeb(year);
    int days = day;
    int i = 1,k;
    while (i < month)
    {
        days += days_per_mon[i];
        i++;
    }
    int s = year - 1 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + days;
    s %= 7;
    cout << "这一天是星期" << mon_to_sun[s] << "\n";
    cout << "\n";
    cout << "按任意数字键返回主菜单：";
    cin >> k;
    system("cls");
    menu();
}

void menu()
{
    cout << "****************************************\n";
    cout << "             欢迎使用万年历             \n";
    cout << "          created by Holly Zhou         \n";
    cout << "****************************************\n";
    cout << "\n";
    cout << "操作键：\n";
    cout << "1、显示一年的年历\n";
    cout << "2、显示一月的月历\n";
    cout << "3、显示某一天是星期几\n";
    cout << "0、退出\n";
    cout << "\n";
    cout << "请输入操作键（0~3）：";

    cin >> option;

    if (option < 0 || option>3)
    {
        system("cls");
        cout << "****************************************\n";
        cout << "输入数字无效，请重新输入！\n" ;
        menu();
    }
}

int main()
{
    menu();

    while (option != 0)
    {
        switch (option)
        {
        case 1:showYear(); break;
        case 2:showMonth(); break;
        case 3:showDay(); break;
        }
        days_per_mon[2] = 28;
    }
    if (option == 0)
        system("pause");

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
