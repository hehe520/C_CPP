#include <iostream>
#include <string>

using namespace std;

class ui;
class file;
struct student;

const int BUFFER_SIZE = 500;	// 读写缓冲区大小
const int MAXPATH = 150;		// 路径大小

// 界面颜色
typedef 
	enum {green, blue, red, purple, yellow, white} 
color;


// ------------------文件操作类------------------

class file
{
public:
	file::file();
	file::~file();
	bool copyfile(string &oldpath, string &newpath);	// 复制
	bool cutfile(string &oldpath, string &newpath);		// 剪切 
	bool fileexist(string &path);					// 判断文件存在
	bool deletefile(string &path);					// 删除文件
	bool newname(string &oldpath, string &name);	// 重命名
	static void writetext(char *text);			// 记录函数
	string getpath();		// 获得当前路径
	string getdir();		// 获得当前目录
private:
	string filepath(void);	// 返回文件路径
	string directory(void);	// 返回所在目录路径
	string filepaths;		// 记录路径
	string filedir;			// 记录目录
};


// ------------------界面显示类------------------

class ui
{
public:
	ui::ui();
	ui::~ui();
	void display();		// 主界面
	int wait();			// 等待操作
protected:
	void exe_create();		// 新增
	void exe_update();		// 修改
	void exe_remove();		// 删除
	void exe_find();		// 查询
	void exe_show();		// 查看
	void exe_set();			// 设置
	void exe_backup();		// 备份
private:
	// strtochar 不通过对象调用，则要设成静态的
	static void strtochar(string &s, char *buf);
	friend file;
	void show_major(short int n, int &a, int &b);
	bool write_student_data(student *addr, string &path);
	int find(student *addr, char *s);
	int findnum(char *s);		// 查找颜色值
	void setcolor(int num);		// 设置颜色
	int check(int a, int b);	// 检查输入
	string checkname();			// 检查名字
	string checknum();			// 检查学号
	void print(int n);			// 输出下划线
	int  getnum(string &str);	// str转int
	inline void back();			// 回主界面
	inline void clear();		// 清屏
	void showxueyuan();			// 显示学院
	void allmajor(short int n);	// 全部专业
	string filename;			// 文件名
	string stu_path;			// 数据路径
	string set_path;			// INI路径
	string dir;					// 目录
	student *addr;				// 保存数据地址
	int cur;					// 已用个数
};


// -----------------学生信息结点-----------------
// 如果类中有 string 必须使用 new 创建
// malloc 只是分配一块空间，不进行构造操作
struct student
{
public:
	char num[20];		// 学号
	char name[20];		// 姓名
	short int sex;		// 性别	
	short int xueyuan;	// 学院代号
	short int major;	// 专业代号
	short int grade;	// 年级
	short int clas;		// 班级
	bool used;			// 删除标记

	void show();		// 输出
	void print_xueyuan(short int n);
	void print_major(short int x, short int n);
	void print_grade(short int n);
	void print_class(short int n);
	void print_sex(short int n);
};
