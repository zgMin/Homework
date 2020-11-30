#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define Status int
#define k 96		//k进制,ascii可显字符共95个，保留0，取96进制 
#define Max_Num	39877	//哈希表长度 
using namespace std; 
typedef struct{
	int num;	//num记录字符串出现次数
	int flag;	//flag指向的字符串标号 
}Hash,HashList[Max_Num];		//Hash表的数据结构 
Status getHash(char ss[][1501],int m,HashList &H,int &val){
	//ss[][]存储字符串的表，m字符串标号，H是哈希表，val得到的哈希值
	//返回值,1.映射前早已重复 0.映射前已经存在 -1.映射前未存在 
	int len =strlen(ss[m]);
    val = 0;
	for(int i = 0; i < len ; i++){
		val =((val*k)%Max_Num + ss[m][i]-' ' + 1)%Max_Num;
	}			//k进制数转换为十进制数 ,过程中进行取模 
	int d=1; //偏移量 
	while(H[val].num!=0){//产生冲突 
		if(strcmp(ss[H[val].flag],ss[m])==0){//相同字符串产生的冲突
			if(H[val].num==1){		//已经存在 
				H[val].num++;return 0;
			}
			else{					//早已重复 
				H[val].num++;return 1;
			}
		} 
		else{	//不同字符串产生的冲突，进行线性探测再散列 
			val=(val+d)%Max_Num;
		} 
	}
	H[val].flag=m;		//指向的字符串标号 
	H[val].num++;		//字符串出现次数+1 
    return -1;
}
void init(HashList &H){//初始化哈希表
	for(int i=0;i<=Max_Num;i++)
		H[i].num=0; 
	return;
}
int main(){
	int t;
	cout<<"请输入测试数据的组数："; 
	cin>>t;
	FILE *pos;
	FILE *rd = fopen("Input.txt", "r");
	FILE *wt = fopen("hash-deduplication.txt", "w"); 
	int cnt=0; //计数器，用于记录当前数据组数 
	HashList H;		//创建哈希表 
	while(true){
		init(H);//初始化哈希表 
		int n; 
		if(fscanf(rd,"%d",&n)==EOF){
			cout<<"输入文件已经全部读取完！"<<endl; 
			cout<<"是否继续测试？（y/n）";
			char jixu;
			cin>>jixu;
			if(jixu=='y'||jixu=='Y'){
				cnt=0;
				cout<<"请输入测试数据的组数："; 
				cin>>t;
				continue;
			} 
			break; 
		}
		int ans[n/2];//ans用于存储重复的单词的下标，最多n/2个
		int ans_cnt=0; //记录重复个数 
		char ss[n+1][1501];//用于读入n个最大长度不超过 1500的字符串 
		for(int i=1;i<=n;i++){
			fscanf(rd,"%s",ss[i]);
			int p;
			if(getHash(ss,i,H,p)==0){
				ans[ans_cnt++]=i;
			}
		}
		//输出重复单词
		cout<<"第"<<cnt+1<<"组重复单词"<<endl; 
		for(int i=0;i<ans_cnt;i++)
			cout<<ss[ans[i]]<<endl; 
		cout<<endl;		//用于分割不同组测试数据 
		for(int i=0;i<ans_cnt;i++)
			fprintf(wt,"%s\n",ss[ans[i]]); 
		fprintf(wt,"\n");
		cnt++;
		if(cnt==t){
			cout<<"是否继续测试？（y/n）";
			char jixu;
			cin>>jixu;
			if(jixu=='y'||jixu=='Y'){
				cnt=0;
				cout<<"请输入测试数据的组数："; 
				cin>>t;
				continue;
			} 
			else break; 
		} 
	}
	fclose(rd);
	fclose(wt); 
	return 0;
}
