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
        ll n;
        cin>>n;
        pair<ll,ll> x[n];
        for(ll i=0;i<n;i++){
            cin>>x[i].first;
            x[i].second=i+1;
        }
        sort(x,x+n,greater<pair<ll,ll>>());
        ll ans[n+1],p=0;
        ans[0]=0;
        for(ll i=0,c=1;i<n;i+=2,c++){
            ans[x[i].second]=c;
            p+=2*c*x[i].first;
        }
        for(ll i=1,c=-1;i<n;i+=2,c--){
            ans[x[i].second]=c;
            p+=2*(-c)*x[i].first;
        }
        cout<<p<<endl;
        for(ll i=0;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}