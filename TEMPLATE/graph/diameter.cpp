int depth = 0 , node = -1;
void dfs(int sv , int cd)
{
    visited[sv] = 1;
    if (depth < cd)
    {node = sv; depth = cd;}
    for (int child : graph[sv])
       if (!visited[child])
            dfs(child , cd + 1);
}
void solve()
{
    dfs(1 ,0);
    int one_end = node ;
    dfs(one_end , 0);
    int other_end = node ;
    cout<< depth;
}
