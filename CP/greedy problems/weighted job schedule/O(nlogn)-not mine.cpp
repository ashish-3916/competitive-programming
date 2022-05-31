void solve()
{
	int n ;
	cin >> n ;

	vector<vector<int>> jobs;
	for (int i = 0; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;// start , end , profit
		jobs.push_back({y, x, z});
	}
	sort(jobs.begin(), jobs.end());
	map<int, int> dp = {{0, 0}};
	for (auto& job : jobs) {
		int cur = prev(dp.upper_bound(job[1]))->second + job[2];
		if (cur > dp.rbegin()->second)
			dp[job[0]] = cur;
	}
	cout << dp.rbegin()->second << endl;

}
