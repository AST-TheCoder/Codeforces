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
        ll a,b,x;
        cin>>a>>b>>x;

        if(a<x && b<x){
            cout<<"NO"<<endl;
            continue;
        }
        while(a>x && b>x){
            if(a>=b) a=a%b;
            else b=b%a;
        }
        if(a==x || b==x){
            cout<<"YES"<<endl;
            continue;
        }
        if(a>b) swap(a,b);
        if(!a || (b-x)%a) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}