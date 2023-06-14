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

ll integer_sum(ll a){
    return a*(a+ 1)>>1;
}

void solve(){
    ll n, q;
    cin>>n>>q;
    vl v(n);
    cin>>v;
    sort(v.begin(), v.end());
    ll sum = accumulate(all(v), 0LL);
    vl w = v;
    ll dum2 = n;
    for(ll i = 0; i<n; i++){
        w[i] += dum2;
        dum2--;
    }
    ll ind = min_element(all(w)) - w.begin();
    while(q--){
        ll ans;
        ll dum;
        cin>>dum;
        ll k = dum;
        if(n == 1){
            if(dum & 1){
                ans = v[0] + dum;
                dum--;
                ans -= dum/2;
            }
            else{
                ans = v[0];
                ans -= dum/2;
            }
        }
        else if(dum <= n){
            ans = v[ind] + k - ind;
            ans = max(v[ind], ans);
            // debug(dum);
        }
        else{
            ll odd = dum - n;
            ll mini = v[ind] + k - ind;
            k -= n;
            // if(ind == n-1 && odd&1){
            //     mini++;
            // }
            if(odd&1){
                mini = min(v[n-1], mini);
                k++;
            }
            // debug(mini, k);
            assert(k % 2 == 0);
            k /= 2;
            // debug(k);
            k -= sum;
            ll dif = integer_sum(dum) - integer_sum(dum - n);
            k -= dif;
            // debug(dif);
            if(odd & 1){
                k += dum - n + 1;
            }
            k += n * mini;
            // debug(k);
            if(k <= 0){
                ans = mini;
            }
            else{
                ans = mini - (k+n-1)/n;
            }
        }
        cout<<ans<<' ';
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
    ll t; t = 1;
    while(t--) solve();
    return 0;
}






