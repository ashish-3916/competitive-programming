
int dirn[4][2] = { { -1, 0 }, {1, 0} , {0, -1} , {0, 1} };

bool valid (int x , int y , int n , int m)
{
	return  ( x >= 0  and  y >= 0 and  x < n  and y < m);
}
/*
2-> for parent 
1-> visited
0-> not visited

other alternative soln where we can track the parent node (pass its coordinates) , so if we find visited node 
alternate of parent node then it means a cycle exist
*/

bool check(vector<vector<char>>&board , vector<vector<int>>&visited , int n  , int m, int cx , int cy , char c , int cycle)
{
	cycle++;

	for (int i = 0; i < 4 ; i++)
	{
		int nx  = cx  + dirn [i][0];
		int ny = cy + dirn [i][1];

		if (valid(nx , ny , n , m))
		{
			if (visited[nx][ny] == 2 and cycle >= 4)
				return true;

			else if (!visited[nx][ny]  and board[nx][ny] == c)
			{
				//cycle++;
				visited[nx][ny] = 1;
				if (check(board , visited , n , m , nx , ny , c , cycle))
					return true;
				visited[nx][ny] = 0;
			}
		}
	}

	return false;

}

bool hasCycle(vector<vector<char>> &board, int n, int m)
{

	vector<vector<int>> visited ( n , vector<int>(m, 0));

	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < m ; j++)
		{
			visited[i][j] = 2;
			if (check(board , visited , n , m, i , j , board[i][j] , 0 ))
				return true;
			visited[i][j] = 0;
		}
	}

	return false;
}


