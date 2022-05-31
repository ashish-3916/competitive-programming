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
	return j1.finish <= j2.finish;
}


int UpperBound(vector<job> & jobs,  int e )
{
	int c = e ;

	int s = 0;
	e--;
	int index = -1;
	while (s <= e)
	{
		int mid = (s + e) / 2 ;

		if (jobs[mid].finish <= jobs[c].start )
			index = mid;
		if (index == mid)
		{
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}

	}
	return index;
}
/*
int bSearch(vector<job> & arr,  int e )
{
	int c = e;
	int s = 0;
	int index = -1;
	while (s < e)
	{
		int mid = (s + e) / 2 ;

		if (arr[mid].finish <= arr[c].start)
			index =  mid;

		if (index == mid)
			s = mid + 1;
		else
			e = mid ;

	}
	return index ;
}
*/
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

	int dp[n];
	dp[0] = arr[0].profit;
	for (int i = 1 ; i < n ; i++)
	{
		int choice1 = dp[i - 1];

		int choice2 = arr[i].profit ;

		int index = UpperBound( arr, i);
		if (index != -1)
			choice2 += dp[index];

		dp[i] = max( choice1 , choice2);
	}

	cout << dp[n - 1] << endl;

}
int main() {
	// your code goes here


	ios_base::sync_with_stdio(false);


	solve();
	return 0;
}

