#include <iostream>
#include <vector>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
bool vis[N];
vector<vector<int> >cc;
vector<int>current_cc;
void dfs(int vertex)
{
    /*Take action on vertex after entering 
    the vertex
    */
    vis[vertex]=true;
    current_cc.push_back(vertex);
    for(int child:g[vertex])
    {
        
        if(vis[child]) continue;
        /*Take action on child before entering the child node
       */
        dfs(child);
         /*Take action on child after exiting child node*/
    }
    /*Take action on vertex before exiting the vertex*/

}
int main()
{
    int n,e;
    cin>>n>>e;
    for (int i = 0; i < e; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int ct=0;
    for (int i = 1; i <= n; i++)
    {
        if(vis[i])continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
        ct++;
    }
    cout<<cc.size()<<endl;
    for(auto c_cc:cc)
    {
        for(int vertex: c_cc){
        cout<<vertex<<" ";
        }
        cout<<endl;
    }
    
}