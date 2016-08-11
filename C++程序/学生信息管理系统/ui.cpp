#include <iostream>
#include <string>
#include <stdlib.h>
#include "student.h"

using namespace std;

// ui 类实现部分

ui::ui()
{
	file f;
	FILE *fp = NULL;
	char buf[200];
	int i = 0;

	file::writetext("程序开始运行...");
	// 初始化成员
	addr = NULL;
	cur = 0;

	// 数据文件名 filename
	filename = "stu_data.dat";
	dir = f.getdir() + "\\";
	stu_path = dir + filename;
	strtochar(stu_path, buf);

	// 加载学生数据文件
	file::writetext("尝试加载数据文件 stu_data.dat");
	if (f.fileexist(stu_path))
	{
		// 存在数据文件
		// 获得文件大小
		fp = fopen(buf, "rb");
		if (!fp) goto NEXT;
		fseek(fp, 0, SEEK_END);
		int size = ftell(fp);
		int each = sizeof(student);
		rewind(fp);
		
		if (size)
		{
			// 建立数据空间
			cur = size / each;
			addr = (student *)malloc((cur+1) * sizeof(student));
			if (!addr) exit(0);
			
			// 开始读取到 addr
			fread(addr, each, cur, fp);
			fclose(fp);
			fp = NULL;
		}
		file::writetext("加载成功！");
	}
	else 
	{
NEXT:
		// 不存在,建立空文件
		fp = fopen(buf, "wb");
		fseek(fp, 0, SEEK_END);
		if (fp) fclose(fp);
		fp = NULL;
		file::writetext("加载失败，创建新 stu_path.dat");
	}

	// 加载皮肤颜色
	file::writetext("从 color.ini 中加载皮肤颜色");
	FILE *set = NULL;
	set_path = dir + "set.ini";
	strtochar(set_path, buf);
	if (f.fileexist(set_path))
	{
		// 读取颜色代号
		char buffer[MAXPATH] = {0};		// 缓冲区

		set = fopen(buf, "rb");
		if (!set) goto NO;
		int an = 1;
		while (an)
			an = fread(buffer, 1, 99, set);
		fclose(set);
		set = NULL;
		setcolor( findnum(buffer) );
		file::writetext("加载成功！");
	}
	else 
	{
NO:		// 使用默认颜色
		setcolor(-1);

		// INI文件记录
		fp = fopen(buf, "wt");
		if (fp) 
		{
			fprintf(fp, "[info]\ncolor=4\n");
			fclose(fp);
			fp = NULL;
		}
		file::writetext("加载失败，使用默认颜色");
	}
}

ui::~ui()
{
	// 将数据写回辅存中
	write_student_data(addr, stu_path);
	file::writetext("保存数据文件");

	// 释放高速缓存中的数据空间
	if (addr) free(addr);
	addr = NULL;
	file::writetext("程序结束！");
}

bool ui::write_student_data(student *addr, string &path)
{
	file f;
	char buf[MAXPATH] = {0};
	FILE *out = NULL;
	
	// 先改成stu_data.dat1
	string path1 = path + "1";
	f.newname(path, path1);

	// 写到 stu_data.dat
	strtochar(path, buf);
	out = fopen(buf, "wb");
	if (out)
	{
		int s = sizeof(student);
		for (int i=0; i<cur; i++)
		{
			if (addr[i].used)
				fwrite(&(addr[i]), 1, s, out);
		}
		fclose(out);
	}
	else
	{
		// 写入失败再改回来
		f.newname(path1, path);
		return false;
	}
	// 删除临时 studata.dat1
	f.deletefile(path1);
	return true;
}

// 设置颜色
void ui::setcolor(int num)
{
	switch (num)
	{
	case green : system("color 0A");
		break;
	case blue : system("color 0B");
		break;
	case red : system("color 0C");
		break;
	case purple : system("color 0D");
		break;
	case yellow : system("color 0E");
		break;
	case white : system("color 0F");
		break;
	default : system("color 0E");
	}
}

