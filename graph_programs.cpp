#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define what_is(x) cerr<<#x<<"is"<<x<<'\n';
#define google cout<<"Case #"<<ll<<": "<<day<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define mod int(1e9+7)
#define nax int(1e4 + 5)

//////////////////////////////////////  
// hamiltonian path - O(2^n * n^2)
// idea is to use dp and bitmasking i.e 1011 means 4th, 2nd , and 1st elements are
// remaining elements to be traversed, so take each let us say 4 then check for remaining nodes
// if there is edge - 2 -> 4 and if some path exists which ends at 2 with remaining 1, 2 nodes
// by this- i.e 1 -> 2 (ending at 2 and contains remaining nodes -1,2)
// now 1 -> 2 -> 4 (since there is a path from 2 to 4)



int Adj[12][12];                        // 12 nodes
bool dp[12][1<<12];

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)                  // first make all paths false
        for(int j = 0; j < (1<<n); j++)
            dp[i][j] = false;
    
    for(int i = 0; i < n; i++)                 // make 1-> 1 true, 2 -> 2 true ...
        dp[i][1<<i] = true;

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        Adj[x][y] = true;
        Adj[y][x] = true;
    }

    for(int i = 0; i < 1<<n; i++)           // loop each pattern 1010111...
        for(int j = 0; j < n; j++)
            if(i & (1<<j))                  // if jth bit is set
                for(int k = 0; k < n; k++)
                    if( ( j != k ) && ( i & (1<<k) ) && Adj[k][j] == true )
                    {
                        if( dp[k][i ^ (1<<j)] )         // if ... 4 -> 3 -> ... -> k exists
                            dp[j][i] = true;
                        
                        break;
                    }

    bool hamilton = false;
    for(int i = 0; i < n; i++)
        if(dp[i][(1<<n) - 1])               // ans is dp[i][2^n - 1]
        {
            hamilton = true;
            break;
        }

    if(hamilton)
        cout << "YES\n";
    else 
        cout << "NO\n";


}

//////////////////////////////////////////////////////////////////////
//articulation point by simple dfs and checking low
int d[nax], low[nax];
llint n, m;
vector<int> adj[nax];
bool isart[nax];
int vistime = 0;

void dfs(int vertex, int parent)
{
    d[vertex] = vistime + 1;
    low[vertex] = vistime + 1;
    vistime++;

    int child = 0;
    for(int i = 0; i < adj[vertex].size(); i++)
    {
        int node = adj[vertex][i];
        if(node == parent)  continue;

        else if(d[node] == 0)
        {   
            child++;
            dfs(node, vertex);
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

/////////////////////////////////////////////  
// strongly connected components
// steps - 
// 1. do dfs1 to store nodes according to finish time in stack (stack top has highest finish time node)
// 2. now stack top has node which is part of 1 of the strong connected comp. of this graph 
// 3. but we need sink reference so - reverse the graph ->so that source, sink interchange
// 4. now do dfs of graph using that stack to get strong connected comp.

int n, m;
vector<int> adj[nax], revadj[nax];
stack<int> s;
bool visited[nax];

void dfs1(int vertex){                      // store the stack
    visited[vertex] = true;
    for(int i = 0; i < adj[vertex].size(); i++)
        if(!visited[adj[vertex][i]])
            dfs1(adj[vertex][i]);
    
    s.push(vertex);
}

void graphrev(){                            // reverse the graph
    for(int i = 0; i < n; i++)
        for(int j = 0; j < adj[i].size(); j++)
            revadj[adj[i][j]].push_back(i);

}
llint ch = 0;
void dfs2(int node){                    // no. of children in this SSC
    visited[node] = true; ch++;
    for(int i = 0; i < revadj[node].size(); i++)
    {
        if(!visited[revadj[node][i]])
        {
            dfs2(revadj[node][i]);
        }   
    }
}

int main(){
    boost
    // input node, edges and find 
    //(sum of no. of nodes in SCC with odd elements - sum of no. of nodes in SCC with even elements)
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
    }

    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            dfs1(i);
    }
    graphrev();
    llint sm = 0;
    memset(visited, 0, sizeof(visited));
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        if(!visited[node])
        {
            dfs2(node);
            sm += (ch%2 == 0 ? -ch : ch);
            ch = 0;
        }
    }
    cout << sm << '\n';


   return 0;
}

///////////// 
// topological sort 

// create topoligical sort (lexographically smallest, since there can be many) of directed acyclic graph in T vector using stack
// this method is similar to small part of finding SCC here we just store nodes in sorted order in T
vector<int> adj[nax];
bool visited[nax];
int n, m;
vector<int> T;


void dfs(int node){                     // main function which works
    visited[node] = true;
    for(int i = 0; i < adj[node].size(); i++)
        if(!visited[adj[node][i]])
            dfs(adj[node][i]);
    
    T.push_back(node);
}



int main(){
    boost
    cin >> n >> m;
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);

    }
    for(int i = 0; i < n; i++)
        sort(all(adj[i]), greater<int>());

    for(int i = n -1; i>-1; i--)
    {
        if(!visited[i])
        dfs(i);
    }
    // cout << "dfsd";
    for(int i = T.size() -1; i > -1; i--)
        cout << T[i] + 1 << ' ';
    cout << '\n';
    
    return 0;
}
