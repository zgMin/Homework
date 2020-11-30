/*
	用二分法
	在一个有序整数序列中，查找用户给定的整数，并给出结果
	若找到相同数值给出其在序列中的位置，若未找到相同数字显示“无匹配项”（“No matchs”）的提示信息。
*/ 
#include<stdio.h>
int binary_search(int L[],int left,int right,int key){//key是否在L中，在返回下标，不在返回-1 
	while(left<=right){
		int mid=(left+right)>>1;
		if(key==L[mid])
			return mid;
		else if(key>L[mid])
			left=mid+1;
		else if(key<L[mid])
			right=mid-1;
	}
	return -1;
}
int main(){
	int L[11],key;
	printf("请输入10个有序整数：");
	for(int i=1;i<=10;i++)
		scanf("%d",&L[i]);
	printf("请输入待查找整数：");
	scanf("%d",&key);
	int pos=binary_search(L,1,10,key);
	if(pos==-1)
		printf("No matchs\n");
	else
		printf("在序列中的下标位置为%d\n",pos); 
	return 0;
} 
