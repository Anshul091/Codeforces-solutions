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
// char query1(ll i){
//     cout<<"? 1 ";
//     cout<<i<<endl;
//     char c;
//     cin>>c;
//     return c;
// }


bool good(ll mid, vector<pll> &w, ll cur, ll end){
    ll ind = w[mid].first + 1;
    cout<<"? 2 "<<ind<<' '<<end<<endl;
    ll dum;
    cin>>dum;
    if(dum == w.size() - mid) return true;
    else return false;
}


char binarysearch(vl &v, ll cur, ll e){
    vector<pll> w;
    for(ll i = 0; i<26; i++){
        if(v[i] != -1){
            w.pb(mp(v[i], i));
            // s.pb(i + 97);
        }
    }
    sort(all(w));
    ll start = 0, end = w.size() - 1;
    ll ans = -1;
    while(start <= end){
        ll mid = start + (end-start)/2;
        // cout<<start<<' '<<end<<' '<<mid<<endl;
        if(good(mid, w, cur, e)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    char c = w[ans].second + 97;
    assert(ans != -1);
    return c;
}
void solve(){
    ll n;
    cin>>n;
    string ans(n, '.');
    ll dist;
    ll cur = 0;
    vl v(26, -1);
    for(ll i = 0; i<n; i++){
        if(i == 0){
            cout<<"? 1 1"<<endl;
            cin>>ans[0];
            cur++;
            v[ans[0] - 97] = i;
            continue;
        }
        cout<<"? 2 1 "<<i + 1<<endl;
        ll dum;
        cin>>dum;
        if(dum == cur){
            // cout<<cur<<' '<<i+1<<endl;
            ans[i] = binarysearch(v, cur, i + 1);
            v[ans[i] - 97] = i;
        }
        else{
            cur++;
            cout<<"? 1 "<<i + 1<<endl;
            cin>>ans[i];
            v[ans[i] - 97] = i;
        }
    }
    cout<<"! "<<ans<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);c
    // #endif
    ll t; t = 1;
    while(t--) solve();
    return 0;
}