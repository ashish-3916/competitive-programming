const int N =2001;
vector<int> graph[2001];
int  visited[2001];
int color[2001];

bool dfs(int sv , int col)
{
    visited[sv] = 1;
    color[sv] = col;
    for (int child : graph[sv])
    {
        if (!visited[child])
        {   if (!dfs(child , col ^ 1))
                return false;
        }
        else if (color[child] == color[sv])
            return false;
    }
    return true;
}
