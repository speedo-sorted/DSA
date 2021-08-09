#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define what_is(x) cerr<<#x<<"is"<<x<<'\n';
#define google cout<<"Case #"<<ll<<": "<<day<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define mod int(1e9+7)
#define nax int(1e4 + 5)
#define nax int(1e5 + 5)

//////////////////////////////////////////////////////////////////////
//articulation point by simple dfs and checking low
int d[nax], low[nax];
llint n, m;
vector<int> adj[nax];
bool isart[nax];

void dfs(int vertex, int time, int parent)
{
    d[vertex] = time + 1;
    low[vertex] = time + 1;
    int child = 0;
    for(int i = 0; i < adj[vertex].size(); i++)
    {
        int node = adj[vertex][i];
        if(node == parent)  continue;

        else if(d[node] == 0)
        {   
            child++;
            dfs(node, time + 1, vertex);
            low[vertex] = min(low[vertex], low[node]);
            
            if(vertex == 0)
                {if(child > 1)
                isart[vertex] == true;}
        
            else if(low[node] >= d[vertex]) 
                isart[vertex] = true;

        }
        else 
        {
            low[vertex] = min(low[vertex], d[node]);
        }
    }

}
/////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// djkstra using sets - directed graph
int dis[nax];
int main(){
    boost
    for(int i = 0; i < nax; i++)
        dis[i] = 1e9;

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> graph[n];

    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        graph[a].push_back({w, b});
    }    
    dis[0] = 0;
    set<pair<int, int>> st;
    st.insert({0, 0});
    while(!st.empty())
    {
        int node = st.begin()->second;
        int distance = st.begin()->first;

        st.erase(st.begin());
        dis[node] = distance;
        for(int i = 0; i < graph[node].size(); i++)
        {
            if(dis[graph[node][i].second] == 1e9 )
                st.insert({dis[node] + graph[node][i].first, graph[node][i].second}),
                dis[graph[node][i].second] = dis[node] + graph[node][i].first;

            else if(dis[graph[node][i].second] > dis[node] + graph[node][i].first)
            {
                st.erase({dis[graph[node][i].second], graph[node][i].second});
                st.insert({dis[node] + graph[node][i].first, graph[node][i].second});
                dis[graph[node][i].second] = dis[node] + graph[node][i].first;
            }
        }

    }
    for(int i = 1; i < n; i++)  
        cout << dis[i] << ' ';
    cout << '\n';
   
    return 0;
}