int ui::findnum(char *s)
{
	int i;
	int res;

	for (i=0; s[i]!='\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			sscanf(s+i, "%d", &res);
			return res;
		}
	}
	return -1;
}

// string 转 char
void ui::strtochar(string &s, char *buf)
{
	int i = 0;

	if (!buf) return ;
	while (s[i] != '\0')
		buf[i++] = s[i];
	buf[i] = '\0';
}

void ui::print(int n)
{
	if (n>0)
	{
		for (int i=0; i<n; i++)
			cout << "-";
	}
}

void ui::clear()
{
	system("cls");
}

void ui::back()
{
	fflush(stdin);
	cout << endl << endl;
	print(3);
	cout << " 按下回车键，回主界面" << endl;
	getchar();
	clear();
	display();
}

void ui::display()
{
	cout << endl;
	print(25);
	cout << "学生信息管理系统";
	print(25);
	cout << endl << endl;

	print(3);
	cout << " 1, 新增学生信息";
	cout << "     2, 修改学生信息";
	cout << "     3, 删除学生信息";
	cout << endl << endl;
	print(3);
	cout << " 4, 查询学生信息";
	cout << "     5, 查看所有学生信息";
	cout << endl << endl;

	print(3);
	cout << " 6, 系统设置";
	cout << "         7, 备份 / 载入学生数据文件";
	cout << endl << endl << endl;

	print(3);
	cout << " 0. 保存并退出" << endl << endl;
	print(3);
	cout << " 请选择要执行的操作：";
}

int ui::getnum(string &str)
{
	if (str.length() == 1 
		&& str[0] >= '0' 
		&& str[0] <= '9')
	{
		return str[0] - '0';
	}
	else 
		return -1;
}

int ui::wait()
{
	string str;
	int op;
	
	file::writetext("等待用户操作...");
	while (1)
	{
		cin >> str;
		fflush(stdin);
		op = getnum(str);
		if (op>=0 && op<=7)
		{
			switch (op)
			{
			case 1 : exe_create();	break;
			case 2 : exe_update();	break;
			case 3 : exe_remove();	break;
			case 4 : exe_find();	break;
			case 5 : exe_show();	break;
			case 6 : exe_set();		break;
			case 7 : exe_backup();	break;
			case 0 : return 0;
			}
		}
		else printf("XXX 输入错误，请重新输入：");
	}
}

int ui::check(int a, int b)
{
	while (1)
	{
		string buf;
		cin >> buf;
		if (buf.length() == 1) 
			if (buf[0]-'0' >= a && buf[0]-'0' <= b)
			{
				fflush(stdin);
				return buf[0] - '0';
			}
		cout << "XXX 输入错误，请重新输入：";
	}
}

void ui::allmajor(short int n)
{
	switch (n)
	{
	case 0 : 
		cout << "1. 计算机与科学技术   2. 软件工程   3. 数字媒体   4. 网络工程";
		cout << endl;
		break;
	case 1 : 
		cout << "1. 财务管理   2. 工程管理   3. 市场营销   4. 公共管理";
		cout << endl;
		cout << "5. 会计学     6. 国际经济与贸易" << endl;
		break;
	case 2 : 
		cout << "1. 法学专业   2. 对外汉语" << endl;
		break;
	case 3 : 
		cout << "1. 英语专业   2. 日语专业" << endl;
		break;
	case 4 : 
		cout << "1. 机械工程及自动化   2. 交通工程   3. 车辆工程" << endl;
		cout << "4. 机械电子工程       5. 热能与动力" << endl;
		break;
	case 5 : 
		cout << "1. 电子科学技术(微电子方向)   2. 电子科学技术(光电信息方向)";
		cout << endl;
		cout << "3. 测控技术     4. 自动化     5. 信息工程" << endl;
		break;			 
	case 6 : 
		cout << "1. 统计学   2. 大学物理   3. 应用数学" << endl;
		break;
	case 7 : 
		cout << "1. 会计学   2. 财务管理" << endl;
		break;
	case 8 : 
		cout << "1. 工业设计   2. 艺术设计   3. 服装设计与工程" << endl;
		break;
	case 9 : 
		cout << "1. 化学工程   2. 材料工程   3. 环境工程" << endl;
		cout << "4. 生物工程   5. 应用化学   6. 安全工程" << endl;
		break;
	}
}

