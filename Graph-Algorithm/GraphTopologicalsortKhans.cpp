#include <iostream>
#include <vector>
#include<stack>
#include<queue>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    vector<int>indegree(n,0);
    queue<int>q;
    for (int i = 0; i < n; i++)
    {
        for(auto it:g[i])
        {
            indegree[it]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    
    vector<int>topo;
    while (!q.empty())
    {
        int node=q.front();
        topo.push_back(node);
        q.pop();
        for(auto child:g[node])
        {
            indegree[child]--;
            if(indegree[child]==0)
            q.push(child);
        }
    }
 //  if(topo.size()==n)
 //  { 
    for(auto p:topo)
    {
        cout<<p<<" ";
    }cout<<endl;
    
 //  }
//    else
//    {
//       cout<<"IMPOSSIBLE\n";
//    }
    
}

/*
string findOrder(string dict[], int N, int K) {
        vector<int>g[K];
        for(int i=0; i<N-1; i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.size(),s2.size());
            for(int ind=0; ind<len; ind++){
                if(s1[ind]!=s2[ind]){
                    g[s1[ind]-'a'].push_back(s2[ind]-'a');
                }
            }
        }
        
        vector<int>indegree(K+1,0);
        
        for(int i=0; i<K; i++){
            for(auto it:g[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0; i<K; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto child:g[node]){
                indegree[child]--;
                if(indegree[child]==0){
                    q.push(child);
                }
            }
        }
        
        string ans="";
        for(auto it:topo){
            ans=ans+char(it+'a');
        }
        return ans;
    }*/