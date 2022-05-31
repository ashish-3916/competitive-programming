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

void solve()
{
	int n , m ;
	cin >> n >> m ;

	vector< int > arr(n + 2 , 0);

	for (int i = 0 ; i < m ; i++)
	{
		int l , r;
		cin >> l >> r;

		arr[l] += 1;
		arr[r + 1] += -1;
	}
	for (int i = 1 ; i <= n + 2 ; i++)
		arr[i] += arr[i - 1];
	/*for (auto i : arr)
		cout << i << " ";
	cout << endl;*/
	sort(arr.begin() + 1 , arr.end() - 1 );
    
    /*
    else we an store in freq array the no of (coins -> boxes)
    the take suffx sum to answer for at least x coins in O(1) time 
    
    O(n) total  time complexity
    O(1) query complexity
    */
	int q;
	cin >> q;
	while (q--)
	{
		int x ;
		cin >> x ;

		int index = lower_bound(arr.begin() + 1 , arr.end() - 1  , x) - arr.begin() ;

		int ans  = n - index + 1;
		cout << ans << endl;
	}


}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

