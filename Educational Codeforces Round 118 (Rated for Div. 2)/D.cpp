#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 100000000000000
#define min_heap priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main()
{   

    ll t;
    cin>>t;

    while(t--){
        ll n,mod=998244353;
        cin>>n;

        vector<ll> id[n+5];

        ll p[n+1];
        p[0]=1;
        for(ll i=1;i<=n;i++){
            p[i]=(p[i-1]*2)%mod;
        }

        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;

            id[x].pb(i);
        }

        ll ans[n],val[n];
        memset(ans,0,sizeof(ans));
        memset(val,0,sizeof(val));

        ll sum=0;

        for(ll i=0;i<=n;i++){
            for(ll j=(ll)id[i+2].size()-1,s=0;j>=0;j--){
                ll v=lower_bound(all(id[i]),id[i+2][j])-id[i].begin();
                v=id[i].size()-v;
                v+=id[i+2].size()-j-1;
                s=(s+p[v])%mod;
                val[id[i+2][j]]=s;
            }
            for(ll j=0,s=0;j<id[i].size();j++){
                ll v=id[i][j];
                ll x;
                if(!i) x=1;
                else{
                    ll c=lower_bound(all(id[i-1]),v)-id[i-1].begin();
                    c--;
                    if(c<0) x=0;
                    else x=ans[id[i-1][c]];
                }

                x=(x+s)%mod;
                s=(s+x)%mod;
                ans[v]=x;
                if(j) ans[v]+=ans[id[i][j-1]];
                sum=(sum+x)%mod;
                ll temp=lower_bound(all(id[i+2]),v)-id[i+2].begin();
                if(temp!=id[i+2].size()){
                    x=(x*val[id[i+2][temp]])%mod;
                    sum=(sum+x)%mod;
                }
            }
        }
        sum=(sum+p[id[1].size()]-1)%mod;
        cout<<sum<<endl;
    }    

    return 0;
}