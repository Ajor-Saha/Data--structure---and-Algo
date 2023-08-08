#include <iostream>
#include <vector>
using namespace std;
vector<int>bellman_ford(vector<vector<int> >&g,int edges,int node,int source)
{
    vector<int>dist(node,1e8);
    dist[source]=0;
    for (int i = 0; i < edges-1; i++)
    {
        for(auto it:g)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if (dist[u]!=1e8 && dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;
            }
            

        }
    }
    //Nth relaxation to check negative cycle
  int flag=0;
    for(auto it:g)
    {
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if (dist[u]!=1e8 && dist[u]+wt<dist[v])
        {
            flag=1;
            break;
        }
        
    }
    vector<int>res(1,-1);
    if(flag==1)return res;
    return dist;
}
int main()
{
    int node,edges;
    cin>>node>>edges;
    vector<vector<int> >g;
    for (int i = 0; i < edges; i++)
    {
        vector<int>v;
        for (int i = 0; i < 3; i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        g.push_back(v);
        
    }
    int source;
    cin>>source;
    vector<int>dist=bellman_ford(g,edges,node,source);
    for(auto d:dist)
    {
        cout<<d<<" ";
    }cout<<endl;

}