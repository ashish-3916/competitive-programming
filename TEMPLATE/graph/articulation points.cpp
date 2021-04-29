/*
case 1 :  if root -> is an articluation point , if it has 2 or more subtrees/ childrens

case 2 :  if not root ->  looking through the edges starting from vertex v≠root.
						  If the current edge (v,child) is such that none of the vertices child or its descendants
						  in the DFS traversal tree has a back-edge to any of ancestors of v,
						  then v is an articulation point. Otherwise, v is not an articulation point.

*/
const int N = 100001;
vector<int>graph[N];
vector<bool>visited(N, false);
vector<int> intime(N, -1) , low(N, -1);
int timer = 0 ;


void dfs(int sv, int parent)
{
	visited[sv] = 1;
	intime[sv] = low[sv] = timer;
	timer++ ;

	int children = 0;
	for (int child : graph[sv])
	{
		if (child == parent)continue;

		if (visited[child]) // this child is the ancestor of sv , is a backedge
		{
			low[sv] =  min(low[sv] , intime[child]);
		}
		else // this child is the descendent  ,is a forward edge
		{
			dfs(child, sv);

			low[sv] = min(low[sv] , low[child]); // if child has an ancestor , sv also has same ancestor

			if (low[child] >= intime[sv] and parent != -1)
				is_cutvertex(sv); // todo

			++children;
		}
	}
	if (p == -1 and children > 1)
		is_cutvertex(sv);
}