// 输出专业
void ui::show_major(short int n, int &a, int &b)
{
	a = 1;
	switch (n)
	{
	case 0 : 
		allmajor(0);  b = 4;  break;
	case 1 : 
		allmajor(1);  b = 6;  break;
	case 2 : 
		allmajor(2);  b = 2;  break;
	case 3 : 
		allmajor(3);  b = 2;  break;
	case 4 : 
		allmajor(4);  b = 5;  break;
	case 5 : 
		allmajor(5);  b = 5;  break;			 
	case 6 : 
		allmajor(6);  b = 3;  break;
	case 7 : 
		allmajor(7);  b = 2;  break;
	case 8 : 
		allmajor(8);  b = 3;  break;
	case 9 : 
		allmajor(9);  b = 6;  break;
	}
	fflush(stdin);
}

// 显示全部学院
void ui::showxueyuan()
{
	cout << "0. 计算机学院   1. 商学院     2. 文法学院   3. 外国语学院" << endl;
	cout << "4. 机车学院     5. 信息学院   6. 数理学院   7. 金融学院" << endl;
	cout << "8. 设计与艺术学院             9. 化工与材料学院" << endl << endl;
}

string ui::checkname()
{
	string tmp;

	while (1)
	{
		cin >> tmp;
		int len = tmp.length();
		if (len < 10)
		{
			if (len >= 4)
			{
				int error = 0;
				for (int i=0; i<len; i++)
				{
					// 只能有英文和汉字
					if (tmp[i] < 0) continue;
					if (!((tmp[i] >= 'a' && tmp[i] <= 'z') 
						|| (tmp[i] >= 'A' && tmp[i] <= 'Z')))
					{
						error = 1;
						break;
					}
				}
				if (error) cout << "XXX 名字中含有非法字符";
				else break;
			}
			else cout << "XXX 错误: 名字过短";
		}
		else cout << "XXX 错误: 名字过长";
		cout << "，请重新输入：";
	}
	return tmp;
}

string ui::checknum()
{
	string tmp;

	while (1)
	{
		cin >> tmp;
		int len = tmp.length();
		if (len == 12)
		{		
			int error = 0;
			for (int i=0; i<len; i++)
			{
				// 只能有数字
				if (!(tmp[i] >= '0' && tmp[i] <= '9'))
				{
					error = 1;
					break;
				}
			}
			if (error) cout << "XXX 学号中含有非法字符";
			else
			{
				// 检查相同学号
				error = 0;
				for (i=0; i<cur; i++)
				{
					char buf[15] = {0};
					strtochar(tmp, buf);
					if (strcmp(buf, addr[i].num) == 0)
					{
						error = 1;
						break;
					}
				}
				if (error) cout << "XXX 该学号已使用";
				else break;
			}
		}
		else cout << "XXX 学号位数错误(12位)";
		cout << "，请重新输入：";
	}
	return tmp;
}

