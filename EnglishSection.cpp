//EnglishSection.h
#pragma once
#include <string>
using namespace std;
/*
1.输入一段英文短文，计算单词数，并把最长、最短的单词输出，要求用英文短文用类CEnglishSection实现短文处理的功能；
*/

class CEnglishSection
{
private:
	string strPara;
	int num;
	string maxWord;
	string minWord;

private:
	void Process();
public:
	CEnglishSection(void);
	~CEnglishSection(void);

	void Input(string paragraph);
	int GetNumWords();
	string GetMaxWord();
	string GetMinWord();

};


//fun.h
#pragma once
#include"EnglishSection.h"
inline void CEnglishSection::Input(string paragraph)//将字符串复制入类
{
	strPara = paragraph;
}
inline CEnglishSection::CEnglishSection(void)
{
	num = 0;//赋初值
}
inline CEnglishSection::~CEnglishSection(void)
{
}
int CEnglishSection::GetNumWords()//计数
{
	int size = strPara.size();
	for (int i = 0; i <=size; i++)
		if (strPara[i] == ' ' || strPara[i] == '\0')//遇到空格和字符串末尾+1
		{
			num++;
			if (strPara[i] == ',' || strPara[i] == '.' || strPara[i] == '!' || strPara[i] == ';')//顺便替换标点
				strPara[i] = ' ';
		}
	return num;
}
inline void CEnglishSection::Process()
{
	string tem;
	minWord.resize(20);//放大内存
	int size = strPara.size(),i,j=0;
	for (i = 0; i <= size; i++)
	{
		if (strPara[i] != ' ' && strPara[i] != '\0')//单词未结束
		{
			tem.resize(++j);//重新分配空间
			tem[j-1] = strPara[i];//复制字母
		}
		else
		{
			if (maxWord.size() < j)//已有最大单词长度小于当前单词
			{
				maxWord.resize(j);
				maxWord = tem;
			}
			if (minWord.size() > j)//已有最小单词长度大于当前单词
			{
				minWord.resize(j);
				minWord = tem;
			}
			tem.clear();//清空临时单词
			j = 0;//复位
		}
	}
}
inline string CEnglishSection::GetMaxWord()
{
	Process();
	return string(maxWord);
}
inline string CEnglishSection::GetMinWord()
{
	return string(minWord);
}


//CEnglishSection.cpp
#include<iostream>
#include<string>
#include "EnglishSection.h"
#include"fun.h"

using namespace std;

int main()
{
	CEnglishSection es;
	string str;
	//英文标点后须有空格
	str = "There are moments in life when you miss someone so much that you just want to pick them from your dreams and hug them for real! Dream what you want to dream; go where you want to go; be what you want to be, because you have only one life and one chance to do all the things you want to do.";

	es.Input(str);
	cout << str << endl << endl;
	cout << "total number of words in paragraph:" << es.GetNumWords() << endl;
	cout << "maximum word:" << es.GetMaxWord() << endl;
	cout << "minimum word:" << es.GetMinWord() << endl;
	return 0;
}
