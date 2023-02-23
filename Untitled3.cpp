#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long long int m,n,i;

    while(cin >> n >> m){
        long long cn1 = m;

        for(i=1;cn1>n && m>1;i++){
            cn1=pow(m,i);
        }

        if(cn1>n || m<=1){
            cout<<"Boring!"<<endl;
        }
        else{
            while(cn1>0){
                cout<<cn1;
                if(cn1!=1){
                    cout<<" ";
                }else{
                    cout<<endl;
                }
                cn1/=m;
            }
        }
    }
    return 0;
}