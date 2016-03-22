// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Num{
	int num = 1;
	char *s = NULL;
};

Num word[99];

int Judge(char danci[])//判断单词
{
	bool j1 = (strlen(danci) >= 4);
	bool j2 = (danci[0] >= 'a' && danci[0] <= 'z');
	if (!(j1&&j2))
		return -1;
	else
	for (int ns = 1; danci[ns] != '\0';)
	{
		if (!((danci[ns] >= 'a' && danci[ns] <= 'z') || (danci[ns] >= '0' && danci[ns] <= '9')))
			return -1;
		else
			ns++;
	}
}
int Sta(char danci[], int nn)   //判断该单词是否出现过
{
	if (nn>0)
	for (int i = 0; i <nn; i++)
	{
		if (!strcmp(danci, word[i].s))  //出现
		{
			word[i].num++;      //+1
			return -1;
		}
	}
}
int main()
{
	char sentence[1000];//字符数组长度要足够大
	ifstream file("d://A_Tale_of_Two_Cities.txt");  
	ofstream outfile("d://Result1.txt");  //读取
	if (!file){
		cout << "Unable to open file";
		exit(1);
	}
	if (!outfile){
		cout << "Unable to open outmyfile";
		exit(1);
	}
	while (!file.eof())
	{
		file.getline(sentence, 1000);
	}
	file.close();
	int num2 = 0;
	while (sentence[num2] != '\0')//转小写
	{
		if (sentence[num2] >= 'A'&&sentence[num2] <= 'Z')
			sentence[num2] = sentence[num2] + 32;
		num2++;
	}
	const char *delim = " ,“”.''‘’!?";  //分隔符
	char *p,
		*pNext = NULL;
	int n = 0,     //计数器 n ,t 初始化
		t = 0;
	p = strtok_s(sentence, delim, &pNext);   //strtovk_s函数根据分隔符分隔字符串
	while (p)
	{
		if (Judge(p) != -1)
		{
			if (Sta(p, n) != -1)
			{
				word[n].s = p;
				n++;
			}
		}
		p = strtok_s(NULL, delim, &pNext);
	}

	while (word[t].s)        //输出统计结果
	{
		cout<< word[t].s << "：" << word[t].num << '\n';
		outfile<< word[t].s << "：" << word[t].num << '\n';
		t++;
}
	outfile.close();
	return 0;
}


