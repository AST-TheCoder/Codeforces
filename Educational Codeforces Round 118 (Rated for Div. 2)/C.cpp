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
        ll n,h;
        cin>>n>>h;

        ll a[n],b[n];
        for(ll i=0;i<n;i++) cin>>a[i];

        for(ll i=1;i<n;i++) b[i-1]=a[i]-a[i-1];
        b[n-1]=h;
        sort(b,b+n);

        for(ll i=0;i<n;i++){
            ll x=h/(n-i)+(h%(n-i)!=0);
            if(x<=b[i]){
                cout<<x<<endl;
                break;
            }
            h-=b[i];
        }
    }    

    return 0;
}