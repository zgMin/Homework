/*
	����������㽱��
	1.profit<=10w��10%
	2.10w<profit<=20w,����10w����10%������10w����7.5%
	3.20w<profit<=40w,����20w����5%
	4.40w<profit<=60w,����40w����3%
	5.60w<profit<=100w,����60w����1.5%
	6.����100w����1% 
*/
#include<stdio.h>
int main(){
	float  profit,bonus;
	//input profit
	scanf("%f",&profit);
	//end
	//calculate bonus
	if(profit>100){
		bonus=10*0.1+10*0.075+20*0.05+20*0.03+40*0.015+(profit-100)*0.01;
	}else if(profit>60){
		bonus=10*0.1+10*0.075+20*0.05+20*0.03+(profit-60)*0.015;
	}else if(profit>40){
		bonus=10*0.1+10*0.075+20*0.05+(profit-40)*0.03; 
	}else if(profit>20){
		bonus=10*0.1+10*0.075+(profit-20)*0.05;
	}else if(profit>10){
		bonus=10*0.1+(profit-10)*0.075;
	}else{
		bonus=profit*0.1;
	}
	//end 
	//output bonus
	printf("����Ϊ%.2f��",bonus);
	//end
	return 0;
}
