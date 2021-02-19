bool none_empty(int grid[][9])
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (grid[i][j] == 0)
				return false;

	return true;
}
int coordinate(int x)
{
	if (x < 3) return 0;
	if (x < 6) return 3;
	return 6;
}
bool check_no(int grid[][9], int x, int y, int val)
{	// horizontally
	for (int i = 0 ; i < 9; i++)
		if (grid[x][i] == val)
			return false;
	// vertically
	for (int i = 0; i < 9; i++)
		if (grid[i][y] == val)
			return false;

	// check in square grid

	int finalx, finaly ;
	//finalx = coordinate(x);
	//finaly = coordinate(y);
	finalx = x - (x % 3);
	finaly = y - (y % 3);
	for (int i = 0 ; i < 3 ; i++)
		for (int j = 0 ; j < 3 ; j++)
			if (grid[finalx + i][finaly + j] == val)
				return false;

	return true;
}
bool sudoku_solver(int grid[][9], int r, int c)
{
	if (none_empty(grid))
	{
		
		return true;
	}
	int next_row, next_col;

	if (c + 1 == 9)
	{
		next_row = r + 1;
		next_col = 0;
	}
	else
	{
		next_row = r;
		next_col = c + 1;
	}
	//cout << next_row << " " << next_col << endl;
	if (grid[r][c] == 0)
	{
		for (int i = 1 ; i <= 9 ; i++)
		{
			bool ans = check_no( grid , r, c, i );
			if (!ans) continue;
			grid[r][c] = i;
			if (sudoku_solver(grid, next_row, next_col))return true;
			grid[r][c] = 0;
		}
		return false;
	}
	else
	{
		return sudoku_solver(grid, next_row, next_col);
	}
}
bool sudokuSolver(int board[][9])
{
   return sudoku_solver(board, 0, 0);
}
