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

void check(int arr[], int s , int e )
{
	if ( s >= e)return ;

	int mid  = (s + e) / 2;

	check(arr, s , mid);
	check(arr, mid + 1 , e);



	if (abs(arr[mid] - arr[mid + 1]) == 1)
	{
		if (arr[mid] > arr[mid + 1])
		{
			int temp = arr[mid];
			arr[mid] = arr[mid + 1];
			arr[mid + 1] = temp;

		}

	}

}
bool check_sort(int arr[] , int n)
{
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] > arr[i])
			return false;
	}
	return true;
}


void solve()
{
	int  n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	check(arr, 0, n - 1);
	if (check_sort(arr, n))
		cout << "Yes" << endl;
	else cout << "No" << endl;
	/*for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
*/}

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


/*
//need to find why this didnt work
bool check(int arr[], int s , int e )
{
	if ( s >= e)return true ;

	int mid  = (s + e) / 2;
	if ((s - e + 1) & 1)mid--;
	bool ans1 = check(arr, s , mid);
	bool ans2 = check(arr, mid + 1 , e);

	if (!ans1 or !ans2) return false;


	if (abs(arr[mid] - arr[mid + 1]) == 1)
	{
		if (arr[mid] > arr[mid + 1])
		{
			int temp = arr[mid];
			arr[mid] = arr[mid + 1];
			arr[mid + 1] = temp;

		}
		return true;
	}
	return false;
}

*/
