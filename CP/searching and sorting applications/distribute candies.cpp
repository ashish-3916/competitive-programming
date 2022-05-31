	#include <iostream>
	#include <bits/stdc++.h>
	#define ll long long
	#define dbg(x)  cout<<#x<<" "<<x<<endl;
	#define F first
	#define S second
	#define setbit(n) __builtin_popcount(n)
	#define all(x) x.begin() , x.end()
	#define clr(x) memset(x,0,sizeof(x))
	#define endl "\n" //delete if interactive
	using namespace std;

	bool check ( vector<int > & candies , int n, int friends , int count)
	{
		int cnt = 0;
		for (int i = 0 ; i < n ; i++)
		{
			cnt +=  candies[i] / count;
		}
		if (cnt < friends)
			return false;
		return true;
	}

	void solve()
	{
		int n, k;
		cin >> n >> k;
		vector<int> candies (n);
		for (int &i :  candies)
			cin >> i;
 
		sort(all(candies));
		int low  = 0 ;
		int high = candies[n - 1];

		ll ans  = 0 ;
		while (low <= high)
		{
			int mid = (low + high ) / 2;

			if ( check ( candies , n , k , mid))
			{
				ans = mid ;
				low = mid + 1;
			}
			else
				high = mid - 1;
		}

		cout << ans << endl;

	}

	int main() {
		// your code goes here
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int t;
		cin >> t;
		while (t--)
		{solve();}
		return 0;
	}

