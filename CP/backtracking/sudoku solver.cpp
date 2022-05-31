#include <iostream>
#include <bits/stdc++.h>
#define ll long long // delete if it causes problem
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define endl "\n" //delete if interactive
using namespace std;
void Print(vector< vector<int> > &grid)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << grid[i][j] ;
		}
		cout << endl;
	}
}
bool none_empty(vector< vector<int> > &grid)
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
bool check_no(vector< vector<int> > &grid , int x, int y, int val)
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
bool sudoku_solver(vector< vector<int> > &grid, int r, int c)
{
	if (none_empty(grid))
	{
		Print(grid);
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

void solve()
{
	vector< vector<int> >grid (9, vector<int>(9, 0));
	string s;
	for (int i = 0; i < 9; i++)
	{
		cin >> s;
		for (int j = 0; j < 9; j++)
			grid[i][j] = s[j] - '0';
		//cin >> grid[i][j];
	}

	bool ans = sudoku_solver(grid, 0, 0);
	//Print(grid);
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}

