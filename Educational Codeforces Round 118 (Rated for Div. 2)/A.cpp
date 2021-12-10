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
#define min_heap priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main()
{   

    ll t;
    cin>>t;

    while(t--){
        ll a,b;
        string p,q;
        cin>>p>>a;
        cin>>q>>b;

            

        ll ok=0;
        //cout<<p<<" "<<q<<endl;
        if(p.size()+a<q.size()+b) ok=-1;
        else if(p.size()+a>q.size()+b) ok=1;
        else{
        for(ll i=0;i<p.size() && i<q.size();i++){
            if(p[i]>q[i]) ok=1;
            if(p[i]<q[i]) ok=-1;
            if(p[i]!=q[i]) break;
        }
        if(!ok){
            if(p.size()<q.size()){
                for(ll i=p.size();i<q.size();i++){
                    if(q[i]!='0'){
                        ok=-1;
                        break;
                    }
                }
            }
            if(p.size()>q.size()){
                for(ll i=q.size();i<p.size();i++){
                    if(p[i]!='0'){
                        ok=1;
                        break;
                    }
                }
            }
        }
    }

        if(ok==1) cout<<">"<<endl;
        if(ok==0) cout<<"="<<endl;
        if(ok==-1) cout<<"<"<<endl;

    }    

    return 0;
}