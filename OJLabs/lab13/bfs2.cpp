#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

struct Node {
    int id;
    string color;
    int d;
    int pi;

    Node(int id) : id(id), color("WHITE"), d(INT_MAX), pi(-1) {}
};

class Graph {
public:
    unordered_map<int, Node*> nodes;
    unordered_map<int, vector<int> > adj;

    ~Graph() 
    {
        for (auto& pair:nodes) 
        {
            delete pair.second;
        }
    }

    void addNode(int id) 
    {
        if(nodes.find(id)== nodes.end()) 
        {
            nodes[id]= new Node(id);
            adj[id]= vector<int>();
        }
    }

    void addEdge(int v1, int v2) {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    void BFS(int s) {
        for (auto& pair : nodes) {
            pair.second->color= "WHITE";
            pair.second->d= INT_MAX;
            pair.second->pi= -1;
        }

        queue<int> q;
        Node* source= nodes[s];
        source->color= "GRAY";
        source->d= 0;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                Node* neighbor = nodes[v];
                if (neighbor->color=="WHITE") {
                    neighbor->color="GRAY";
                    neighbor->d=nodes[u]->d + 1;
                    neighbor->pi=u;
                    q.push(v);
                }
            }
            nodes[u]->color="BLACK";
        }
    }

    void print_path(int s, int v)
    {
        if (nodes[v]->d == INT_MAX) {
            cout << -1 << endl;
            return;
        }

        vector<int> path;
        int current = v;
        while(current != -1)
        {
            path.push_back(current);
            current = nodes[current]->pi;
        }

        reverse(path.begin(), path.end());
        for (int i=0;i<path.size();i++) {
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    int n,m,s;
    cin>>n>>m>>s;

    Graph graph;

    for (int i=1;i<=n;i++)
    {
        graph.addNode(i);
    }

    for (int i=0;i<m;i++)
    {
        int vi, vj;
        cin>>vi>>vj;
        graph.addEdge(vi, vj);
    }

    graph.BFS(s);

    int vy, vz;
    cin>>vy>>vz;

    graph.print_path(s, vy);
    graph.print_path(s, vz);

}