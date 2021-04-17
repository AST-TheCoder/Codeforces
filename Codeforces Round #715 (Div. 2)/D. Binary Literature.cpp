//Problem link: https://codeforces.com/contest/1509/problem/D
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
		string a,b,c;
		cin>>a>>b>>c;

		string p,q;
		char ok;
		if(count(all(a),'0')>=n && count(all(b),'0')>=n){
			p=a,q=b,ok='0';
		}
		if(count(all(a),'1')>=n && count(all(b),'1')>=n){
			p=a,q=b,ok='1';
		}
		if(count(all(a),'0')>=n && count(all(c),'0')>=n){
			p=a,q=c,ok='0';
		}
		if(count(all(a),'1')>=n && count(all(c),'1')>=n){
			p=a,q=c,ok='1';
		}
		if(count(all(c),'0')>=n && count(all(b),'0')>=n){
			p=c,q=b,ok='0';
		}
		if(count(all(c),'1')>=n && count(all(b),'1')>=n){
			p=c,q=b,ok='1';
		}

		if(count(all(q),ok)>count(all(p),ok)) swap(p,q);
		string ans;
		for(ll i=0,j=0;i<p.size() || j<q.size();){
			if(i==p.size()){
				ans+=q[j];
				j++;
			}
			else if(j==q.size()){
				ans+=p[i];
				i++;
			}
			else if(p[i]==ok && q[j]==ok){
				ans+=ok;
				i++,j++;
			}
			else if(p[i]!=ok){
				ans+=p[i];
				i++;
			}
			else{
				ans+=q[j];
				j++;
			}
		}
		for(ll i=ans.size();i<3*n;i++) ans+='0';
		cout<<ans<<endl;
	}

	return 0;
}
