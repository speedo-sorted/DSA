#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define Fill(a,b)  memset(a,b,sizeof(a))
#define what_is(x) cerr<<#x<<"is"<<x<<'\n';
#define google cout<<"Case #"<<ll<<": "<<day<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define mod int(1e9+7)
#define nax int(1e4 + 3)

/*
    prims algorithm for minimum spanning tree 

*/


vector<pair<int, int>> adj[nax];
set<pair<int, int>> st;
bool visited[nax] = {};

int main(){
    boost
    // n=nodes, m=edges
    llint n, m;

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {  
         //input is - node1 node2 weight
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }
    st.insert({0, 1});
    visited[0] = true;
    llint ans = 0;
    while(!st.empty())
    {   
        int wt = st.begin()->first;
        int node = st.begin()->second;
        st.erase(st.begin());
        if(visited[node])
            continue;
        ans += wt;
        visited[node] = true;
        for(auto pr: adj[node])
        {
            if(!visited[pr.second])
                st.insert(pr);
        }

    }

    // sum of weights
    cout << ans << '\n';

    return 0;
}