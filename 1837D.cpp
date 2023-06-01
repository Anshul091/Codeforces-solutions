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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll cnt1 = 0, cnt2 = 0;
    for(ll i = 0; i<n; i++){
        if(s[i] == '(') cnt1++;
        else cnt2++;
    }
    if(cnt1 != cnt2){
        cout<<"-1\n";
        return;
    }
    vl arr(n);
    for(ll i = 0; i<n; i++){
        if(s[i] == '(') arr[i] = 1;
        else arr[i] = -1;
    }
    ll sm = 0;
    ll possible = 1;
    for(auto i:arr){
        sm += i;
        if (sm == 0) continue;
        if (sm*arr[0] < 0){
            possible = 0;
            break;
        }
    }
    if (possible){
        cout<<"1\n";
        for(ll i = 0; i< n; i++){
            cout<<"1 ";
        }
        cout<<"\n";
        return;
    }
    else{
        ll sm = 0;
        vl ans(n, 2);
        if(arr[0] == -1){
            for(ll i = 0; i<n; i++)
                arr[i] *= -1;
        }

        ll negone = n >> 1;
        sm = 0;
        for(ll i = 0; i<n; i++){
            ll cur = arr[i];
            if(cur == 1){
                if(sm + 1 <= negone){
                    ans[i] = 1;
                    sm++;
                }
            }
            else{
                if(sm - 1 >= 0){
                    ans[i] = 1;
                    sm--;
                }
                negone--;
            }
        }
        cout<<"2\n";
        cout<<ans<<'\n';
    }
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







        // cout<<"2\n";
        // vl ans(n, 1);
        // cnt2 = 0;
        // flag = 0;
        // if(s[0] == '(') flag++;
        // else flag--;
        // for(ll i = 0; i<n; i++){
        //     flag1 = 0;
        //     if(s[i] == '(') flag1++;
        //     else flag1--;
        //     if((cnt2+flag1)*flag >= 0){
        //         cnt2 += flag1;
        //         ans[i] = 2;
        //     }
        // }
        // cout<<ans<<'\n';