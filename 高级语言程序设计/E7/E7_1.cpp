/*
	打印出10行杨辉三角形
*/ 
#include<stdio.h>
int tri[11][11];
int main(){
	//计算杨辉三角形 
	for(int i=1;i<=10;i++)
        tri[i][1] = tri[i][i] = 1;  //每行最开始和结束的数字均为1 
    for(int i=3;i<=10;i++)
        for(int j=2;j<=i-1;j++)
            tri[i][j]=tri[i-1][j-1]+tri[i-1][j];  //除两边的数外都等于上两顶数之和
    //end 
    //output
	for(int i=1;i<=10;i++){
		for(int j=1;j<=i;j++){
			printf("%-3d ",tri[i][j]);
		}
		printf("\n");//换行 
	}
	//end
	return 0;
} 
