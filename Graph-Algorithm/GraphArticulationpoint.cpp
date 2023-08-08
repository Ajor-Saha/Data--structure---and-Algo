#include <iostream>
#include <vector>
#include <set>
#include<stack>
using namespace std;
typedef long long ll;
const int N=1e5+10;
vector<int>g[N];
int vis[N],in[N],low[N];
int timer;
stack<int>st;
void dfs(int node,int par)
{
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;
    int children=0;
    for(auto child:g[node])
    {
        if(child==par)continue;
        if(vis[child])
        {
            low[node]=min(low[node],in[child]);
        }
        else
        {
            dfs(child,node);
            low[node]=min(low[node],low[child]);
            if(low[child]>=in[node] && par!=-1)
                cout<<node<<" is a cut point\n";
                ++children;
        }
    }
    st.push(node);
    if(par==-1 && children>1)
    cout<<node<<" is a cut point\n";
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i,-1);
        }
        
        
    }
   
   while (!st.empty())
   {
      cout<<st.top()<<" ";
      st.pop();
   }
   
    // for (int i = 1; i <=n; i++)
    // {
    //     cout<<in[i]<<" ";
    // }cout<<endl;
    
    // for (int i = 1; i <=n; i++)
    // {
    //     cout<<low[i]<<" ";
    // }cout<<endl;
    

}