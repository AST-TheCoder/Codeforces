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
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main()
{   
    
    ll t;
    cin>>t;

    while(t--){
        ll n,m,mod=1000000007;
        cin>>n>>m;
        pair<pair<ll,ll>,ll> x[m];
        for(ll i=0;i<m;i++){
            cin>>x[i].first.first>>x[i].first.second>>x[i].second;
        }
        sort(x,x+m);
        ll cnt[32];
        for(ll i=0;i<32;i++) cnt[i]=n;
        for(ll j=0;j<32;j++){
            for(ll i=0,p=1;i<m;i++){
                if(x[i].second%2==0 && p<=x[i].first.second){
                    cnt[j]-=(max(x[i].first.second,p)-max(x[i].first.first,p)+1);
                    p=max(x[i].first.second+1,p);
                }
                x[i].second/=2;
            }
        }
        ll p[n+1];
        p[0]=1;
        for(ll i=1;i<=n;i++) p[i]=(p[i-1]*2)%mod;
        ll ans=0;
        for(ll j=0,q=1;j<32;j++){
            //cout<<j<<" "<<cnt[j]<<endl;
            if(cnt[j]>0 && cnt[j]<=n){
                ll c=(p[cnt[j]-1]*p[n-cnt[j]])%mod;
                c=(c*q)%mod;
                ans=(ans+c)%mod;
            }
            q=(q*2)%mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}