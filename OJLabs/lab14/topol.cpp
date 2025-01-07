#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[50001];
int color[50001];  
vector<int> ordered;
bool cycle = false;

void dfs(int u) 
{
    color[u]=1; 

    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(color[v]==0) 
        {
            dfs(v);
        } 
        else if(color[v]==1) 
        {
            cycle=true;
        }
    }
    
    color[u]=2;  
    ordered.push_back(u);
}

void topological_sort(int n)
{
    for(int i=1;i<=n;i++)
        color[i] = 0;
    ordered.clear();
    cycle=false;
    
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            dfs(i);
        }
    }

    reverse(ordered.begin(), ordered.end());
}

int main() {
    int n, m;
    cin>>n>>m;
    
    for (int i=0;i<m;i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    topological_sort(n);
    
    if(cycle)
    {
        cout<<-1<<endl;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            cout<<ordered[i]<<" ";
        }
    }
    
    return 0;
}