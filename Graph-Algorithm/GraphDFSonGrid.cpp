#include<iostream>
#include<vector>
using namespace std;
int N,M;
bool vis[1001][1001];
bool isValid(int x,int y)
{
    if(x<1 || x>N || y<1 || y>M)
    return false;
    if(vis[x][y]==true)
    return false;
    return true;
}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void dfs(int x,int y)
{
    vis[x][y]=1;
    cout<<x<<" "<<y<<endl;
    for(int i=0; i<4; i++)
    if(isValid(x+dx[i],y+dy[i]))
    dfs(x+dx[i],y+dy[i]);
    // if(isValid(x-1,y))
    // dfs(x-1,y);//up
    // if(isValid(x,y+1))
    // dfs(x,y+1);//right
    // if(isValid(x+1,y))
    // dfs(x+1,y);//down
    // if(isValid(x,y-1))
    // dfs(x,y-1);//left
}
int main()
{
    cin>>N>>M;
    dfs(1,1);
}