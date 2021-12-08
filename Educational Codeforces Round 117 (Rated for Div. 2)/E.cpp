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

ll cnt[200007];

int main()
{


    ll n,k=0;
    cin>>n;

    pair<ll,ll> a[n+1];
    for(ll i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        k=max(k,a[i].second);
    }
    ll p=min(n,k);
    double c=0.0;
    vector<ll> ans;

    for(ll i=1;i<=p;i++){
        memset(cnt,0,sizeof(cnt));
        for(ll j=1;j<=n;j++){
            cnt[a[j].first]+=min(i,a[j].second);
        }
        vector<pair<ll,ll>> x;
        for(ll j=1;j<=200006;j++){
            if(cnt[j]){
                x.pb({cnt[j],j});
            }
        }
        sort(all(x),greater<pair<ll,ll>>());
        ll s=0,v=min(i,(ll)x.size());
        for(ll j=0;j<v;j++){
            s+=x[j].first;
        }
        double temp=(double)s/(double)i;
        if(temp>c){
            c=temp;
            ans.clear();
            for(ll j=0;j<v;j++) ans.pb(x[j].second);
        }
    }
    cout<<ans.size()<<endl;
    for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}