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
        ll n,x,b;
        cin>>n>>x>>b;
        ll a[n+1];
        for(ll i=1;i<=n;i++){
            a[i]=n-i+1;
        }
        for(ll i=1;i<=n/2;i++){
            if(a[i]==b){
                swap(a[i],a[n/2+1]);
                break;
            }
        }
        for(ll i=n/2+1;i<=n;i++){
            if(a[i]==x){
                swap(a[i],a[n/2]);
                break;
            }
        }
        sort(a+1,a+n/2+1);
        sort(a+n/2+1,a+n+1);
        if(a[1]!=x || a[n]!=b) cout<<-1<<endl;
        else{
            for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
            cout<<endl;
        }
    }

    return 0;
}