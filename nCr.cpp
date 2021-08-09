 
#include <iostream> 
#include<string>

using namespace std; 
int ncr(int n,int r){
	int res=1,k=1;
	if(r<(n-r)){
		for(int i=n,m=1;i>n-r;--i,++m){
			res*=i;
			k*=m;
		}
	return (res/k);
	}
	return ncr(n,(n-r));
}
int main() 
{ 	int n,r;
	cin>>n>>r;
	cout<<ncr(n,r);
	

	
	return 0; 
} 
