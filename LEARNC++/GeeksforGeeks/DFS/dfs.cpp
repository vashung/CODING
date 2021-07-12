#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    //map <int, bool> visited;
    //map <int, list<int>> adj;
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int s);
    void DFSU(int s, bool *visited);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFSU(int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
    {
        if (!visited[*i])
        {
            DFSU(*i, visited);
        }
    }
}

//Wrapper function
void Graph::DFS(int s)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    DFSU(s, visited);
}

int main()
{
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(1, 2);

    graph.DFS(2);
}