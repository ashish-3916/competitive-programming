/*
  https://www.codechef.com/problems/CHEFRRUN/
	
	const int N  = 1e5 + 1 ;
	vector<ll> graph[N];
	vector<ll> transpose[N];
	vector<ll> out_time(N);
	vector<ll>visited(N);
	vector<ll>skips(N);
	vector<ll>nodes;
	ll n , x;
	ll idx = 0 ;
  
	void dfs1(ll sv)
	{
		visited[sv] = 1;
		nodes.push_back(sv);

		for (ll child :  transpose[sv])
			if (!visited[child])
				dfs1(child);

	}
	void dfs(ll sv)
	{
		visited[sv] = 1;

		for (ll child :  graph[sv])
			if (!visited[child])
				dfs(child);

		out_time[idx++] = sv;

	}
  
	void solve()
	{
		for (ll i = 0; i < N ; i++)
		{
			graph[i].clear();
			transpose[i].clear();
			out_time[i] = 0;
			visited[i] = 0;
			skips[i] = 0;
		}

		cin >> n;
		for (ll i = 0 ; i < n ; i++)
		{
			cin >> x;
			skips[i] = x;

			ll a  = i ;
			ll b = (i + x + 1) % n;

			if (a == b)continue ; // self loop , will handle later, test case 2

			graph[a].push_back(b);
			transpose[b].push_back(a);
		}

		for (ll i = 0 ; i < n ; i++)
		{
			if (!visited[i])
				dfs(i);
		}

		for (ll i = 0 ; i < n ; i++)
		{
			visited[i] = 0;
		}
		vector<vector<ll>>component;
		for (ll i = idx - 1 ; i >= 0 ; i--)
		{
			if (!visited[out_time[i]])
			{
				nodes.clear();
				dfs1(out_time[i]);
				component.push_back(nodes);
			}
		}

		//debug(component);
		ll ans = 0 ;
		for (auto v : component)
		{
			ll s = v.size();
			if (s > 1)
				ans += s;

			else /// check for self loop
			{
				ll a  = v[0] ;
				ll b = (v[0] + skips[v[0]] + 1) % n;
				if (a == b) // if present
					ans++;
			}
		}

		cout << ans << endl;
	}




*/
