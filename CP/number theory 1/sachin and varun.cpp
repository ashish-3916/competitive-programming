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



/*

    ax + by = d ; find no of inegral soln that satisfy this equation

    a,x,b,d,y >=0
    0 <=x <= d/a
    0 <=y <= d/b

    ( d-by )mod a = 0
    if we find smallest y(y1) rest of value would be y1+a , y1+2a .... y1+na <= d/b -> n+1 terms


    how do we find y1?
    (d-by)mod a = 0
    d%a - b%a * y%a = 0 ;

    ax + by = d ;
    y = d/b - ax/b
    y%a=(d/b)%a // is the smallest as it is less than a
    y1=(d/b)%a

    y1 = ( d%a*(b^-1)%a)%a


*/

vector<ll>ExtendedEuclid(ll a , ll b)
{
    if (b == 0)
        return {a , 1 , 0};

    vector<ll> small = ExtendedEuclid(b, a % b);

    return {small[0]  , small[2] , small[1] - (a / b) *small[2]}; // gcd , x1 , y1
}
ll MMInverse(ll a , ll m)
{
    if (__gcd(a, m) != 1) // not coprime ,,, if m is prime , use fermat little thrm
        return -1;
    vector<ll> res = ExtendedEuclid(a , m);
    return (res[1] + m ) % m; // in case res1 is neg
}

void solve()
{
    ll a , b , d ;
    cin >> a >> b >> d ;

    ll g = __gcd(a, b);

    if (d % g) { // no integral solution exists
        cout << 0 << endl;
        return;
    }
    if (d == 0) { // y= mx
        cout << 1 << endl;
        return ;
    }
    a /= g;
    b /= g;
    d /= g;
    ll mmi = MMInverse(b , a);
    if (mmi == -1 ) {
        cout << 0 << endl ;
        return ;
    }

    ll y1 = (( d % a ) * mmi) % a ;
    if (d < y1 * b) {
        cout << 0 << endl;
        return;
    }
    ll n =  (d / b - y1 ) / a ;
    cout << n + 1 << endl ;

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

