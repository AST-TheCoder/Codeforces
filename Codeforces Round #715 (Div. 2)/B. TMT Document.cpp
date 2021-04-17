//Problem link: https://codeforces.com/contest/1509/problem/B
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

		queue<ll> q,p;
		for(ll i=0;i<s.size();i++){
			if(s[i]=='T') q.push(i);
			else{
				if(q.empty()){
					cout<<"NO"<<endl;
					goto read;
				}
				ll x=q.front();
				s[x]='X';
				q.pop();
			}
		}
		for(ll i=s.size()-1;i>=0;i--){
			if(s[i]=='T') p.push(i);
			else if(s[i]=='M'){
				if(p.empty()){
					cout<<"NO"<<endl;
					goto read;
				}
				ll x=p.front();
				s[x]='X';
				p.pop();
			}
		}

		for(ll i=0;i<s.size();i++){
			if(s[i]=='T'){
				cout<<"NO"<<endl;
				goto read;
			}
		}
		cout<<"YES"<<endl;
	}

	return 0;
}
