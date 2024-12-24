#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<pair<int, long long> > adj[50005];
long long dist[50005];
int pa[50005];

void dijkstra(int start, int n)
{
    for(int i=0;i<n;i++)
    {
        dist[i]=LLONG_MAX;
        pa[i]=-1;
    }
    dist[start]=0;
    
    priority_queue<pair<long long, int>, 
    vector<pair<long long, int> >,
    greater<pair<long long, int> > > pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int u=pq.top().second;
        long long d=pq.top().first;
        pq.pop();
        
        if(d>dist[u]) continue;
        
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].first;
            long long weight=adj[u][i].second;
            
            if(dist[u]+weight<dist[v]) 
            {
                dist[v]=dist[u]+weight;
                pa[v]=u;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}

void print_path(int s, int t)
{
    vector<int> path;
    for (int v=t;v!=-1;v=pa[v])
    {
        path.push_back(v);
    }
    
    for(int i=path.size()-1;i>=0;i--)
    {
        cout<<path[i]+1<<" ";
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        int u, v;
        long long w;
        cin>>u>>v>>w;
        u--;
        v--;
        adj[u].push_back(make_pair(v, w));
    }
    
    int s,t;
    cin>>s>>t;
    s--;
    t--;
    
    dijkstra(s, n);
    print_path(s,t);
    
    return 0;
}
