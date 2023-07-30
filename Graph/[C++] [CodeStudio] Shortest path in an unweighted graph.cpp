//O(n+m) [n = no. of vertices, m = no. of edges]

#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int, list<int>> adjList;

	//Adjcency List
	for(int i=0;i<edges.size();i++)
	{
		int u = edges[i].first;
		int v = edges[i].second;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	vector<bool> visited(n+1);
	vector<int> ans;
	unordered_map<int, int> parentNode;
	queue<int> q;

	q.push(s);
	parentNode[s] = -1;
	visited[s] = 1;

	//bfs and store parentNode for each node.
	while(!q.empty())
	{
		int frontNode = q.front();
		q.pop();

		for(auto i:adjList[frontNode])
		{
			if(!visited[i])
			{
				parentNode[i] = frontNode;
				visited[i] = 1;
				q.push(i);
			}
		}
	} 

	//If we backtrack parent nodes from Destination to source, we'll get the shortest path.
	int temp = t;
	ans.push_back(temp);

	while(temp != s)
	{
		temp = parentNode[temp];
		ans.push_back(temp);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}