void ui::exe_create()	// 新增
{
	student *n;

	clear();
	// 扩大空间存放数据, 一般多申请一些
	// 申请太小，释放的时候出现各种奇怪错误
	if (addr)
	{
		n = (student *)realloc(addr, 
			(cur+2) * sizeof(student));
		if (!n) exit(0);
		addr[cur].used = false;
		addr[cur+1].used = false;
		cur++;
		addr = n;
	}
	else 
	{
		addr = (student *)malloc(sizeof(student));
		if (!addr) exit(0);
		cur = 1;
	}
	file::writetext("新增学生信息");
	cout << endl;
	print(3);
	cout << " 新增学生数据:" << endl << endl;
	cout << "请输入学生姓名：";
	string tmp;
	tmp = checkname();
	strtochar(tmp, addr[cur-1].name);
	
	cout << endl;
	cout << "请输入学号：";
	fflush(stdin);
	string tmp2;
	tmp2 = checknum();
	strtochar(tmp2, addr[cur-1].num);

	cout << endl;
	cout << "0. 男    1. 女" << endl << endl;
	print(3);
	cout << " 请输入性别：";
	addr[cur-1].sex = check(0, 1);

	cout << endl;
	showxueyuan();
	print(3);
	cout << " 请输入学院代号：";
	addr[cur-1].xueyuan = check(0, 9);

	cout << endl;
	int a, b;
	show_major(addr[cur-1].xueyuan, a, b);
	cout << endl << "请输入专业代号：";
	addr[cur-1].major = check(a, b);

	cout << endl;
	print(3);
	cout << " 请输入年级(1 到 4)：";
	addr[cur-1].grade = check(1, 4);

	cout << endl;
	print(3);
	cout << " 请输入班级代号(1 到 9)：";
	addr[cur-1].clas = check(1, 9);

	addr[cur-1].used = true;	// 删除标记
	cout << endl << "保存成功！";
	back();
}

int ui::find(student *addr, char *s)
{
	int pos = -1;

	for (int i=0; i<cur; i++)
	{
		if (!strcmp(s, addr[i].num))
		{
			pos = i;
			break;
		}
	}
	return pos;
}

void ui::exe_update()	// 修改
{
	clear();
	file::writetext("修改学生信息");
	cout << endl;
	print(3);
	if (cur == 0)
		cout << "没有学生数据，无法修改" << endl;
	else
	{
		cout << " 修改学生数据:" << endl << endl;
		print(3);
		cout << " 返回主界面输入 0 " << endl << endl;
		print(3);
		cout << " 请输入待修改学生学号：";
		char s[20];
INPUT:
		cin >> s;
		if (s[0] == '0' && s[1] == '\0') goto BACK;
		int pos = find(addr, s);
		if (pos == -1) 
		{
			cout << endl << "找不到该学生，请重新输入：";
			goto INPUT;
		}
		else
		{
			cout << endl;
			addr[pos].show();
			cout << endl;
			cout << "1. 姓名   2. 性别   3. 年级   4. 班级";
			cout << endl << "5. 学院   6. 专业   7. 全部修改";
			cout << endl << endl;;
			print(3);
			cout << " 请问要修改：";
			int op;
			string str;
			string tmp;
			while (1)
			{
				cin >> str;
				fflush(stdin);
				op = getnum(str);
				if (op>=1 && op <= 7)
				{
					switch (op)
					{
					case 7 : 
					case 1 : 
						cout << endl;
						print(3);
						cout << " 请输入新姓名：";
						tmp = checkname();
						strtochar(tmp, addr[pos].name);
						fflush(stdin);
						if (op != 7)
						{
							cout << endl << "修改成功！" << endl;
							goto BACK;
						}
					case 2 :
						cout << endl;
						cout << "0. 男    1. 女" << endl << endl;
						print(3);
						cout << " 请输入新性别：";
						addr[pos].sex = check(0, 1);
						if (op != 7)
						{
							cout << endl << "修改成功！" << endl;
							goto BACK;
						}
					case 3:
						cout << endl;
						print(3);
						cout << " 请输入年级(1 到 4)：";
						addr[pos].grade = check(1, 4);
						if (op != 7)
						{
							cout << endl << "修改成功！" << endl;
							goto BACK;
						}
					case 4:
						cout << endl;
						print(3);
						cout << " 请输入班级代号(1 到 9)：";
						addr[pos].clas = check(1, 9);
						if (op != 7)
						{
							cout << endl << "修改成功！" << endl;
							goto BACK;
						}
					case 5:
						cout << endl;
						showxueyuan();
						print(3);
						cout << " 请输入学院代号：";
						addr[pos].xueyuan = check(0, 9);
						if (op != 7)
						{
							cout << endl << "修改成功！" << endl;
							goto BACK;
						}
					case 6:
						cout << endl;
						int a, b;
						show_major(addr[pos].xueyuan, a, b);
						cout << endl << "请输入专业代号：";
						addr[pos].major = check(a, b);
						if (op != 7)
						{
							cout << endl << "修改成功！" << endl;
							goto BACK;
						}
					default : 
						if (op == 7)
						{
							cout << endl << "修改成功！" << endl;
							goto BACK;
						}
					}
				}
				else cout << "XXX 输入错误，请重新输入：";
			}
			file::writetext("修改成功！");
		}
	}
BACK:
	back();
}

