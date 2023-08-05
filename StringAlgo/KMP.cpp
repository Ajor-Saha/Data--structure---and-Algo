#include <iostream>
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
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string s,pat;
        cin>>s>>pat;
        string st="";
        st+=pat;
        st+="#";
        st+=s;
        vector<int>lps(st.size(),0);
        lps[0]=0;
        int i=1,len=0;

        while (i<st.size())
        {
            if(st[i]==st[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len>0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        
        int siz=pat.size();
        // int cnt=0;
        // for(int i=0; i<st.size(); i++){
        //     if(lps[i]==siz)cnt++;
        // }
        
        vector<int>ans,res;
        for (int i = 0; i < st.size(); i++)
        {
            if(i>siz){
                ans.push_back(lps[i]);
            }
        }
       
        for(int i=0; i<ans.size(); i++){
            if(ans[i]==siz){
                int index=(i+1)-siz;
                res.push_back(index+1);
            }
        }
        
        if(res.size()==0){
            cout<<"Not Found\n";
            cout<<endl;
            continue;
        }
        cout<<res.size()<<endl;
        for(int i=0; i<res.size(); i++){
            cout<<res[i]<<" ";
        }cout<<endl;
        cout<<endl;
        
        
        
    }
    
}