const int N = 100001;

vector<int> graph[N] ;
vector<int> indegree(N , 0);
vector<int> ans  ;

int n , m ;
void bfs()
{
	queue<int> q ;
	for (int i = 1 ; i <= n ; i++)
		if (indegree[i] == 0)
			q.push(i);

	while (q.size())
	{
		int curr = q.front();
		q.pop() ;

		ans.push_back(curr);

		for (int child :  graph[curr])
		{
			indegree[child]--;
			if (indegree[child] == 0)
				q.push(child);
		}
	}
	if(ans.size()==n)
		// topsort in ans
	else
		// topsort not possible

}


/* // not sure   UPD : works fine       learning  -> check cycle in directed graph
const int N = 100001;

vector<int> graph[N] ;
vector<bool> visited(N , false);
vector<int> ans  ;

vector<int>intime(N , 0) , outtime(N , 0) ;
int timer = 1 ;

bool iscycle(int sv)
{
	visited[sv] = 1;

	intime[sv] = timer++ ;

	for (int child :  graph[sv])
	{
		if (!visited[child])
		{
			if (iscycle(child))
				return true;
		}
		else
		{
			if (intime[sv] > intime[child]  and outtime[child] == 0 )
				return true;
		}
	}

	ans.push_back(sv);

	outtime[sv] = timer++;

	return false;
}

// if cycle return false;
// else print in reverse order



*/
