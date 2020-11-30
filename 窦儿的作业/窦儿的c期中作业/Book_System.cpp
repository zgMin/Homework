#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
 
#include<time.h>
using namespace std;

int main(){	
//0表示沙暴，1表示晴朗，2表示高温 
	srand(time(NULL));
	int A[31];
	for(int i=1;i<=30;i++){
		int tmp=rand()%10000;
		if(tmp<2000)
			A[i]=0;
		else if(tmp<5000)
				A[i]=1;
		else
			A[i]=2; 
	}
	for(int i=1;i<=30;i++){
		cout<<A[i]<<" ";
	}
	return 0;
}