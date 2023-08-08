#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll INF=1e17;
vector<pair<ll,ll> >g[N];
vector<ll>dist(N,INF);
 
void dijkstra(ll source)
{
    vector<ll>vis(N,0);
    set<pair<ll,ll> >st;
    st.insert({0,source});
    dist[source]=0;
    while (st.size()>0)
    {
        auto node=*st.begin();
        ll v=node.second;
        ll v_dist=node.first;
        st.erase(st.begin());
        if(vis[v])continue;
        vis[v]=1;
        for(auto child:g[v])
        {
            ll child_v=child.first;
            ll wt=child.second;
            if(dist[v]+wt<dist[child_v])
            {
                dist[child_v]=dist[v]+wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }
    
}
void printsolution(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout<<dist[i]<<" ";
    }cout<<endl;
    
}
int main()
{
    ll n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        ll x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
    }
    dijkstra(1);
    printsolution(n);
 
}
/*
6 9
1 2 1
1 3 5
2 4 2
2 3 2
2 5 1
3 5 2
4 5 3
4 6 1
5 6 2
*/