/*
	�ö��ַ�
	��һ���������������У������û����������������������
	���ҵ���ͬ��ֵ�������������е�λ�ã���δ�ҵ���ͬ������ʾ����ƥ�������No matchs��������ʾ��Ϣ��
*/ 
#include<stdio.h>
int binary_search(int L[],int left,int right,int key){//key�Ƿ���L�У��ڷ����±꣬���ڷ���-1 
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
	printf("������10������������");
	for(int i=1;i<=10;i++)
		scanf("%d",&L[i]);
	printf("�����������������");
	scanf("%d",&key);
	int pos=binary_search(L,1,10,key);
	if(pos==-1)
		printf("No matchs\n");
	else
		printf("�������е��±�λ��Ϊ%d\n",pos); 
	return 0;
} 
