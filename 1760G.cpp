#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
typedef vector<bool> vb;
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
void dfs(ll par, ll node, vvl &adj, vl &xori, ll b, map<pll, ll> &gxori, ll flag){
    for(auto i:adj[node]){
        if(flag == 1 || i != b){
            if(i == par){ continue; }
            xori[i] = xori[node]^gxori[mp(node, i)];
            dfs(node, i, adj, xori, b, gxori, flag);
        }
    }
}
 
void solve(){
    ll n, a, b;
    cin>>n>>a>>b;
    vvl adj(n+1);
    ll dum, dum1;
    map<pair<ll, ll>, ll> gxori;
    for(ll i =0; i<n-1; i++){
        ll dum2;
        cin>>dum>>dum1>>dum2;
        adj[dum].pb(dum1);
        adj[dum1].pb(dum);
        gxori[mp(dum, dum1)] = dum2;
        gxori[mp(dum1, dum)] = dum2;
    }
    vl xori(n+1, -1);
    xori[a] = 0;    
    ll flag = 0;
    dfs(-1, a, adj, xori, b, gxori, flag);
    // cout<<xori<<'\n';
    sort(xori.begin(), xori.end());
    vl xori2(n+1, -1);
    flag = 1;
    xori2[b] = 0;
    dfs(-1, b, adj, xori2, a, gxori, flag);
    for(ll i = 1; i<=n; i++){
        if(xori2[i] != -1 && i != b){
            if(binary_search(xori.begin(), xori.end(), xori2[i])){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while(t--) solve();
    return 0;
}