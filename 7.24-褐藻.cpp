#include<stdio.h>
int main()
{
	printf("���������3���������ж����Ƿ�Ϊ����\n");
	float a=0;
	scanf("%f",&a);
	int b=a,d=0,c=2;
	if(b=a){
	   if(a>3){
              do{d=b%c;
                 ++c;
                 if(d==0){
                   printf("no");
                   break;}
                 if(c==b-1){
                   printf("yes");
                   break;}
			  }while(c<b); 
	        }else printf("error");
	}else printf("error");
	return 0;
}