void ui::exe_remove()	// 删除
{
	clear();
	file::writetext("删除学生信息");
	cout << endl;
	print(3);
	if (cur == 0)
		cout << "没有学生数据，无法删除" << endl;
	else
	{
		cout << " 删除学生数据:" << endl << endl;
		print(3);
		cout << " 返回主界面输入 0 " << endl << endl;
		print(3);
		cout << " 请输入待删除学生学号：";
		char s[20];
DEL_INPUT:
		cin >> s;
		if (s[0] == '0' && s[1] == '\0') goto DEL_BACK;
		int pos = find(addr, s);
		if (pos == -1) 
		{
			cout << endl << "找不到该学生，请重新输入：";
			goto DEL_INPUT;
		}
		else 
		{
			addr[pos].used = false;
			cout << endl <<"删除成功！" << endl;
		}
	}
DEL_BACK:
	back();
}

void ui::exe_find()		// 查询
{
	clear();
	file::writetext("查询学生信息");
	cout << endl;
	print(3);
	if (cur == 0)
		cout << "没有该学号，无法查询" << endl;
	else
	{
		cout << " 查询学生数据:" << endl << endl;
		print(3);
		cout << " 返回主界面输入 0 " << endl << endl;
		print(3);
		cout << " 请输入待查询学生学号：";
		char s[20];
FIND_INPUT:
		cin >> s;
		if (s[0] == '0' && s[1] == '\0') goto FIND_BACK;
		int pos = find(addr, s);
		if (pos == -1) 
		{
			cout << endl << "找不到该学生，请重新输入：";
			goto FIND_INPUT;
		}
		else 
		{
			cout << endl << "该学生信息：" << endl << endl;
			addr[pos].show();
		}
	}
FIND_BACK:
	back();
}

void ui::exe_show()		// 查看
{
	clear();
	file::writetext("查看学生信息");
	cout << endl;
	print(3);
	if (cur == 0)
		cout << "没有学生数据，无法查看" << endl;
	else
	{
		cout << " 全部学生数据:" << endl << endl;
		cout << "学号\t\t姓名\t性别\t年级\t学院\t\t专业\t      班级";
		cout << endl;
		print(79);
		cout << endl;
		for (int i=0; i<cur; i++)
		{
			if (addr[i].used)
			{
				cout << addr[i].num << "\t" << addr[i].name << "\t";
				addr[i].print_sex(addr[i].sex);
				cout << "\t";
				addr[i].print_grade(addr[i].grade);
				cout << "\t";
				addr[i].print_xueyuan(addr[i].xueyuan);
				cout << "\t";
				addr[i].print_major(addr[i].xueyuan, addr[i].major);
				cout << "     ";
				addr[i].print_class(addr[i].clas);
				cout << endl;
			}
		}
	}
	back();
}

