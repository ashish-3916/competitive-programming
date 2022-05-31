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


/*
idea : 

  [arr1] [arr1] [arr1] . . . . . . [arr1]
  
  [arr1] ......[arr_sum].......[arr1]
  
  [arr1][arr1]......[arr_sum].....
  
     [arr2].........[arr_sum]....
   
   if k=1 -> kadane of arr1 is ans
   
   else 
   ans is kadane_arr2 +  arr_sum      //////// this came from intuituion since we need max( prefix1+ suffix1 , kadane_arr1 )
   but if arr_sum <0   
   ans is kadane_arr2
 
*/
ll kadane2(vector<ll>&arr) // neg is included
{
	ll n = arr.size();

	ll ans = arr[0];
	ll curr = arr[0];
	for (int i = 1 ; i < n ; i++)
	{
		if (arr[i] + curr > arr[i] )
			curr += arr[i];
		else
			curr = arr[i];

		if (curr > ans) ans = curr;
	}
	return ans;


}

void solve()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> arr1(n), arr2(2 * n);

	for (ll &x : arr1)
		cin >> x;

	for (int i = 0; i < 2 * n; ++i)
		arr2[i] = arr1[i % n];

	ll sum0 = 0;
	for (int i = 0 ; i < n ; i++)
		sum0 += arr1[i];


	ll sum1 = kadane2(arr1);
	ll sum2 = kadane2(arr2);

	if (k == 1) cout << sum1 << endl;
	// else k>=2
	else if (sum0 < 0)	cout << sum2 << endl;
	else cout << ( (k - 2)*sum0 + sum2) << endl;
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
	while (t--)solve();
	return 0;
}

/*




*/
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

ll prefix(vector<ll> & arr)
{
	int n = arr.size();
	vector<ll> pre(n);
	ll s = 0;
	for (int i = 0; i < n; i++)
	{
		s += arr[i];
		pre[i] = s;
	}
	return *max_element(all(pre));
}
ll suffix(vector<ll> & arr)
{
	int n = arr.size();
	vector<ll> suff(n);
	ll s = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		s += arr[i];
		suff[i] = s;
	}
	return *max_element(all(suff));
}

ll kadane2(vector<ll>&arr) // neg is included
{
	int n = arr.size();

	long curr_sum = 0, max_sum = LONG_MIN;;
	for (long i = 0; i < n; i++)
	{
		curr_sum += arr[i];
		if (curr_sum > max_sum) {
			max_sum = curr_sum;
		}
		if (curr_sum < 0) {
			curr_sum = 0;
		}
	}
	return max_sum;


}

void solve()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n);

	for (ll &x : arr)
		cin >> x;

	ll sum0 = 0;
	for (int i = 0 ; i < n ; i++)
		sum0 += arr[i];

	ll sum1 = kadane2(arr);
	ll best_suffix = suffix(arr);
	ll best_prefix = prefix(arr);

	if (k == 1)cout << sum1 << endl;
	else
	{
		if (sum0 > 0)
		{
			cout << max(best_prefix + best_suffix + (sum0 * (k - 2)) , sum1) << endl;
		}

		else
			cout << max(best_prefix + best_suffix , sum1) << endl;
	}


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
	while (t--)solve();
	return 0;
}

