#include<stdlib.h>
#include<stdio.h>
int main(){
	printf("���������鳤��\n");
	int a=0,b,c,d,i;
	int *n;
	scanf("%d",&d);
	n=(int*)malloc(d*sizeof(int));
	printf("��������������(�����������á�,������)\n");
	for(i=0;i<d;i++)
	    scanf("%d",&n[i]);
	printf("������Ҫ���ҵ�����\n");
	scanf("%d",&b);
	d=d-1;
	while(a<d){
		c=(a+d)/2;
	    if(b<n[c])
	       d=c-1;
	    else if(b>n[c])
	       a=c+1;
	    else if(b==n[c]){
	       printf("Ҫ��������������λ��Ϊ%d",c+1);
	       break;
		}	
	}  
	return 0; 
}
