/*
T.C -> O(n!)
S.C -> O(n*n)
*/

#include <bits/stdc++.h> 
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
	//check for row
	int i = row;
	int j = col;
	while(j >= 0)
	{
		if(board[i][j] == 1)
			return false;
		j--;
	}

	//check for upper left diagonal
	i = row;
	j = col;
	while(i >=0 && j>=0)
	{
		if(board[i][j] == 1)
			return false;
		
		i--;
		j--;
	}

	//check for lower left diagonal
	i = row;
	j = col;
	while(i<n && j>=0)
	{
		if(board[i][j] == 1)
			return false;
		i++;
		j--;
	}

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
			solve(col+1, board, ans, n);
			
			//backtracking
			board[row][col] = 0;
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