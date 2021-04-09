//Problem link: https://codeforces.com/contest/1504/problem/A
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
		string s;
		cin>>s;
		ll id=-1,n=s.size();
		for(ll i=0;i<n;i++){
			if(s[i]!='a'){
				id=i+1;
				break;
			}
		}
		if(id==-1){
			cout<<"NO"<<endl;
			continue;
		}
		if(n%2 && id==(n+1)/2) id--;
		else if(id>n/2) id=n-id;
		else id=n-id+1;
		cout<<"YES"<<endl;
		for(ll i=0;i<id;i++) cout<<s[i];
		cout<<'a';
		for(ll i=id;i<n;i++) cout<<s[i];
		cout<<endl;
	}

	return 0;
}