void ui::exe_set()		// 设置
{
	clear();
	file::writetext("设置颜色");
	cout << endl;
	print(3);
	cout << " 系统设置：" << endl << endl;
	cout << "1. 绿色   2. 蓝色   3. 红色   4. 紫色   5. 黄色   6. 白色";
	cout << endl << endl;
	cout << "设置界面颜色：";
	string str;
	int op;
	while (1)
	{
		fflush(stdin);
		cin >> str;
		op = getnum(str);
		if (op >= 1 && op <= 6)
		{
			switch (op)
			{
			case 1 : setcolor(0); break;
			case 2 : setcolor(1); break;
			case 3 : setcolor(2); break;
			case 4 : setcolor(3); break;
			case 5 : setcolor(4); break;
			case 6 : setcolor(5); break;
			}
			// 写入 INI 文件
			char buf[MAXPATH];
			strtochar(set_path, buf);
			FILE *fp = NULL;
			fp = fopen(buf, "wt");
			if (fp) 
			{
				fprintf(fp, "[info]\ncolor=%d\n", op-1);
				fclose(fp);
				fp = NULL;
			}
			cout << endl << "设置成功！" << endl;
			break;
		}
		else cout << "XXX 输入错误，请重新输入：";
	}
	back();
}

void ui::exe_backup()	// 备份
{
	clear();

	// 把数据写回到辅存中,准备备份
	write_student_data(addr, stu_path);

	// 开始
	file::writetext("开始备份数据文件");
	cout << endl;
	cout << "1. 备份学生数据文件到...    2. 载入新的学生数据文件" << endl << endl;
	print(3);
	cout << " 请选择要执行的操作：";
	int op;
	string str;
	int len = 0, i = 0;
	while (1)
	{
		cin >> str;
		fflush(stdin);
		op = getnum(str);
		if (op>=1 && op <= 2)
		{
			string newpath;
			file copy;
			switch (op)
			{
			case 1 : 
				cout << endl;
				print(3);
				cout << " 请输入新路径：(如：c:\\student\\)";
				cin >> newpath;
				// 接上文件名
				newpath += filename;

				// 开始复制
				if (copy.copyfile(stu_path, newpath))
				{
					cout << endl << "备份成功！" << endl;
					file::writetext("备份成功！");
				}
				else 
				{
					cout << endl << "备份失败！" << endl;
					file::writetext("备份失败");
				}
				goto BACK2;
			case 2 : 
				file::writetext("开始还原数据文件");
				cout << endl;
				cout << "注意：此操作将会覆盖原有的数据!" << endl << endl;
				print(3);
				cout << " 请输入学生数据文件的路径：(如：c:\\student\\stu.dat)";
				cout << endl;
				cin >> newpath;
				if (copy.fileexist(newpath))
				{
					copy.deletefile(stu_path);
					copy.copyfile(newpath, stu_path);
					copy.newname(stu_path, filename);

					// 刷新内存中的数据
					FILE *fp = NULL;
					char buf[MAXPATH] = {0};
					strtochar(stu_path, buf);

					if (addr) free(addr);
					fp = fopen(buf, "rb");
					if (!fp) goto NEXT2;
					fseek(fp, 0, SEEK_END);
					int size = ftell(fp);
					int each = sizeof(student);
					rewind(fp);
					if (size)
					{
						// 建立数据空间
						cur = size / each;
						addr = (student *)malloc((cur+1) * sizeof(student));
						if (!addr) exit(0);
						
						// 开始读取到 addr
						fread(addr, each, cur, fp);
						fclose(fp);
						fp = NULL;
					}				
					cout << endl << "载入成功！" << endl;
					file::writetext("载入成功！");
				}
				else
				{
NEXT2:
					cout << endl << "载入失败！找不到 "<< newpath << endl;
					file::writetext("加载失败，找不到数据文件");
				}
				goto BACK2;
			}
		}
		else cout << "XXX 输入错误，请重新输入："; 
	}
BACK2:
	back();
}
