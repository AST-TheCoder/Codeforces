//Problem link: https://codeforces.com/contest/1509/problem/A
//Solution:

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
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

		vector<ll> x,y;
		for(ll i=0;i<n;i++){
			ll p;
			cin>>p;
			if(p%2) x.pb(p);
			else y.pb(p);
		}
		for(ll i=0;i<x.size();i++) cout<<x[i]<<" ";
		for(ll i=0;i<y.size();i++) cout<<y[i]<<" ";
			cout<<endl;

	}

	return 0;
}
