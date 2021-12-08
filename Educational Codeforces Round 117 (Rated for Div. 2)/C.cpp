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
        ll k,x,ans=0;
        cin>>k>>x;
        if(k*(k+1)>=2*x){
            ans=(sqrt(1+8*x)-1)/2;
            if(ans*(ans+1)<2*x) ans++;
            cout<<ans<<endl;
        }
        else{
            ans=k;
            x-=(k*(k+1))/2;
            k--;
            x=(k*(k+1))/2-x;
            ll p=0;
            if(x>0) p=(sqrt(1+8*x)-1)/2;
            ans+=k-p;
            cout<<ans<<endl;
        }
    }

    return 0;
}