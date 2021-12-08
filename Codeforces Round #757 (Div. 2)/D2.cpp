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


ll x[20000007],ans[20000007];
bool c[5007];
vector<ll> dv,chk[20000007],p,ok;

void compute(){
    vector<pair<ll,ll>> temp;
    for(ll i=0,c=0;i<ok.size();i++){
        c++;
        if(i+1==ok.size() || ok[i]!=ok[i+1]){
            temp.pb({ok[i],c});
            c=0;
        }
    }
    vector<ll> d;
    d.pb(1);
    x[1]++;
    for(ll i=0;i<temp.size();i++){
        vector<ll> t;
        for(ll j=1,v=1;j<=temp[i].second;j++){
            v*=temp[i].first;
            for(ll k=0;k<d.size();k++){
                ll y=d[k]*v;
                t.pb(y);
                if(!x[y]){
                    dv.pb(y);
                    chk[y]=chk[d[k]];
                    chk[y].pb(temp[i].first);
                }
                x[y]++;
            }
        }
        for(ll j=0;j<t.size();j++){
            d.pb(t[j]);
        }
    }
}

int main()
{   

    for(ll i=2;i*i<=20000000;i++){
        if(!c[i]){
            p.pb(i);
            for(ll j=i;j*j<=20000000;j+=i)
                c[j]=1;
        }
    }
    
    ll n,m=0;
    scanf("%lli",&n);

    for(ll i=0;i<n;i++){
        ll v;
        scanf("%lli",&v);
        m=max(m,v);

        ok.clear();
        for(ll j=0;j<p.size() && p[j]*p[j]<=v;j++){
            while(!(v%p[j])){
                ok.pb(p[j]);
                v/=p[j];
            }
        }
        if(v!=1) ok.pb(v);
        compute();
    }
    for(ll i=1;i<=m;i++) ans[i]=(i-1)*x[i]+n;
    
    dv.pb(1);
    sort(all(dv));
    for(ll j=dv.size()-1;j>=0;j--){
        ll d=dv[j];
        //cout<<d<<" :";
        for(ll i=0;i<chk[d].size();i++){
            //cout<<" "<<chk[d][i];
            ll v=d/chk[d][i];
            ans[v]=max(ans[v],(v-1)*(x[v]-x[d])+ans[d]);
        }
        //cout<<endl;
    }
    printf("%lli\n",ans[1]);

    return 0;
}