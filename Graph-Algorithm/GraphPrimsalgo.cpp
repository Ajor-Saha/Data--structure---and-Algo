#include <iostream>
#include <vector>
#include <set>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+10;
vector<pair<int,int> >g[N];
int prims_algo(int n)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
    pq.push(make_pair(0,0));
    vector<int>vis(n+1,0);
    int res=0;
    while (!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int wt=it.first;
        if(vis[node])continue;
        vis[node]=1;
        res+=wt;
        for(auto it:g[node])
        {
            int child=it.first;
            int child_wt=it.second;
            if (!vis[child])
            {
                pq.push(make_pair(child_wt,child));
            }
            
        }

    }
    return res;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back(make_pair(y,wt));
        g[y].push_back(make_pair(x,wt));
    }

    cout<<prims_algo(n)<<endl;
    
}