int dirn[8][2] = { { -1, -1}, { -1, 0}, { -1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

bool valid(int x , int y , int n , int m)
{
	return (x >= 0 and y >= 0 and x < n and y < m);
}
bool bfs(vector<vector<char>> &board, int n, int m , int cx , int cy , vector<vector<bool>>&visited, string s)
{
	if (s.length() == 0 )
		return true;
    
    visited[cx][cy]=true;

	for (int i = 0; i < 8 ; i++)
	{
		int nx = cx + dirn[i][0];
		int ny = cy + dirn[i][1];

		if (valid(nx, ny , n , m) and !visited[nx][ny] and board[nx][ny] == s[0])
		{
            visited[nx][ny]=1;
			int ans  = bfs( board , n , m , nx , ny , visited , s.substr(1));
			if (ans)
				return true;
		}
	}
	visited[cx][cy]= false;
	return false;
}
bool hasPath(vector<vector<char>> &board, int n, int m)
{
	string s = "ODINGNINJA";
    vector<vector<bool>> visited(n , vector<bool>(m, 0));
                
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 'C')
			{
				if (bfs(board, n , m , i , j , visited, s))
					return true;
			}
		}
	}
	return false;

}
