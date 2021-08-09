#include<iostream>
using namespace std;
void upper(int);
void lower(int);
int main(){

    cout<<"give no of rows: ";
    int row;
    cin>>row;
    if(row%2==0){upper(row/2);    lower(row/2);}
    else{
        upper((row/2)+1); lower(row/2);
    }



    return 0;
}
void upper(int r){
    for(int p=0;p<r;++p){
        for(int m=0;m<(2*r)-1;++m){
            if(p%2!=0 && m%2!=0 && (m>=r-p-1 && m<=r+p-1)){
                cout<<'*';
                
            }
            else if(p%2==0 && m%2==0 && (m>=r-p-1 && m<=r+p-1)) cout<<'*';
            else cout<<' ';

        }
        cout<<endl;

    }    
}
void lower(int r){
    for(int p=r-1;p>=0;--p){
        for(int m=0;m<(2*r)-1;++m){
            if(p%2!=0 && m%2!=0 && (m>=r-p-1 && m<=r+p-1)){
                cout<<'*';
                
            }
            else if(p%2==0 && m%2==0 && (m>=r-p-1 && m<=r+p-1)) cout<<'*';
            else cout<<' ';
        }
        cout<<endl;
    }
}