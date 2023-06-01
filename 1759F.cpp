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
    ll n, p;
    cin>>n>>p;
    vl v(n);
    cin>>v;
    vl w = v;
    ll dum = v[n-1];
    ll dum2;
    if(n > 1)   dum2 = v[n-2];
    else dum2 = 0;
    sort(v.begin(), v.end());
    ll check = dum, upto = -1;
    for(ll i = 0; i<min(p, (ll)105); i++){
        // cout<<binary_search(v.begin(), v.end(), 0)<<'\n';
        if(!binary_search(v.begin(), v.end(), (check+p)%p)){
            upto = (check+p)%p;
            break;
        }
        check--;
    }
    if(upto == -1){
        cout<<"0\n";
        return;
    }
    if(upto >= dum){
        cout<<upto-dum<<'\n';
        return;
    }
    for(ll i = n-2; i>=-1; i--){
        if(i < 0){
            v.pb(1);
            break;
        }
        if(w[i] != p-1){
            v.pb(w[i]+1);
            break;
        }
    }

    ll ans = p - dum;
    sort(v.begin(), v.end());
    check = dum, upto = -1;
    // cout<<v<<'\n';
    for(ll i = 0; i<min(p, (ll)105); i++){
        if(!binary_search(v.begin(), v.end(), (check+p)%p)){
            upto = (check+p)%p;
            break;
        }
        check--;
    }
    // cout<<upto<<"\n";
    if(upto != -1 && upto < dum)
    ans = max(ans, ans + upto);
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
    ll flag = 0;
    while(t--) solve();
    return 0;
}