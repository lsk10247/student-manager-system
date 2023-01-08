// 学生成绩.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include "Manager.h"
using namespace std;

int input;
//若未读入数据。则无法进行其他操作
bool inisicalized;

void getNum(int,int);

int main()
{
    Manager* manager = new Manager();

    cout << "*********课程成绩管理与分析系统*********" << endl;
    cout << "*                                      *" << endl;
    cout << "*            1.读入课程成绩            *" << endl;
    cout << "*            2.浏览学生成绩            *" << endl;
    cout << "*            3.查询学生成绩            *" << endl;
    cout << "*            4.修改学生成绩            *" << endl;
    cout << "*            5.补录学生成绩            *" << endl;
    cout << "*            6.删除学生成绩            *" << endl;
    cout << "*            7.保存修改成绩            *" << endl;
    cout << "*            8.统计课程成绩            *" << endl;
    cout << "*            9.保存统计数据            *" << endl;
    cout << "*            0.退出操作系统            *" << endl;
    cout << "*                                      *" << endl;
    cout << "****************************************" << endl;
    
    while (true) {
        getNum(0,9);
        switch (input)
        {
        case 1:
            inisicalized = true;
            cout << "**************读入课程成绩**************" << endl;
            manager->insert();
            cout << "****************操作完成****************" << endl;
            break;
        case 2:
            cout << "**************浏览学生成绩**************" << endl;
            manager->brouse();
            cout << "****************操作完成****************" << endl;
            break;
        case 3:
            cout << "**************查询学生成绩**************" << endl;
            manager->search();
            cout << "****************操作完成****************" << endl;
            break;
        case 4:
            cout << "**************修改学生成绩**************" << endl;
            manager->change();
            cout << "****************操作完成****************" << endl;
            break;
        case 5:
            cout << "**************补录学生成绩**************" << endl;
            manager->append();
            cout << "****************操作完成****************" << endl;
            break;
        case 6:
            cout << "**************删除学生成绩**************" << endl;
            manager->remove();
            cout << "****************操作完成****************" << endl;
            break;
        case 7:
            cout << "**************保存修改成绩**************" << endl;
            manager->storage();
            cout << "****************操作完成****************" << endl;
            break;
        case 8:
            cout << "**************统计课程成绩**************" << endl;
            manager->analysize();
            cout << "****************操作完成****************" << endl;
            break;
        case 9:
            cout << "**************保存统计数据**************" << endl;
            manager->save();
            cout << "****************操作完成****************" << endl;
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "请输入0到9以内的数字。" << endl;
            break;
        }
    }


}

void getNum(int min,int max) {
    while (!(cin >> input) || (input<min || input>max) && !(max == 0))
    {
        while (getchar() != '\n');
        cin.clear();
        if (max != 0) {
            cout << "只能输入" << min << "~" << max << "之间的数，请重新输入！" << endl;
        }
        else {
            cout << "请输入数字！" << endl;
        }
    }
    if ((!inisicalized) && (input != 1)&&(input!=0)) {
        cout << "请先读入数据！" << endl;
        getNum(0,9);
    }
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
