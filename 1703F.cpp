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
struct SegTree{
    ll size;
    vl tree_arr;
    
    void initialize(ll n){
        size = 1;
        while (size < n) size *= 2;
        tree_arr.assign(2*size, 0);                 // Set INF for min
    }
    ll access(ll ind){
        return tree_arr[tree_arr.size()-size-1+ind];
    }
    
    ll combine(ll a, ll b) {return a+b;}                // Set min or max or add
    
    void upd(ll ind, ll val, ll x, ll lx, ll rx){
        if (lx == rx - 1) {tree_arr[x] = val; return;}
        if (ind < (lx + rx)/2) upd(ind, val, 2*x+1, lx, (lx + rx)/2);
        else upd(ind, val, 2*x+2, (lx + rx)/2, rx);
        tree_arr[x] = combine(tree_arr[2*x+1], tree_arr[2*x+2]);
    }
    
    void upd(ll ind, ll val){                               // ind has 0 based indexing
        upd(ind, val, 0, 0, size);
    }
 
    ll query(ll l, ll r, ll x, ll lx, ll rx){
        if (lx >= r || rx <= l) return 0;                   // Set INF for min
        if (lx >= l && rx <= r) return tree_arr[x];
        ll query1 = query(l, r, 2*x+1, lx, (lx + rx)/2);
        ll query2 = query(l, r, 2*x+2, (lx + rx)/2, rx);
        return combine(query1, query2);
    }
 
    ll query(ll left, ll right){// answers query from left to right-1 (0 based indexing)
        return query(left, right, 0, 0, size);
    }
};
void solve(){
    ll n;
    cin>>n;
    vl v(n);
    cin>>v;
    SegTree s;
    s.initialize(n+5);
    vl w;
    for(ll i = 0; i<n; i++){
        if(v[i] < i+1) w.pb(i+1);
    }
    ll ans = 0;
    for(ll j = w.size() - 1; j>=0; j--){
        ans += s.query(w[j] + 1, n);
        ll dum = s.query(v[w[j]-1], v[w[j]-1]+1);
        s.upd(v[w[j]-1], dum+1);
        // cout<<ans<<'\n';
    }
    cout<<ans<<'\n';
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