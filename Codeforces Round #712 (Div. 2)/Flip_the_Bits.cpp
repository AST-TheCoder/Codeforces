//Problem link: https://codeforces.com/contest/1504/problem/B
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

	read:
	while(t--){
		ll n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		ll cnt[n];
		memset(cnt,0,sizeof(cnt));
		if(a[0]=='1') cnt[0]=1;
		else cnt[0]=-1;
		for(ll i=1;i<n;i++){
			cnt[i]=cnt[i-1];
			if(a[i]=='1') cnt[i]++;
			else cnt[i]--;
		}
		ll m=0;
		for(ll i=n-1;i>=0;i--){
			if(m%2 && a[i]==b[i]){
				if(cnt[i]){
					cout<<"NO"<<endl;
					goto read;
				}
				m++;
			}
			else if(!(m%2) && a[i]!=b[i]){
				if(cnt[i]){
					cout<<"NO"<<endl;
					goto read;
				}
				m++;
			}
		}
		cout<<"YES"<<endl;
	}

	return 0;
}
