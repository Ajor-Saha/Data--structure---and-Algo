#include <iostream>
#include <vector>
#include<queue>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
bool vis[N];
bool detetCycle(int source)
{
    vis[source]=true;
    queue<pair<int,int> >q;
    q.push(make_pair(source,-1));
    while (!q.empty())
    {
        auto it=q.front();
        int node=it.first;
        int parent=it.second;
        q.pop();
        for(int child:g[node])
        {
            if (!vis[child])
            {
                q.push(make_pair(child,node));
                vis[child]=true;
            }
            else if (parent!=child)
            {
                return true;
            }
            
            
        }
    }
    return false;
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= m; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int cycle=0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if(detetCycle(i))
            {
                cycle=1;
            }
        }
        
    }
    cout<<cycle<<endl;
    
}