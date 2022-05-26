#include <bits/stdc++.h>
#define ll long long
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcountll(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define endl "\n" //delete if interactive
using namespace std;

void __print(int x) {cerr << x;}
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
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int mod = 1e9 + 7;
long long add(long long a , long long b)
{
    long long ans = ((a % mod) + (b % mod)) % mod;
    if (ans < 0)ans += mod;
    return ans;
}
const int N = 7.5e5 + 1 ;

void solve()
{
    int n ;
    cin >> n ;
    vector<int> arr(n);
    for (int i = 0 ; i < n ; i++)
        cin >> arr[i] ;
    sort(all(arr));

    vector<int>res(N, 0);
    for (int i : arr) res[i] = 1 ;


    int ans = 0 ;

    for (int i = 0 ; i < N ; i++) {
        if (res[i]) {
            for (int j = i + i ; j < N ; j += i)
                if (res[j])
                    res[j] = add(res[j]   , res[i]);

            ans = add(ans , res[i]);
        }

    }
    cout << ans << endl;
}
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >> t;
    while (t--)
    {solve();}
    return 0;

}


