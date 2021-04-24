int timer = 1; 

void dfs(int sv)
{
	visited[sv]=1 ;

	in[sv]=timer++ ;

	for(int child : graph[sv])
		if(!visited[child])
			dfs(child);

	out[sv]=timer++;
}
