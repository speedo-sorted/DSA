#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()

#define fill(a,b)  memset(a,b,sizeof(a))
#define what_is(x) cerr<<#x<<"is"<<x<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
void merg(int a[],int l,int r){
    int mid=(l+r)/2,p1=l,p2=mid+1,pos=0;
    int sz=r-l+1;
    int b[sz];
    while(pos<r-l+1)
    {
        if(a[p1]<=a[p2] && p1<mid+1)
        {
            (b[pos]=a[p1]);
            p1++;
        }
        else if(a[p2]<=a[p1] && p2<r+1)
        {
            (b[pos]=a[p2]);
            p2++;
        }
        else if(p1>mid)
        {
            (b[pos]=a[p2]);
            p2++;
        }
        else
        {
            (b[pos]=a[p1]);
            p1++;
        }
        
        pos++;
    }
    for(int x:b)
    {
        a[l]=x; l++;
    }
}
void mergesort(int a[],int l,int r){
    int mid=(l+r)/2;

    if(l<r)
    {
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
    }
    merg(a,l,r);
}

int main(){
    boost
    int a[]={7,3,9,3,-1,8,4,6,1,5,3,0};    
   mergesort(a,0,sizeof(a)/4-1);
    for(int i=0;i<12;i++)
        cout<<a[i]<<' ';
    return 0;
}