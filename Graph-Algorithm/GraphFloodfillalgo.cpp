#include<iostream>
#include<vector>
using namespace std;
int n,m;
int arr[1001][1001];
bool vis[1001][1001];
int sr,sc,color;

void dfs(int i,int j,int intialColor)
{
    if(i<1 || j<1)return;
    if(i>n || j>m)return;
    if(arr[i][j]!=intialColor)return;
    arr[i][j]=color;
    dfs(i-1,j,intialColor);
    dfs(i+1,j,intialColor);
    dfs(i,j-1,intialColor);
    dfs(i,j+1,intialColor);
 
}
int main()
{
   cin>>n>>m;
   for (int i = 1; i <= n; i++)
   {
       for (int j = 1; j <= m; j++)
       {
           cin>>arr[i][j];
       }
       
   }
   cin>>sr>>sc>>color;
   int initialColor=arr[sr][sc];
   if(initialColor!=color)
   dfs(sr,sc,initialColor);
   for (int i = 1; i <= n; i++)
   {
       for (int j = 1; j <= m; j++)
       {
           cout<<arr[i][j]<<" ";
       }cout<<endl;
       
   }
   
    
 
}