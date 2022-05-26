// a genaral solution 
// see gfg video on YT for help
int maxProduct(vector<int>& arr)
{

	int n = arr.size();

	int minpro = arr[0];
	int maxpro = arr[0];
	int ans = arr[0];
	int choice1, choice2 = 0;

	for (int i = 1; i < n; i++)
	{
		choice1 = minpro * arr[i];
		choice2 = maxpro * arr[i];
		//cout <<  choice2 << " " << choice1 << " " << arr[i] << endl;
		minpro = min(arr[i], min(choice1, choice2));
		maxpro = max(arr[i], max(choice1, choice2));
		ans = max(ans, maxpro);
		//cout << maxpro << " " << minpro << " " << ans << "\n\n" ;


	}
	return ans;

}

// codezens lol soln (assuming that their always exist a positive product )
int maxProduct(vector<int>& arr)
{

	int n = arr.size();
	if (n == 1)return arr[0];

	int mx = 1;
	int mn = 1;
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			mx = mx * arr[i];
			mn = min(1, mn * arr[i]);

		}

		else if (arr[i] < 0)
		{
			int temp = mx;
			mx = max(mn * arr[i], 1);
			mn = temp * arr[i];
		}
		else if (arr[i] == 0)
			mn = mx = 1;

		ans = max(ans, mx);


	}
//	cout << mn << endl;
	return ans;
}
