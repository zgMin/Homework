/*
	定义包含一个 10 个整数的数组
	设计起泡排序的函数和选择排序的函数
	通过调用两个排序函数，显示每趟排序的结果
	比较起泡排序与选择 2排序的差异。
*/ 	  
#include <stdio.h>
void bubble_sort(int a[])            //冒泡法排序 
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

void choose_sort(int b[])    //选择排序法 
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
    printf("请输入十个要比较的整数\n"); 
    for(i=0;i<10;i++)
    {
		scanf("%d",&a[i]);
		b[i]=a[i]; 
	}
    bubble_sort(a);
    choose_sort(b); 
    printf("冒泡法排序结果为:\n");
    for(i=0;i<=9;i++)
    	printf("  %d\t",a[i]);
    printf("\n");
    printf("选择排序法排序结果为:\n");
    for(i=0;i<=9;i++)
    	printf("  %d\t",b[i]);
    return 0;
}
