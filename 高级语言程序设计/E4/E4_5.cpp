/*
	��ӡ���Ϊn������ 
*/
#include<stdio.h>
int main(){
	int n,ctr=0;//ctr��������ż���Ĳ�ͬ 
	scanf("%d",&n);
	if(n%2==0)
		ctr=-1;
	//ͼ��Ԫ��ֻ�пո���Ǻţ���Ϊ���¶Գ�
	//�����ϰ벿�֣���i�еĿո���Ϊ(n+1)/2-i��m�Ǻ���Ϊ2i-1
	//�м������㣬2i-1=n����i=(n+1)/2
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
	//�����°벿�֣���i�пո���Ϊi-(n+1)/2+ctr���Ǻ��� 2n-2i+1
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
