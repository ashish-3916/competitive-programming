#include<climits>
int dirn[4][2] = { { -1, 0 }, {1, 0} , {0, -1} , {0, 1} };

bool valid (int x , int y , int n )
{
	return  ( x >= 0  and  y >= 0 and  x < n  and y < n);
}

int find(vector<vector<int>>&cake , int n  , vector<vector<bool>>&visited , int cx , int cy)
{
	visited[cx][cy] = true;

	int ans  = 1;

	for (int i = 0; i < 4 ; i++)
	{
		int nx = cx + dirn[i][0];
		int ny = cy + dirn[i][1];

		if (valid(nx , ny , n)  and !visited[nx][ny] and cake[nx][ny] == 1)
		{
			ans += find(cake , n , visited , nx , ny);
		}
	}
	return ans ;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{

	vector<vector<bool>> visited ( n , vector<bool>(n, 0));

	int ans  = INT_MIN;

	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			if (!visited[i][j]  and cake[i][j] == 1)
				ans  = max( ans , find(cake , n , visited , i , j));
		}
	}

	return ans ;
}
