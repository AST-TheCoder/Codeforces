//Problem link: https://codeforces.com/contest/1509/problem/C
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

map<ll,ll> cnt;
vector<ll> x;
ll dp[2007][2007];

ll solve(ll i,ll j){
	if(i==j) return 0;
	if(dp[i][j]) return dp[i][j];
	ll p=abs(x[j]-x[i])*cnt[x[i]]+solve(i+1,j);
	ll q=abs(x[j]-x[i])*cnt[x[j]]+solve(i,j-1);
	return dp[i][j]=min(p,q);
}

int main()
{	

	ll n;
	cin>>n;

	for(ll i=0;i<n;i++){
		ll p;
		cin>>p;
		if(cnt[p]==0) x.pb(p);
		cnt[p]++;
	}

	sort(all(x));
	
	ll ans=solve(0,x.size()-1);
	cout<<ans<<endl;

	return 0;
}
