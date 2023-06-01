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
const double PI = 3.141592653589793;
const int MOD = 1e9+7;
const int mod = 998244353;
const int inf = INT_MAX;
const ll INF = INT_MAX;
 
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
    vpl v(n);
    vl b(n);
    for(ll i = 0; i<n; i++){
        cin>>v[i].first;
        cin>>v[i].second;
        b[i] = v[i].second;
    }
    sort(v.begin(), v.end());
    for(ll i = 0; i<n; i++) b[i] = v[i].second;
    vl maxi(n+1, 0);
    for(ll i = n-1; i>=0; i--)          maxi[i] = max(maxi[i+1], b[i]);
    ordered_set o;
    ll ans = INF;
    for(ll i = 0; i<n; i++){
        if(i != 0)
        o.insert(b[i-1]);
        ll pos = o.order_of_key(v[i].first);
        // cout<<v[i].first<<'\n';
        ll element;
        if (pos >= o.size())   element = -INF;
        else
        element = *(o.find_by_order(pos));
        pos--;
        ll element2;
        if(pos < 0) element2 = -INF;
        else element2 = *(o.find_by_order(pos));
        ll act_element;
        if(abs(element-v[i].first) <= abs(element2-v[i].first)){ act_element = element;
        }
        else act_element = element2;
        // cerr<<act_element<<'\n';

        ll comp = max(act_element, maxi[i+1]);
        ll comp2 = max(element2, maxi[i+1]);
        ans = min(ans, abs(comp-v[i].first));
        ans = min(ans, abs(comp2-v[i].first));
    }
    cout<<ans<<'\n';
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