#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include<stack>
#include<set>
#include <unordered_map>
using namespace std;
#define precision(n) cout << setprecision(n) << fixed;
#define Pair make_pair
typedef long long ll;
const int mod=1e9+7;
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    ll p=31;
    ll pow=p;
    ll dhv=s2[0]-'a'+1;
    
    for (int i = 1; i < s2.size(); i++)
    {
        dhv=(dhv+((s2[i]-'a'+1)*pow))%mod;
        pow=(pow*p)%mod;
    }
    

    ll dp[s1.size()];
    ll pa[s1.size()];

    dp[0]=s1[0]-'a'+1;
    pa[0]=1;
    pow=p;

    for(int i=1; i<s1.size(); i++){
        dp[i]=(dp[i-1]+((s1[i]-'a'+1)*pow))%mod;
        pa[i]=pow;
        pow=(pow*p)%mod;
    }

    int sp=0,ep=s2.size()-1;
    vector<int>ans;

    while (ep<s1.size())
    {
        ll win=dp[ep];

        if(sp>0)win=(win-dp[sp-1]+mod)%mod;
        if(win==(dhv*pa[sp])%mod)
        ans.push_back(sp+1);
        sp++;
        ep++;
    }
    
    if(ans.size()==0){
        cout<<"Not Found"<<endl;
        cout<<endl;
        return;
    }

    cout<<ans.size()<<endl;

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    cout<<endl;

}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
}