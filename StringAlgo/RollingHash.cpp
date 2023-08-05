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
ll getHash(string key)
{
    ll value=0;
    ll p = 31;
    ll p_power=1;
    
    for(char ch:key)
    {
        value=(value+(ch-'a'+1)*p_power)%mod;
        p_power=(p_power*p)%mod;
    }
    return value;
}
int main()
{
    bool flag=1;

    while (flag)
    {
        string key;
        cout<<"Enter key\n";
        cin>>key;
        if(key==".")flag=false;
        else{
            cout<<"key : "<<key<<"Hash : "<<getHash(key)<<endl;
        }
    }
    
}