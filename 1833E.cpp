#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
typedef vector<pll> vpl;
const double PI = 3.141592653589793;
const int MOD = 1e9+7;
const int mod = 998244353;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
 
#define pb push_back
#define mp make_pair
 
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
void dfs(ll node, vvl &adj, vl &visited, vl &degree, ll &noof2s){
    visited[node] = 1;
    if(degree[node] == 1) noof2s = 1;
    for(auto i:adj[node]){
        if(!visited[i])
            dfs(i, adj, visited, degree, noof2s);
    }
}
void solve(){
    ll n;
    cin>>n;
    vvl adj(n);
    for(ll i = 0; i<n; i++){
        ll dum;
        cin>>dum;
        dum--;
        adj[dum].pb(i);
        adj[i].pb(dum);
    }
    vl visited(n);
    ll comp = 0;
    ll mini = 1;
    vl degree(n);
    for(ll i = 0; i<n; i++){
        set<ll> s;
        for(ll j = 0; j<adj[i].size(); j++){
            s.insert(adj[i][j]);
        }
        degree[i] = s.size();
    }
    // cout<<degree<<'\n';
    ll ans = 0, flag = 0;
    for(ll i = 0; i<n; i++){
        if(!visited[i]){
            comp++;
            ll noof2s = 0;
            dfs(i, adj, visited, degree, noof2s);
            if(noof2s == 0) ans++;
            else if(noof2s == 1 && flag == 0){
                flag = 1;
                ans++;
            }
        }
    }
    cout<<ans<<' '<<comp<<'\n';
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