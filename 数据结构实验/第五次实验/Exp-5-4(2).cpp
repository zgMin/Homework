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
        int size=0;//当前大小
        int ok=0;//是否有结果
        while(a[j]!='\0'){
            if(a[j]=='S'){//入栈
                if(size==m){//栈满
                    cout<<"NO"<<endl;
                    ok=1;
                    break;
                }
                size++;
            }
            if(a[j]=='X'){//出栈
                if(size==0){//栈空
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
