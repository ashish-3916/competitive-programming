#include<vector>

int dirn[4][2] = { {1, 0}, { -1, 0}, {0, -1}, {0, 1} };

bool valid(int x, int y, int n)
{
	return (  x<n and y<n  and x >= 0  and y >= 0);
}
void findpath(int arr[][20], int n, int cx , int cy , vector<vector<int> > &visited)
{
	if ( cx == n - 1 and  cy == n - 1)
	{	visited[cx][cy] = 1;
		for (int i = 0 ; i < n; i++)
			for (int j = 0; j < n; j++)
				cout << visited[i][j] << " ";
		cout << endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{

		int x = cx + dirn[i][0];
		int y = cy + dirn[i][1];

		if (valid(x, y, n) and arr[x][y] and !visited[x][y] )
		{
			visited[x][y] = 1;
			findpath(arr, n , x, y, visited);
			visited[x][y] = 0;
		}
	}

}
void ratInAMaze(int maze[][20], int n) {

	vector<vector<int> > visited( n , vector<int>( n , 0));
	visited[0][0] = 1;
	findpath(maze, n , 0, 0, visited);
}
