
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

const int N = 1000005;
const int mod = 1e9 + 7;
long long add(long long a , long long b)
{
    long long ans = ((a % mod) + (b % mod)) % mod;
    if (ans < 0)ans += mod;
    return ans;
}

map<int , int > kmap;
map<int , int > curr;
void factorise(int k , bool f = false) {

    for (int i = 2 ; i*i <= k ; i++) {
        int cnt = 0 ;
        if (!k) break;
        while (k and (k % i == 0)) {
            k /= i ; cnt ++;
        }
        if (cnt) {
            if (!f)kmap[i] += cnt ;
            else curr[i] += cnt;
        }

    }
    if (k > 1) {
        if (!f)kmap[k] += 1 ;
        else curr[k] += 1;
    }
}
void defactorise(int k) {
    for (int i = 2 ; i * i <=k ; i++) {
        int cnt = 0 ;
        if (!k) break;
        while (k and (k % i == 0)) {
            k /= i ; cnt ++;
        }
        if (cnt) {
            curr[i] -= cnt;
        }
    }
    if (k > 1) {
        curr[k] -= 1;
    }
}
bool check() { // 2*3*5*7*11*13*17*19*23*29  
    // curr>= kmap
    for (auto i : kmap) { //O(11 + 1 )
        int factor =  i.first;
        int power =  i.second;

        if (curr[factor] < power) return false;
    }
    return true;
}
void solve()
{
    int n , k ;
    cin >> n >> k ;
    vector<int> arr(n);

    for (int i = 0 ; i < n ; i++)
        cin >> arr[i] ;
    if(k==1){cout<< (n*(n+1))/2 << endl; return;}
    
    factorise(k);
    int ans = 0 ;
    int j = 0 ;
    for (int i = 0 ; i < n ; i++) {
        // add factors of arr[i]
        factorise(arr[i] , true); 
        // do until factors meet k-factors and increment i and ans ;
        while (j<=i and check()) {
            ans = add(ans ,  n - i) ;
            defactorise(arr[j]);
            j++;
        }
    }
    cout << ans << endl;
}
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    {solve();}
    return 0;

}



// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main(){
    
//     ll n,k;
//     cin>> n >> k;
//     ll arr[n];
    
//     for(ll i = 0; i<n ;i++){
//         cin>>arr[i];
//     }
    
//     vector<pair<int,int>> vp;
//     ll temp_k = k;
//         for(int i = 2; i*i<=temp_k ;i++){
            
//             if(temp_k%i == 0){
//                 int count = 0;
//                 while(temp_k%i == 0){
//                     temp_k/=i;
//                     count++;
//                 }
//                 vp.push_back({i,count});
                
//             }
        
//         }
    
    
//     if(temp_k!=1){
//         vp.push_back({temp_k,1});
//     }
    
    
//     ll ans = 0;
    
//     vector<pair<int,int>> vq;
//     for(int i=0;i<vp.size();i++){
//         // cout<<vp[i].first<<" ";
//         vq.push_back({vp[i].first, 0});
//         // cout<<vq[i].first<<endl;
//     }
// 	int i = 0;
//     int j = 0;
//     while(i!=n){
//         for(int z=0 ;z<vq.size();z++){
//             temp_k = arr[i];
//             int cn = 0;
//             while(temp_k%vp[z].first == 0){
//                 temp_k/=vp[z].first;
//                 cn++;
//             }
//             vq[z].second +=cn;
//         }
        
//         bool done = true;
        
//         for(int z= 0;z<vq.size();z++){
//             if(vp[z].second > vq[z].second){
//                 done = false;
//                 break;
//             }
//         }
//         if(done){
//             ans += n-i;
//             while(j<=i){
//                 for(int l=0 ;l<vq.size();l++){
//                     temp_k = arr[j];
//                     int cn = 0;
//                     while(temp_k%vp[l].first == 0){
//                         temp_k/=vp[l].first;
//                         cn++;
//                     }
//                     vq[l].second -= cn;
//                 }
                
//                 bool done_2 = true;
//                 for(int l= 0;l<vq.size();l++){
//                     if(vp[l].second > vq[l].second){
//                         done_2 = false;
//                         break;
//                     }
//                 }
                
//                 if(done_2){
//                     j++;
//                     ans+=n-i;
//                 }
//                 else {
//             		i++;
//                     j++;
//                     break;
//                 }
//             }
//         }
//         else{
//             i++;
//         }
        
//     }
//     cout<<ans<<endl;
    
     
    
    
// }





