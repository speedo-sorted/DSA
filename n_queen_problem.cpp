//N Queen Problem
/*
approach-
i know that if path is possible then exactly 1 queen will be there for every row
so i check just for the row that if queen at that row is not attacked before
 (by checking c[],r[] and mp and set(for diagonal elements) )and will not be attacked after by calling fn for next
 row .. then a[][] value will be 1 .
 if i reach the end of a col then return 0
 however if i reach end of all row and queens left ==0 then return 1 for each...
*/

#include <bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(), v.end()
#define boost                         \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
int r[30]={},c[30]={};
unordered_map<int,int> mp;
set<pair<int,int>> st;
int a[20][20]={};
int n;
bool chk(int row,int col){
    int pos=-(n-1);
    int i=row-col;
    while(i>=pos)
    {
        if(mp[i]==1 && (r[row]==1 && c[col]==1) && (st.lower_bound({row,col}))->first==row && (st.lower_bound({row,col}))->second==col)
            return 1;
        i-=2;   col+=1;   row-=1;
    }
    return 0;
}
bool isattacked(int row,int col){
    if((r[row]==0 && c[col]==0) && (mp[(row-col)]==0 && chk(row,col)==0))
        return 0;
    return 1;

}
bool countqueen(int row,int queen){
    if(row==n+1 && queen==0)
        return 1;
    else if(row==n+1)
        return 0;
    for(int i=1;i<=n;i++)
    {   
        if(!isattacked(row,i))
        {   
            r[row]=1;c[i]=1;
            mp[(row-i)]=1;  
            st.insert({row,i});
            if(countqueen(row+1,queen-1))
            {
                a[row][i]=1;
                return 1;
            }
            r[row]=0;c[i]=0;
            mp[(row-i)]=0;
            st.erase({row,i});
            

        }
    }
    return 0;
}

int main()
{
    boost 
    cin>>n;
    if(countqueen(1,n))
    {   cout<<"YES"<<'\n';
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j]==1)
                {
                    cout<<1<<' ';
                }
                else
                {
                        cout<<0<<' ';
                }
            }
            cout<<'\n';
        }
    }
    else 
        cout<<"NO"<<'\n';
    
    
    return 0;
}

