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

// bool good(vl &v, ll mid){

//     // ll ind = upper_bound(all(v), v[0] + 2*mid) - v.begin();
//     // if(ind >= n-2) return true;
//     // ll ind2 = upper_bound(all(v), v[ind] + 2*mid) - v.begin();
//     // if(ind2 >= n-1) return true;
//     // ll ind3 = upper_bound(all(v), v[ind2] + 2*mid) - v.begin();
//     // if(ind3 >= n) return true;
//     // return false;
// }

void solve(){
    ll n;
    cin>>n;
    vl v(n);
    cin>>v;
    sort(all(v));
    ll l = 0, r = v[n-1];
    ll ans = -1;
    while(l <= r){
	    ll mid = l + (r-l)/2;
        bool flag = false;
        ll ind = upper_bound(all(v), v[0] + 2*mid) - v.begin();
        if(ind >= n-2) flag = true;
        ll ind2 = upper_bound(all(v), v[ind] + 2*mid) - v.begin();
        if(ind2 >= n-1) flag = true;
        ll ind3 = upper_bound(all(v), v[ind2] + 2*mid) - v.begin();
        if(ind3 >= n) flag = true;
	    if(flag){
	    	ans = mid;
	    	r = mid-1;
	    }
	    else{
	    l = mid+1;
	    }
    }
    cout<<ans<<'\n';
    // for(ll i = 0; i < n; i++){
    //     ll dum = (v[i] - v[0] + 1)/2;
    //     if(i >= n-2){
    //         ans = min(ans, dum);
    //         break;
    //     }
    //     ll ind = upper_bound(all(v), v[i+1] + 2*dum) - v.begin();
    //     ll ind2 = upper_bound(all(v), v[ind] + 2*dum) - v.begin();
    //     if(ind2 == n){
    //         ans = min(ans, dum);
    //         return;
    //     }
    //     ll dum1 = v[ind] - v[i + 1] + 1 >> 1;
    //     ll dum2 = 
    // }
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