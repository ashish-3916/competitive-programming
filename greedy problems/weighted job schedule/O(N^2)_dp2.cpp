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

class job
{
public:
	int start , finish , profit;
	job() {}
	job( int s , int f , int p)
	{
		start = s; finish = f; profit = p;
	}
};
bool myfunc(job j1 , job j2)
{
	return j1.finish < j2.finish;
}

void solve()
{
	int n ;
	cin >> n ;

	vector<job> arr(n);
	for (int i = 0; i < n ; i++)
	{
		int x, y, z ;
		cin >> x >> y >> z;
		arr[i] = job(x, y, z);
	}

	sort(all (arr) , myfunc);
	/*for ( auto x : arr)
		cout << x.start << " " << x . finish << " " << x.profit << endl;*/
	int dp[n];
	dp[0] = arr[0].profit;
	for (int i = 1 ; i < n ; i++)
	{
		int choice1 = dp[i - 1];

		int choice2 = arr[i].profit ;

		for (int j = i - 1 ; j >= 0 ; j--)
		{
			if (arr[i].start >= arr[j].finish)
			{
				choice2 += dp[j];
				break;
			}
		}

		dp[i] = max( choice1 , choice2);
	}

	cout << dp[n - 1] << endl;

}
int main() {
	// your code goes here


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();
	return 0;
}

