//�����������֣��������ߺ���С�� 
#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int max,min;
	if(a<b){
		max=b,min=a;
		if(b<c){
			max=c;
		}else if(a>c){
			min=c;
		}
	}else{
		max=a,min=b;
		if(a<c){
			max=c;
		}else if(b>c){
			min=c;
		}
	}
	printf("����ߣ�%d    ��С�ߣ�%d\n",max,min);
	return 0;
} 
