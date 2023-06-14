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
vector<ll> f(ll cursm, ll i, ll n, vector<ll>& arr, vector<vector<vector<ll>>>& memo) {
    if (memo[cursm][i] != vector<ll>{-1}) {
        return memo[cursm][i];
    }

    if (i == n) {
        return cursm == 0 ? vector<ll>{1} : vector<ll>{};
    }

    vector<ll> v1 = f(cursm + arr[i], i + 1, n, arr, memo);
    if (!v1.empty()) {
        v1.pb(arr[i]);
        memo[cursm][i] = v1;
        return v1;
    }

    vector<ll> v2;
    if (cursm >= arr[i]) {
        v2 = f(cursm - arr[i], i + 1, n, arr, memo);
    }
    if (!v2.empty()) {
        v2.pb(-arr[i]);
        memo[cursm][i] = v2;
        return v2;
    }

    return vector<ll>{};
}
void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;

    if (n & 1) {
        cout << "NO" << "\n";
        return;
    }

    vector<ll> arr{1};
    for (ll i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            arr.back() += 1;
        } else {
            arr.pb(1);
        }
    }

    vector<vector<vector<ll>>> memo(n + 1, vector<vector<ll>>(n + 1, vector<ll>{-1}));

    vector<ll> stack = f(0, 0, arr.size(), arr, memo);
    if (stack.empty()) {
        cout << "NO" << "\n";
        return;
    }

    vector<char> ans;
    for (ll i = 1; i < stack.size(); i++) {
        if (stack[i] > 0) {
            ans.insert(ans.end(), stack[i], '(');
        } else {
            ans.insert(ans.end(), -stack[i], ')');
        }
    }
    reverse(ans.begin(), ans.end());

    cout<<"YES\n";
    for (ll i = 0; i < ans.size(); i++) {
        cout<<ans[i];
    }
    cout<<'\n';
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