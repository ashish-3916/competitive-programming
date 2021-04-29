/*

in brief : if somehow child has less time than parent which would mean that edge isn't bridge , means child has alternate path to move to its ancestor .

so the idea is :

Let's say we are in the DFS, looking through the edges starting from vertex v. 
The current edge (sv,child) is a bridge if and only if none of the vertices child and its
descendants in the DFS traversal tree has a back-edge to vertex sv or any of its ancestors. 
Indeed, this condition means that there is no other way from sv to child except for edge (sv,child)

backedge can never be a bridge.

we maintain a low array which basically maintains the lowest time / minimum time , this time is 
either the low time of node , or child , or intime of ancestor if it has . low array would contain 
intime of the node , or of the ancestor (in case if it has )

for a backedge :  low time of node would be intime of its ancestor other than parent ,
				  as intime of ancestor is  less than the node , which means edge ancestor and 
				  node is not a bridge.

for a forward edge : it is a bridge, if child wont have any backedge , hence if low time of child would
				     be equal to its intime , which would be greater than the intime of the node itself,
			    	  which makes an edge a bridge .


so code looks like :
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
			// now we check relation between sv and its this child

			if (low[child] > intime[sv]) // currently ig intime[sv]=low[sv]
				is_bridge(sv, child); // todo

			low[sv] = min(low[sv] , low[child]); // if child has an ancestor , sv also has same ancestor
		}
	}
}

