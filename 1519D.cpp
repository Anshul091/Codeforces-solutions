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
void solve(){
    ll n;
    cin>>n;
    vl a(n), b(n);
    cin>>a>>b;
    vvl dp(n, vl(n));
    ll prod = 0;
    for(ll i = 0; i<n; i++){
        prod += a[i]*b[i];
    }
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<n; j++){
            // if(i >= 0) cerr<<dp[0][0]<<'\n';
            if(j <= i) dp[0][i] += a[j]*b[i-j];
            else dp[0][i] += a[j]*b[j];
        }
    }
    dp[n-1][n-1] = prod;
    // cerr<<dp[0][0]<<' '<<prod<<'\n';
    for(ll i = n-2; i>0; i--){
        for(ll j = i; j<n; j++){
            if(i == j) dp[i][j] = prod;
            else if(i == j-1) dp[i][j] = prod - a[i]*b[i] - a[j]*b[j] + a[i]*b[j] + a[j]*b[i];
            else dp[i][j] = dp[i+1][j-1] - a[i]*b[i] - a[j]*b[j] + a[i]*b[j] + a[j]*b[i];
        }
    }
    ll mn = -INF;
    // cerr<<dp[0][0]<<'\n';
    // for(ll i = 0; i<n; i++){ 
    //     for(ll j = 0; j<n; j++)
    //         cerr<<dp[i][j]<<' ';
    //     cerr<<'\n';
    // }
    for(ll i = 0; i<n; i++){
        for(ll j = i; j<n; j++){
            if(dp[i][j] > 0) mn = max(mn, dp[i][j]);
        }
    }
    cout<<mn<<'\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // #endif
    ll t; t = 1;
    while(t--) solve();
    return 0;
}