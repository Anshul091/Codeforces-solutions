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

ll MAXN = 1e10+10;
vl fib, pref;
void fibonacci(){
    fib.resize(2, 1LL);
    while(fib.back() <= (MAXN)){
        ll ind = fib.size() - 1;
        ll dum = fib[ind] + fib[ind-1];
        fib.pb(dum);
    }
    pref.resize(fib.size());
    partial_sum(all(fib), pref.begin());
}

void solve(){
    ll n;
    cin>>n;
    vl v(n);
    cin>>v;
    if(n == 1){
        if(v[0] == 1) cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    ll sum = accumulate(all(v), 0LL);
    ll dum = 0;
    if(!binary_search(all(pref), sum)){
        cout<<"NO\n";
        return;
    }
    ll ind = 0;
    // debug(sum);
    for(ll i = 0; i<pref.size(); i++){
        ind = i;
        if(pref[i] == sum) break;
    }
    priority_queue<ll> pq;
    for(ll i = 0; i<n; i++){
        pq.push(v[i]);
    }
    ll prev = 0;
    for(ll i = ind; i>=0; i--){
        if(pq.empty() || pq.top() < fib[i]){
            cout<<"NO\n";
            return;
        }
        ll dum = pq.top();
        pq.pop();
        // debug(dum);
        if(prev != 0) pq.push(prev);
        prev = dum - fib[i];
        // debug(prev);
    }
    cout<<"YES\n";
    
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // #endif
    fibonacci();
    ll t; cin>>t;
    while(t--) solve();
    return 0;
}