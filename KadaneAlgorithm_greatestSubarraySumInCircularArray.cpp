#include<iostream>
#include<typeinfo>
using namespace std;
						//	KADANE'S ALGORITHM ON CIRCULAR ARRAY(FIND MAX SUBARRAY SUM)
						//	I INDEXED TILL 2*N
						//ANOTHER APPROACH IS SUBSTRACT LEAST SUBARRAY SUM FROM TOTAL ARRAY USING KADANE TO GET 
						//ANSWER.

int main(){
	int n,x;
	cin>>n>>x;
	int a[n];

	
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
    int ini=0,fin=n-1;
    while(ini!=fin)
    {
        if(a[ini]+a[fin]==x)
        {
            cout<<"True";
            break;
        }
        
        else if(a[ini]+a[fin]>x)
        {
            fin--;
        }
        else if(a[ini]+a[fin]<x)
        {
            ini++;
        }
        
    }
    if(ini==fin){
        cout<<"False";
    }

	

	return 0;
}
