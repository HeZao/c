#include<stdio.h>
int main(){
    printf("�������ַ����Լ������С�a���롰d���ĸ���\n");
	int a=0,b=0,c=0;
	char str[10000];
	gets(str);
	for(;a<sizeof(str)/sizeof(char);a++){
		if(str[a]=='a')
		   b++;
		if(str[a]=='d')
		   c++;
	}
	printf("a:%d,d:%d",b,c);
	return 0;
}
