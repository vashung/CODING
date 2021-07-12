#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void BFS(int s);
    void addEdge(int v, int w);
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

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    list<int> que; //Create Que
    visited[s] = true;
    que.push_back(s);

    while (!que.empty())
    {
        s = que.front();
        cout << s << " ";
        que.pop_front();

        for (auto i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                que.push_back(*i);
            }
        }
    }
}

int main()
{
    Graph graph(7);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(2, 0);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    graph.BFS(2);

    return 0;
}
