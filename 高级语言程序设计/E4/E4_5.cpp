/*
	打印最长行为n的菱形 
*/
#include<stdio.h>
int main(){
	int n,ctr=0;//ctr控制奇数偶数的不同 
	scanf("%d",&n);
	if(n%2==0)
		ctr=-1;
	//图中元素只有空格和星号，且为上下对称
	//对于上半部分，第i行的空格数为(n+1)/2-i，m星号数为2i-1
	//中间行满足，2i-1=n，即i=(n+1)/2
	for(int i=1;i<=(n+1)/2;i++){
		//output kongge
		for(int j=1;j<=(n+1)/2-i;j++){
			printf(" ");
		}
		//end
		//output star
		for(int j=1;j<=2*i-1;j++){
			printf("*");
		}
		//end
		printf("\n"); 
	} 
	//对于下半部分，第i行空格数为i-(n+1)/2+ctr，星号数 2n-2i+1
	 for(int i=(n+1)/2+1;i<=n;i++){
		//output kongge
		for(int j=1;j<=i-(n+1)/2+ctr;j++){
			printf(" ");
		}
		//end
		//output star
		for(int j=1;j<=2*n-2*i+1;j++){
			printf("*");
		}
		//end
		printf("\n"); 
	} 
	return 0;
} 
