/*

log n for binary search 

for checking 
  T(n)= O(1) + T( 9n/10)
     .    .        .  
  T(1)=       T((9/10)^r *n)
  
  (9/10)^r *n =1 
  n=(10/9)^r
  log 10/9 n =r

= O(log 10/9 n )

so total  == (logn)^2

*/
#include <iostream>
#include <bits/stdc++.h>
#define ll long long // delete if it causes problem
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define endl "\n" //delete if interactive
using namespace std;
bool check(ll n , ll c)
{
	ll have = 0, req = n;

	while (n > 0)
	{
		if (n - c < 0)
		{have += n; break;}

		have += c;

		n -= c;

		n = n - (n / 10);
	}
	if (2*have >= req)
		return true;
	else return false;
}
void solve()
{
	ll n;
	cin >> n;
	ll ans = -1;

	ll low = 1, high = n;
	while (low <= high)
	{
		ll mid  = low + ( high - low) / 2;

		bool c = check( n, mid );
		if (c)
		{
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	cout << ans << endl;

}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

