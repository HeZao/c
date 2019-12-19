//EnglishSection.h
#pragma once
#include <string>
using namespace std;
/*
1.����һ��Ӣ�Ķ��ģ����㵥���������������̵ĵ��������Ҫ����Ӣ�Ķ�������CEnglishSectionʵ�ֶ��Ĵ���Ĺ��ܣ�
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
inline void CEnglishSection::Input(string paragraph)//���ַ�����������
{
	strPara = paragraph;
}
inline CEnglishSection::CEnglishSection(void)
{
	num = 0;//����ֵ
}
inline CEnglishSection::~CEnglishSection(void)
{
}
int CEnglishSection::GetNumWords()//����
{
	int size = strPara.size();
	for (int i = 0; i <=size; i++)
		if (strPara[i] == ' ' || strPara[i] == '\0')//�����ո���ַ���ĩβ+1
		{
			num++;
			if (strPara[i] == ',' || strPara[i] == '.' || strPara[i] == '!' || strPara[i] == ';')//˳���滻���
				strPara[i] = ' ';
		}
	return num;
}
inline void CEnglishSection::Process()
{
	string tem;
	minWord.resize(20);//�Ŵ��ڴ�
	int size = strPara.size(),i,j=0;
	for (i = 0; i <= size; i++)
	{
		if (strPara[i] != ' ' && strPara[i] != '\0')//����δ����
		{
			tem.resize(++j);//���·���ռ�
			tem[j-1] = strPara[i];//������ĸ
		}
		else
		{
			if (maxWord.size() < j)//������󵥴ʳ���С�ڵ�ǰ����
			{
				maxWord.resize(j);
				maxWord = tem;
			}
			if (minWord.size() > j)//������С���ʳ��ȴ��ڵ�ǰ����
			{
				minWord.resize(j);
				minWord = tem;
			}
			tem.clear();//�����ʱ����
			j = 0;//��λ
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
	//Ӣ�ı������пո�
	str = "There are moments in life when you miss someone so much that you just want to pick them from your dreams and hug them for real! Dream what you want to dream; go where you want to go; be what you want to be, because you have only one life and one chance to do all the things you want to do.";

	es.Input(str);
	cout << str << endl << endl;
	cout << "total number of words in paragraph:" << es.GetNumWords() << endl;
	cout << "maximum word:" << es.GetMaxWord() << endl;
	cout << "minimum word:" << es.GetMinWord() << endl;
	return 0;
}
