#include<stdio.h>
int main(){
	printf("����һ�������ҳ�С�ڵ����������\n");
	float a;
	scanf("%f",&a);
	int b=a,c=2,d;
	if(b>=2){
	   int a=2;
	   do{d=a%c;
	      if(d==0&&a!=c){
	   	     a++;
	   	     c=2;
		               }
	      if(d!=0&&a!=c){
	   	     c++;
	   	               }     
	      if(a==c){
		     printf("%d,",a);
		     a++;
			 c=2;}	     
	}while(a<=b);
	}return 0;
}
