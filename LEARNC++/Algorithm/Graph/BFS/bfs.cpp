#include<bits/stdc++.h>
#define VERTICE 7

using namespace std;

class Graph{
    public:
     int V;
     list<int> *adj;

     Graph(int v){
         this->V = v;
         adj = new list<int>[V];
     }
     void insert(int, int);
     void bsf(int);
}; 

void Graph::insert(int v, int w){
    adj[v].push_back(w);
}
void Graph::bsf(int n){
    list<int> q;
    bool *visit= new bool[V];
    for(int i = 0;i < V; i++){
        visit[i] = false;
    }
    visit[n] = true;
    q.push_back(n);

    while(!q.empty())
    {
        n = q.front();
        cout<<n<<" " ;
        q.pop_front();
        for(auto x= adj[n].begin(); x != adj[n].end(); x++){
            if(!visit[*x]){
                visit[*x] = true;
                q.push_back(*x);
            }
        }

    }
}



int main()
{
    Graph g(7);
    g.insert(0,1);
    g.insert(0,2);
    //g.insert(2,1);
    g.insert(1,2);  g.insert(2,0);
    g.insert(2,3);
    g.bsf(2);
    return 0;
}
