#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        char a[101];
        cin>>a;
        int j=0;
        int size=0;//��ǰ��С
        int ok=0;//�Ƿ��н��
        while(a[j]!='\0'){
            if(a[j]=='S'){//��ջ
                if(size==m){//ջ��
                    cout<<"NO"<<endl;
                    ok=1;
                    break;
                }
                size++;
            }
            if(a[j]=='X'){//��ջ
                if(size==0){//ջ��
                    cout<<"NO"<<endl;
                    ok=1;
                    break;
                }
                size--;
            }
            j++;
        }
        if(!ok) if(!size) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
    }
    return 0;
}
