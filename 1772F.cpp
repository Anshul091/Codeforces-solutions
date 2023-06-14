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
void solve(){
    ll n, m, k;
    cin>>n>>m>>k;
    vector<vector<string>> v;
    for(ll i = 0; i<k + 1; i++){
        vector<string> w;
        for(ll j = 0; j<n; j++){
            string s;
            cin>>s;
            w.pb(s);
        }
        v.pb(w);
    }
    vector<string> initial(n, string(m, '.'));
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            ll flag = 0;
            for(ll r = 0; r < k + 1; r++){
                if(v[r][i][j] != v[0][i][j]) flag = 1;
            }
            if(flag == 0) initial[i][j] = v[0][i][j];
        }
    }
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            if(initial[i][j] == '.'){
                initial[i][j] = 97 - initial[i-1][j];
            }
        }
    }

    vpl change;
    for(ll i = 0; i<k + 1; i++){
        ll dif = 0;
        for(ll j = 0; j < n; j++){
            for(ll r = 0; r < m; r++){
                if(v[i][j][r] != initial[j][r]) dif++;
            }
        }
        change.pb({dif, i});
    }
    sort(all(change));
    cout<<change[0].second + 1<<'\n';
    vvl ans;
    for(ll i = 1; i <= k; i++){
        ll ind = change[i].second;
        for(ll j = 0; j<n; j++){
            for(ll r = 0; r < m; r++){
                if(v[ind][j][r] != initial[j][r]){
                    ans.pb({1, j + 1, r + 1});
                }
            }
        }
        ans.pb({2, ind + 1});
        initial = v[ind];
    }
    cout<<ans.size()<<'\n';
    for(ll i = 0; i<ans.size(); i++){
        cout<<ans[i]<<'\n';
    }
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