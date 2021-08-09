#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define what_is(x) cerr<<#x<<"is"<<x<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void towerOfHanoi(int n,char src,char des,char hlp){
    if(n==0)
        return;
    towerOfHanoi(n-1,src,hlp,des);
    cout<<"move "<<src<<" to "<<des<<'\n';
    towerOfHanoi(n-1,hlp,des,src);
}
int main(){
    boost
    towerOfHanoi(4,'A','C','B');
    return 0;
}
