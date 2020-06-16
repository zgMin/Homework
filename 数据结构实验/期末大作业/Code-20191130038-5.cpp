#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#define Status int
#define k 96		//k����,ascii�����ַ���95��������0��ȡ96���� 
#define Max_Num	39877	//��ϣ���� 
using namespace std; 
typedef struct{
	int num;	//num��¼�ַ������ִ���
	int flag;	//flagָ����ַ������ 
}Hash,HashList[Max_Num];		//Hash������ݽṹ 
Status getHash(char ss[][1501],int m,HashList &H,int &val){
	//ss[][]�洢�ַ����ı�m�ַ�����ţ�H�ǹ�ϣ��val�õ��Ĺ�ϣֵ
	//����ֵ,1.ӳ��ǰ�����ظ� 0.ӳ��ǰ�Ѿ����� -1.ӳ��ǰδ���� 
	int len =strlen(ss[m]);
    val = 0;
	for(int i = 0; i < len ; i++){
		val =((val*k)%Max_Num + ss[m][i]-' ' + 1)%Max_Num;
	}			//k������ת��Ϊʮ������ ,�����н���ȡģ 
	int d=1; //ƫ���� 
	while(H[val].num!=0){//������ͻ 
		if(strcmp(ss[H[val].flag],ss[m])==0){//��ͬ�ַ��������ĳ�ͻ
			if(H[val].num==1){		//�Ѿ����� 
				H[val].num++;return 0;
			}
			else{					//�����ظ� 
				H[val].num++;return 1;
			}
		} 
		else{	//��ͬ�ַ��������ĳ�ͻ����������̽����ɢ�� 
			val=(val+d)%Max_Num;
			d++;
		} 
	}
	H[val].flag=m;		//ָ����ַ������ 
	H[val].num++;		//�ַ������ִ���+1 
    return -1;
}
void init(HashList &H){//��ʼ����ϣ��
	for(int i=0;i<=Max_Num;i++)
		H[i].num=0; 
	return;
}
int main(){
	int t;
	cout<<"������������ݵ�������"; 
	cin>>t;
	freopen("Input.txt","r",stdin); //�����ض����������ݽ���Input.txt�ļ��ж�ȡ 
	freopen("hash-deduplication.txt","w",stdout); //����ض���������ݽ�����hash-deduplication.txt�ļ��� 
	int cnt=0; //�����������ڼ�¼��ǰ�������� 
	HashList H;		//������ϣ�� 
	while(true){
		init(H);//��ʼ����ϣ�� 
		int n; 
		cin>>n;
		int ans[n/2];//ans���ڴ洢�ظ��ĵ��ʵ��±꣬���n/2��
		int ans_cnt=0; //��¼�ظ����� 
		char ss[n+1][1501];//���ڶ���n����󳤶Ȳ����� 1500���ַ��� 
		for(int i=1;i<=n;i++){
			cin>>ss[i];
			int p;
			if(getHash(ss,i,H,p)==0){
				ans[ans_cnt++]=i;
			}
		}
		//����ظ�����
		for(int i=0;i<ans_cnt;i++)
			cout<<ss[ans[i]]<<endl; 
		cout<<endl;		//���ڷָͬ��������� 
		cnt++;
		if(cnt==t) break;
	}
	fclose(stdin);//�ر��ض�������
	fclose(stdout);//�ر��ض������ 
	return 0;
}
