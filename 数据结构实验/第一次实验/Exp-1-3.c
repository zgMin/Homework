#include<stdio.h>
#include<stdlib.h>
void move(char A,char C)
//���A��C·�� 
{
	printf("%c--->%c\n",A,C); 
}
void digui(int n,char A,char B,char C)
//�ݹ鷽����ÿ���ƶ�Ϊ��n�����Ӵӵڶ��������������ĸ����� 
{
	if(n==1) move(A,C);
	else{
		//n-1��A->B 
		digui(n-1,A,C,B);
		//��n��A->C
		move(A,C);
		//n-1��B->C
		digui(n-1,B,A,C); 
	}
}
void feidigui(int n)
//�ǵݹ鷽�� 
{
	int sum=(1<<n)-1;
	int cnt,i,t,k;
	for(cnt=1;cnt<=sum;cnt++){ //���ƶ��������� 
		for(t=2,i=1;i<=n;i++,t*=2){ //������� ,t=2^i 
			if(cnt%t==t/2){	//�ҵ��ƶ����̺� 
				k=cnt/t;	//��i���̵ĵ�k���ƶ�
				if(n%2==i%2){	//��ż��ͬ����ʱ�� 
					if( (k+1)%3 == 0 ) move('B','A');
					if( (k+1)%3 == 1 ) move('A','C');
					if( (k+1)%3 == 2 ) move('C','B');
				} 
				else{	//��ż��ͬ��˳ʱ�� 
					if( (k+1)%3 == 0 ) move('C','A');
					if( (k+1)%3 == 1 ) move('A','B');
					if( (k+1)%3 == 2 ) move('B','C');
				}
				break; 
			} 
		}
	} 
}
int main(){
	int n;
	scanf("%d",&n);
	//digui(n,'A','B','C');
	feidigui(n);
	return 0;
} 
