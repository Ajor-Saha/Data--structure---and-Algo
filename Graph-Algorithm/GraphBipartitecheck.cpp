#include <iostream>
#include <vector>
#include<queue>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
int color[N];
bool bipartiteCheck(int source)
{
    queue<int>q;
    color[source]=0;
    q.push(source);
    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int child:g[node])
        {
            if(color[child]==-1)
            {
                color[child]=!color[node];
                q.push(child);
            }
            else if (color[child]==color[node])
            {
                return false;
            }
            
        }
    }
    return true;
    
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
    
    for (int i = 0; i <= n; i++)
    {
        color[i]=-1;
    }
    int flag=0;
    for (int i = 1; i <= n; i++)
    {
        if (color[i]==-1)
        {
            if(bipartiteCheck(i))
            {
                flag=1;
            }
        }
        
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<color[i]<<" ";
    }cout<<endl;
    
    
}