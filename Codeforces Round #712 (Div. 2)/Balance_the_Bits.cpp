//Problem link: https://codeforces.com/contest/1504/problem/C
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
		string s;
		cin>>s;
		ll o=count(all(s),'1');
		ll z=count(all(s),'0');
		if(o%2 || z%2 || s[0]=='0' || s[n-1]=='0'){
			cout<<"NO"<<endl;
			continue;
		}
		ll c=0,x=0;
		string a,b;
		cout<<"YES"<<endl;
		for(ll i=0;i<n;i++){
			if(s[i]=='1'){
				if(x<o/2){
					a+='(';
					b+='(';
				}
				else{
					a+=')';
					b+=')';
				}
				x++;
			}
			else{
				if(!c){
					a+=')';
					b+='(';
					c=1;
				}
				else{
					a+='(';
					b+=')';
					c=0;
				}
			}
		}
		cout<<a<<endl<<b<<endl;
	}

	return 0;
}
