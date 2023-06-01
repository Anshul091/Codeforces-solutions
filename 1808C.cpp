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
vl printDigit(ll N)
{
    vl arr;
    ll j, r;
    while (N != 0) {
        r = N % 10;
        arr.pb(r);
        N = N / 10;
    }
    reverse(arr.begin(), arr.end());
    return arr;
}
ll getDigit(vl v){
    ll ans = 0;
    ll p = 1;
    for(ll i = v.size()-1; i>=0; i--){
        ans += p*v[i];
        p *= 10;
    }
    return ans;
}
ll checker(vl &maxi, vl &mini, ll k, vl &dum, ll i, bool del){
    if(k == 0){
        return dum[0]+1;
    }
    for(ll m = dum[k] + del; m < 10; m++){
        if(max(maxi[k-1], m) - min(mini[k-1], m) <= i) return m;
    }
    return -1;
}
void solve(ll t){
    ll l, r;
    cin>>l>>r;
    // if(l == 1 && r == 71) flag = 1;
    // if(flag == 1){
    // if(t == 20 || t == 19){
    //     cout<<l<<"        "<<r<<'\n';
    // }
    // else return;
    // }
    ll ans = 0;
    ll cnt = 0;
    vl v1 = printDigit(l);
    vl v2 = printDigit(r);
    if(l < 10){
        cout<<l<<'\n';
        return;
    }
    if(v2.size() > v1.size()){
        for(ll i = 0; i<v1.size(); i++){
            cout<<"9";
        }
        cout<<'\n';
        return;
    }
    ll ans2 = l;
    for(ll i = 0; i<10; i++){
        vl dum = v1;
        ll mini = v1[0];
        vl minia;
        vl maxia;
        ll maxi = v1[0];
        ll safe = 0;
        for(ll j = 0; j<v1.size(); j++){
            mini = min(v1[j], mini);
            minia.pb(mini);
            maxi = max(v1[j], maxi);
            maxia.pb(maxi);
            // cout<<maxi<<'\n';
            if(maxi - mini > i){
                for(ll k = j; k>= 0; k--){
                    if(checker(maxia, minia, k, dum, i, k != j) == -1) continue;
                    else{
                        // cerr<<i<<"        "<<k<<'\n';
                        dum[k] = checker(maxia, minia, k, dum, i, k != j);
                        j = k+1;
                        while(j<v1.size()){
                            if(k > 0)
                            dum[j] = max(dum[k], maxia[k-1])-i;
                            else dum[j] = dum[k]-i;
                            if(dum[j] < 0) dum[j] = 0;
                            j++;
                        }
                        break;
                    }
                }
            }
        }
        // cout<<i<<"       "<<getDigit(dum)<<'\n';
        if(getDigit(dum) <= r  && getDigit(dum)>= l){
            ans2 = getDigit(dum);
            break;
        }
    }
    cout<<ans2<<'\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // #endif
    ll t; cin>>t;
    while(t--) solve(t);
    return 0;
}