/*
** OPTIMISED **
Map to check if a queen already exists
-> map for row 
-> map for left diagonal -- (row+col) returns a same number for a particular left diagonal
	e.x :- a[0][2], a[1][1], a[2][0] is a left diagonal => (0+2) = (1+1) = (2+0)

-> map for right diagonal -- (n-1)+(col-row) returns a same number for a particular right diagonal
	e.x :- a[2][1], a[1][0] is a right diagonal => suppose it's a 4*4 matrix,
												=> (4-1)+(2-1) = (4-1)+(1-0)
												=> 4 = 4
*/
#include <bits/stdc++.h> 
unordered_map<int, bool> mapRow, mapUD, mapLD;

void markTrue(int row, int col, int n){
	mapRow[row] = 1;
	mapUD[((n-1)+(col-row))] = 1;
	mapLD[row+col] = 1;
}

void markFalse(int row, int col, int n){
	mapRow[row] = 0;
	mapUD[((n-1)+(col-row))] = 0;
	mapLD[row+col] = 0;
}

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
	vector<int> temp;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			temp.push_back(board[i][j]);
	
	ans.push_back(temp);
}

/*
Since we are traversing from left to right of matrix, 
so no need to check for elements of right side as there doesn't exist any queen yet.

Also, No need to check for column as our algo is designed such that one queen exist in a column at a time.

So we need to check for
-> row elements if any queen exist in left part of it.
-> Upper left diagonal and lower left diagonal.
*/
bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
	if(mapRow[row] || mapUD[((n-1)+(col-row))] || mapLD[row+col])
		return false;
	return true;
}

void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
	//base case
	if(col == n)
	{
		addSolution(board, ans, n);
		return;
	}

	//for every row element in a column
	for(int row=0;row<n;row++)
	{
		if(isSafe(row, col, board, n)){
			board[row][col] = 1;
			markTrue(row, col, n);
			solve(col+1, board, ans, n);
			
			//backtracking
			board[row][col] = 0;
			markFalse(row, col, n);
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n, vector<int>(n, 0));
	vector<vector<int>> ans;
	solve(0, board, ans, n);
	return ans;
}