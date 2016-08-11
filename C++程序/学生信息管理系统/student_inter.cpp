#include "student.h"
#include <iostream>
#include <string>

using namespace std;

// student 实现部分

// 全局
string allmajor[10][6] = 
{
	"计算机与科学技术","软件工程","数字媒体","网络工程"," "," ",
	"财务管理","工程管理","市场营销","公共管理","会 计 学","国际经济与贸易",
	"法学专业","对外汉语"," "," "," "," ",
	"英语专业","日语专业"," "," "," "," ",
	"机械工程及自动化","交通工程","车辆工程","机械电子工程","热能与动力"," ",
	"微 电 子","光电信息",
	"测控技术","自 动 化","信息工程"," ",
	"统 计 学","大学物理","应用数学"," "," "," ",
	"会 计 学","财务管理"," "," "," "," ",
	"工业设计","艺术设计","服装设计与工程"," "," "," ",
	"化学工程","材料工程","环境工程","生物工程","应用化学","安全工程",
};

void student::show()
{
	cout << "学号：" << num << endl;
	cout << "姓名：" << name << endl;
	cout << "性别：";
	print_sex(sex);
	cout << endl << "年级：";
	print_grade(grade);
	cout << endl << "学院：";
	print_xueyuan(xueyuan);
	cout << endl << "专业：";
	print_major(xueyuan, major);
	print_class(clas);
	cout << endl;
}

void student::print_xueyuan(short int n)
{
	switch (n)
	{
	case 0 : cout << "计算机学院";		break;
	case 1 : cout << "商 学 院";		break;
	case 2 : cout << "文法学院";		break;
	case 3 : cout << "外国语学院";		break;
	case 4 : cout << "机车学院";		break;
	case 5 : cout << "信息学院";		break;
	case 6 : cout << "数理学院";		break;
	case 7 : cout << "金融学院";		break;
	case 8 : cout << "设计与艺术学院";	break;
	case 9 : cout << "化工与材料学院";	break;
	}
}

void student::print_grade(short int n)
{
	switch (n)
	{	
	case 1 : cout << "一年级";	break;
	case 2 : cout << "二年级";	break;
	case 3 : cout << "三年级";	break;
	case 4 : cout << "四年级";	break;
	}
}

void student::print_class(short int n)
{
	switch (n)
	{
	case 1 : cout << " 1 班";	break;
	case 2 : cout << " 2 班";	break;
	case 3 : cout << " 3 班";	break;
	case 4 : cout << " 4 班";	break;
	case 5 : cout << " 5 班";	break;
	case 6 : cout << " 6 班";	break;
	case 7 : cout << " 7 班";	break;
	case 8 : cout << " 8 班";	break;
	case 9 : cout << " 9 班";	break;
	}
}

void student::print_sex(short int n)
{
	if (n == 0) cout << "男";
	else if (n == 1) cout << "女";
}

void student::print_major(short int x, short int n)
{
	cout << allmajor[x][n-1];
}
