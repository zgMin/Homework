#include<stdio.h>
#include<stdlib.h>
void move(char A,char C)
//输出A到C路径 
{
	printf("%c--->%c\n",A,C); 
}
void digui(int n,char A,char B,char C)
//递归方法，每次移动为把n个盘子从第二个参数移至第四个参数 
{
	if(n==1) move(A,C);
	else{
		//n-1个A->B 
		digui(n-1,A,C,B);
		//第n个A->C
		move(A,C);
		//n-1个B->C
		digui(n-1,B,A,C); 
	}
}
void feidigui(int n)
//非递归方法 
{
	int sum=(1<<n)-1;
	int cnt,i,t,k;
	for(cnt=1;cnt<=sum;cnt++){ //按移动次数遍历 
		for(t=2,i=1;i<=n;i++,t*=2){ //遍历标号 ,t=2^i 
			if(cnt%t==t/2){	//找到移动的盘号 
				k=cnt/t;	//第i号盘的第k次移动
				if(n%2==i%2){	//奇偶相同，逆时针 
					if( (k+1)%3 == 0 ) move('B','A');
					if( (k+1)%3 == 1 ) move('A','C');
					if( (k+1)%3 == 2 ) move('C','B');
				} 
				else{	//奇偶不同，顺时针 
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
