
int board[11][11];
bool check(int row , int col, int n)
{
	// checck vertically
	for (int i = row - 1 ; i >= 0 ; i--)
		if (board[i][col])return false;
	// check left diagonal

	for (int i = row - 1 , j = col - 1  ; i >= 0 and  j >= 0 ; i--, j--)
		if (board[i][j])return false;

// check right diagonal
	for (int i = row - 1 , j = col + 1  ; i >= 0 and  j < n ; i--, j++)
		if (board[i][j])return false;

	return true;
}
void placequeens(int n , int row)
{
	if (row == n)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0 ; j < n ; j++ )
				cout << board[i][j] << " ";
		cout << endl;
		return;
	}

	for (int i = 0 ; i < n ; i++) 
	{
		if (check(row, i , n)) /// O(N)
		{	board[row][i] = 1; // place a queen
			placequeens(n, row + 1); // recurse
			board[row][i] = 0; // remove a queen
		}
	}
	return ;
}
void placeNQueens(int n) {

	//memset(board, 0 , sizeof(board));
	placequeens(n , 0);
}
