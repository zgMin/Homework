/*
	目标杆为：A，目的杆为 B，辅助杆为：C
	利用递归程序
	将 N 块汉诺塔盘片从 A 搬动至 B 的步骤显示出来。
*/
#include<stdio.h>

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
int main(){
	int n;
	scanf("%d",&n);
	digui(n,'A','C','B');
	return 0;
} 
