/*
	根据利润计算奖金
	1.profit<=10w，10%
	2.10w<profit<=20w,低于10w部分10%，高于10w部分7.5%
	3.20w<profit<=40w,高于20w部分5%
	4.40w<profit<=60w,高于40w部分3%
	5.60w<profit<=100w,高于60w部分1.5%
	6.高于100w部分1% 
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
	printf("奖金为%.2f万",bonus);
	//end
	return 0;
}
