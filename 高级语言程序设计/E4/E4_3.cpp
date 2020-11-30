/*
	100匹马，驼100担货，
	大马驼3担，中马驼2担 两匹小马驼1担，
	大中小马各几匹 
*/ 
#include<stdio.h>
int main(){
	int big,mid,small;
	for(big=0;big<=33;big++){//遍历大马个数 
		for(mid=0;mid<=50-big*3;mid++){//遍历中马个数 
			if((100-big-mid)%2==0 &&big*3+mid*2+(100-big-mid)/2==100){//剩下的100-big-mid则是小马个数 
				printf("大马%d匹，中马%d匹，小马%d匹\n",big,mid,100-big-mid);
			}
		}
	} 
	return 0;
} 
