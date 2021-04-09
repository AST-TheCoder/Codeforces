//Problem link: https://codeforces.com/contest/1504/problem/D
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

ll p[107][107];

int main()
{	
	

	ll n;
	cin>>n;

	queue<pair<ll,ll>> x,y;

	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if((i+j)%2) y.push({i,j});
			else x.push({i,j});
		}
	}

	while(!x.empty() && !y.empty()){
		ll c;
		cin>>c;
		if(c==1){
			pair<ll,ll> ok=y.front();
			y.pop();
			cout<<2<<" "<<ok.first<<" "<<ok.second<<endl;
			p[ok.first][ok.second]=2;
		}
		else{
			pair<ll,ll> ok=x.front();
			x.pop();
			cout<<1<<" "<<ok.first<<" "<<ok.second<<endl;
			p[ok.first][ok.second]=1;
		}
	}

	queue<pair<ll,ll>> need;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(!p[i][j]){
				need.push({i,j});
			}
		}
	}

	pair<ll,ll> m;
	m.second=3;
	if(x.size()) m.first=1;
	else m.first=2;

	while(!need.empty()){
		ll c;
		cin>>c;
		pair<ll,ll> ok=need.front();
		need.pop();
		if(c==m.first) cout<<m.second<<" "<<ok.first<<" "<<ok.second<<endl;
		else cout<<m.first<<" "<<ok.first<<" "<<ok.second<<endl;
	}

	return 0;
}
