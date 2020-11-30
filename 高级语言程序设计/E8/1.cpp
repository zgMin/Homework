/*
	统计多行输入的字符串长度，
	并将统计结果以升序方式列出，
	以水平柱状图的形式显示出来。
*/
#include<stdio.h>
#include<string.h>
int	biao[100];
int main(){
	char s[100];
	int Lmax=0;
	while(scanf("%s", s) != EOF){
		int L=strlen(s);
		Lmax=Lmax<L?L:Lmax;
		biao[L]++;
	}
	printf("length\tNumber\tGraphic\n＝＝＝＝＝＝＝＝＝＝＝＝\n");
	for(int i=1;i<=Lmax;i++){
		if(biao[i]){
			printf("%d\t%d\t",i,biao[i]);
			for(int j=1;j<=biao[i];j++){
				printf("■");
			}
			printf("\n");
		}
	}
	return 0;
} 
