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
Advanced GCD  [A -> 10^250 , B -> 1e5 , gcd(A , B) = ? = gcd(B , A%B)  = gcd(B , Ans)]

    A -> fg
    A%B ?  -> (f*10 + g)%B -> ((f*10)%B + g%B)%B
           -> (((0*10) + f)*10)%B + g%B)%B
    PreviousAns = 0 ;
    int Ans = (PreviousAns*10 % B + currentDigit %B)
*/
int getNoFromString(int b , string &a) {
    int ans = 0;

    for (char c :  a ) {
        ans =  ((ans * 10 )% b + (c - '0') % b) % b ;
    }
    return ans ;
}
void solve()
{
    int A ;
    string B ;
    cin >> A >> B ;
    if(!A) {cout<<B<< endl; return ;}
    int b = getNoFromString(A , B);
    
    cout << __gcd(A , b) << endl;
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

