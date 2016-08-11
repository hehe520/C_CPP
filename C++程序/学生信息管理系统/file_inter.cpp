#include "student.h"
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// file 类实现部分

file::file()
{
	filepaths = filepath();
	if (filepaths[0] == '0') exit(0);

	filedir = directory();
	if (filedir[0] == '0') exit(0);
}

file::~file()
{
	// to be continued...
}

// 获得程序路径
string file::filepath(void)
{
	char buffer[MAX_PATH];

	if (GetModuleFileName(NULL, buffer, MAX_PATH))
	{
		string s = buffer;
		return s;
	}
	else return NULL;
}

// 获得程序目录
string file::directory(void)
{
	char buffer[MAX_PATH];

	if (GetCurrentDirectory(MAX_PATH, buffer))
	{
		string s = buffer;
		return s;
	}
	else return NULL;

}

string file::getpath()
{
	return filepaths;
}

string file::getdir()
{
	return filedir;
}

// 判断文件存在
bool file::fileexist(string &path)
{
	FILE *fp = NULL;
	char f[200];
	int i = 0;

	// string 转 char
	ui::strtochar(path, f);

	fp = fopen(f, "rb");
	if (fp)
	{
		fclose(fp);
		return true;
	}
	else return false;
}

// 复制 old 到 new
bool file::copyfile(string &oldpath, string &newpath)
{
	char c_old[MAXPATH] = {0};
	char c_new[MAXPATH] = {0};
	FILE *in = NULL;
	FILE *out = NULL;

	ui::strtochar(oldpath, c_old);   // 必须显示调用
	ui::strtochar(newpath, c_new);

	if (!fileexist(oldpath)) return false;
	in = fopen(c_old, "rb");
	if (in)
	{
		out = fopen(c_new, "wb");
		if (out)
		{
			// 读写缓冲区
			char buffer[BUFFER_SIZE];
			int an;

			// 开始复制
			while (1)
			{
				an = fread(buffer, 1, BUFFER_SIZE, in);
				if (an == 0) break;
				fwrite(buffer, 1, an, out);
			}
			fclose(out);
		}
		fclose(in);
	}
	return true;
}

// 删除文件
bool file::deletefile(string &path)
{
	if (fileexist(path))
	{
		char buf[MAXPATH] = {0};

		ui::strtochar(path, buf);
		remove(buf);
		return true;
	}
	return false;
}

// 剪切 old 到 new
bool file::cutfile(string &oldpath, string &newpath)
{
	if (copyfile(oldpath, newpath)) 
	{
		deletefile(oldpath);
		return true;
	}
	return false;
}

// 重命名
bool file::newname(string &oldpath, string &name)
{
	if (fileexist(oldpath))
	{
		char buf[MAXPATH] = {0};
		char dir[MAXPATH] = {0};	// 当前目录
		char n[50] = {0};
		int len = 0;

		ui::strtochar(oldpath, buf);
		ui::strtochar(oldpath, dir);
		ui::strtochar(name, n);

		// 提取目录
		while (dir[len] != '\0') len++;
		while (dir[len] != '\\')
		{
			dir[len] = '\0';
			len--;
		}
		
		// dir 加上新名字
		int len2 = 0;
		while (n[len2] != '\0')
		{
			dir[++len] = n[len2++];
		}
		
		if (rename(buf, dir)) return true;
	}
	return false;
}

void file::writetext(char *text)
{
	char buffer[MAX_PATH];

	// 获得目录
	if (GetCurrentDirectory(MAX_PATH, buffer))
	{
		int len = 0;
		int i = 0;
		char name[] = "\\recond.txt";
		while (buffer[len] != '\0') len++;
		while (name[i] != '\0')
			buffer[len++] = name[i++];
		buffer[len] = '\0';

		// 打开文件
		FILE *out = NULL;
		out = fopen(buffer, "a");
		if (out)
		{
			// 获得系统时间
			struct tm *tmp;
			time_t second;
			int h, m, s;
			time(&second);
			tmp = localtime(&second);
			h = tmp->tm_hour;
			m = tmp->tm_min;
			s = tmp->tm_sec;
			// 写入时间
			fprintf(out, "[%02d:%02d:%02d] ", h,m,s);
			// 写入事件
			fprintf(out, "%s\n", text);
			fclose(out);
		}
	}
}
