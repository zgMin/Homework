/*
	�������һ�� 10 ������������
	�����������ĺ�����ѡ������ĺ���
	ͨ��������������������ʾÿ������Ľ��
	�Ƚ�����������ѡ�� 2����Ĳ��졣
*/ 	  
#include <stdio.h>
void bubble_sort(int a[])            //ð�ݷ����� 
{    
	int i,j,tmp;  
 	for(i=0;i<9;i++){       
 		for(j=0;j<9-i;j++){            
   			if(a[j]>a[j+1]){                
				tmp=a[j];            
	    		a[j]=a[j+1];               
	    		a[j+1]=tmp;            
	   		}       
    	}   
  	}
}

void choose_sort(int b[])    //ѡ������ 
{
 	int i,j,tmp;
 	for(i=0;i<=9;i++){
 		for(j=i+1;j<=9;j++){
	 		if(b[i]>b[j]){
				tmp=b[j];
	  			b[j]=b[i];
	  			b[i]=tmp;
	    	}
	 	}
 	}	
}


int main()
{
    int a[10],b[10],i;
    printf("������ʮ��Ҫ�Ƚϵ�����\n"); 
    for(i=0;i<10;i++)
    {
		scanf("%d",&a[i]);
		b[i]=a[i]; 
	}
    bubble_sort(a);
    choose_sort(b); 
    printf("ð�ݷ�������Ϊ:\n");
    for(i=0;i<=9;i++)
    	printf("  %d\t",a[i]);
    printf("\n");
    printf("ѡ������������Ϊ:\n");
    for(i=0;i<=9;i++)
    	printf("  %d\t",b[i]);
    return 0;
}
