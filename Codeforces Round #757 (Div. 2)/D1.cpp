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


ll x[5000007],ans[5000007],cnt[5000007];

int main()
{   
    
    ll n,m=0;
    cin>>n;

    for(ll i=0;i<n;i++){
        ll v;
        cin>>v;
        m=max(m,v);

        for(ll j=1;j*j<=v;j++){
            if(v%j) continue;
            x[j]++;
            if(v/j!=j) x[v/j]++;
        }
    }

    for(ll i=m;i>=1;i--){
        ans[i]=i*x[i]+n-x[i];
        cnt[i]=x[i];
    }
    

    for(ll i=m;i>=1;i--){
        for(ll j=2*i;j<=m;j+=i){
            if(ans[i]<i*(x[i]-cnt[j])+ans[j]-x[i]+cnt[j]){
                ans[i]=i*(x[i]-cnt[j])+ans[j]-x[i]+cnt[j];
                //cnt[i]=cnt[j]+x[i];
            }
        }
    }
    cout<<ans[1]<<endl;

    return 0;
}