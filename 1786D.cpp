#include <bits/stdc++.h>
using namespace std;
 
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
 
 
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
typedef vector<pll> vpl;
typedef vector<bool> vb;
 
 
 
 
 
const double PI = 3.141592653589793;
const int MOD = 1e9+7;
const int mod = 998244353;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
 
 
 
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
 
 
 
// Operator overloads <<, >> 
template<typename T1, typename T2> // cin >> pair
istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector
istream &operator>>(istream &istream, vector<T> &v) { for (auto &it : v) { cin >> it; } return istream; }
template<typename T1, typename T2> // cout << pair
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector
ostream &operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) { cout << it << " "; } return ostream; }
 
// ================================== Template Ends ==================================
// ================================== Debug Starts ==================================
// void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// ================================== Debug Ends ==================================

void characterdeterminer(ll ind, ll &ch){
    if(ind == 0) ch = 'w';
    else if(ind == 1) ch = 'i';
    else if(ind == 2) ch = 'n';
}
void solve(){
    ll m;
    cin>>m;
    vector<vvl> adj(3, vvl(3));
    for(ll i = 0; i<m; i++){
        string s;
        cin>>s;
        sort(s.begin(), s.end());
        // cout<<s<<'\n';
        if(s != "inw"){
            vl v(3, 0);
            // cout<<v.size();
            for(ll j = 0; j<s.size(); j++){
                if(s[j] == 'w') v[0]++;
                else if(s[j] == 'i') v[1]++;
                else v[2]++;
            }
            // __print(v);
            ll mx = *max_element(v.begin(), v.end());
            ll ind = max_element(v.begin(), v.end()) - v.begin();
            ll ind2 = min_element(all(v)) - v.begin();
            ll ind3 = 3 - ind - ind2;
            adj[ind2][ind].pb(i);
            // cerr<<ind<<' '<<ind2<<' ';
            if(mx == 3) adj[ind3][ind].pb(i);
            // __print(adj[ind][ind2]);
            // cerr<<'\n';
        }
    }
    // for(ll i = 0; i<3; i++){
    //     for(ll j = 0; j<3; j++){ __print(adj[i][j]); 
    //     }
    //     cerr<<'\n';
    // }
    vvl ans;
    vl index(9, -1);
    for(ll i = 0; i<3; i++){
        ll ind = i;
        ll ind2 = (i+1)%3;
        ll ch, ch2;
        characterdeterminer(ind, ch);
        characterdeterminer(ind2, ch2);
        for(ll j = 0; j<min(adj[ind][ind2].size(), adj[ind2][ind].size()); j++){
            vl d(4);
            d[0] = adj[ind][ind2][j] + 1;
            d[2] = adj[ind2][ind][j] + 1;
            d[1] = ch2;
            d[3] = ch;
            ans.pb(d);
            index[3*ind+ind2] = j;
            index[3*ind2+ind] = j;
        }
    }
    ll flag = 1;
    if(index[1] + 1 == adj[0][1].size()) flag = 0;
    
    if(flag == 0){
        for(ll i = index[3]+1; i<adj[1][0].size(); i++){
            vl d(4), e(4);
            d[1] = 'w';         d[3] = 'n';
            d[0] = adj[1][0][index[3]+1] + 1;    d[2] = adj[0][2][index[2] + 1] + 1;
            e[1] = 'n';         e[3] = 'i';
            e[0] = adj[1][0][index[3] + 1] + 1;    e[2] = adj[2][1][index[7] + 1] + 1;
            ans.pb(d);
            ans.pb(e);
            index[3]++;
            index[2]++;
            index[7]++;
        }
    }
    else{
        for(ll i = index[1] + 1; i<adj[0][1].size(); i++){
            vl d(4), e(4);
            d[1] = 'w';         d[3] = 'i';
            d[0] = adj[2][0][index[6] + 1] + 1;    d[2] = adj[0][1][index[1] + 1] + 1;
            e[1] = 'i';         e[3] = 'n';
            e[0] = adj[2][0][index[6] + 1] + 1;    e[2] = adj[1][2][index[5] + 1] + 1;
            ans.pb(d);
            ans.pb(e);
            index[1]++;
            index[5]++;
            index[6]++;
        }
    }





    cout<<ans.size()<<'\n';
    for(ll i = 0; i<ans.size(); i++){
        for(ll j = 0; j<ans[i].size(); j++){
            if(j & 1) cout<<(char)ans[i][j]<<' ';
            else cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // #endif
    ll t; cin>>t;
    while(t--) solve();
    return 0;
}