/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/
***********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define NL printf("\n")
#define PRD(t) printf("%d ", t)
#define SCD(t) scanf("%d",&t)
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,a,b) for (int i = (a); i >= (b); i--)
#define ITER(it, m) for (it = m.begin(); it != m.end(); it++)
#define PB push_back
typedef vector <int> vi;

template <typename T>
void swap(T *a, T *b) { T t = *a; *a = *b; *b = t;}

void printVec(vi v){for(int i = 0; i < v.size(); i++) cout<<v[i]<<" "; cout<<endl;}
vi inputVec(){vi v; int n,t; SCD(n); FOR(i,0,n) {SCD(t); v.PB(t);} return v;}

/*
int DFS(map<int, vector<int> > adjList, int index, int *maxDistance)
{
	map<int, vector<int> >::iterator it = adjList.find(index);
	if (it == adjList.end())
	{
		//printf("Node:%d No child found, returning 0\n",index);
		return 0;
	}
	
	vi child = it->second;

	vi depthsForSubtrees;

	for (int i = 0; i < child.size(); i++)
	{
		depthsForSubtrees.push_back(DFS(adjList, child[i], maxDistance));
	}

	sort(depthsForSubtrees.begin(), depthsForSubtrees.end());
	int n = depthsForSubtrees.size();

	if (n == 1)
	{
		*maxDistance = max(*maxDistance, depthsForSubtrees[0] + 1);
	}
	else
	{
		*maxDistance = max(*maxDistance, depthsForSubtrees[n-1] + depthsForSubtrees[n-2] + 2);
	}

	//printf("Node:%d List of depths from subtrees:",index);
	//printVec(depthsForSubtrees);

	//printf("Node:%d Max Distance: %d, depth returned: %d\n", index, *maxDistance, depthsForSubtrees[n-1]+1);

	return depthsForSubtrees[n-1] + 1;
}
*/

int BFS(map<int, vector<int> > adjList, int start, int &end)
{
	queue<pair<int, int> >q;
	unordered_set<int> visited;

	int cur_level = 0;
	int cur_node = start;

	q.push({cur_node, cur_level});

	while (!q.empty())
	{
		cur_node = q.front().first;
		cur_level = q.front().second;
		q.pop();
		visited.insert(cur_node);
		//printf("processing node: %d at level:%d\n", cur_node, cur_level);
		map<int, vector<int>>::iterator it = adjList.find(cur_node);
		if (it != adjList.end())
		{
			vector<int> neighbors = it->second;
			for (int i = 0; i < neighbors.size(); i++)
			{
				if (visited.count(neighbors[i]) == 0)
				{
					//printf("inserting node:%d and level:%d\n", neighbors[i], cur_level+1);
					q.push({neighbors[i], cur_level + 1});
				}
			}
		}
	}

	//printf("BFS call returning node:%d and level:%d\n", cur_node, cur_level);

	end = cur_node;

	return cur_level;
}

int solve(vi &v)
{
	map<int, vector<int>> adjList;
	int n = v.size();

	FOR(i,0,n)
	{
		if (v[i] != -1)
		{
			adjList[v[i]].push_back(i);
			adjList[i].push_back(v[i]);
		}
	}

	/*map<int, vector<int>>::iterator it;
	ITER(it, adjList)
	{
		printf("%d:",it->first);
		vi t = it->second;
		printVec(t);
	}*/
	int path_start, path_end;

	BFS(adjList, 0, path_start);

	int maxDistance = BFS(adjList, path_start, path_end);

	return maxDistance;
}

void runTest()
{
	vi v = inputVec();
	cout<<solve(v)<<endl;
}

int main()
{
	#ifndef ONLINE_JUDGE

	freopen("D://Code//inputf.in", "r", stdin);
	freopen("D://Code//outputf.in", "w", stdout);

	#endif

	int num_of_tests;
	SCD(num_of_tests);

	while(num_of_tests--)
	{
		runTest();
	}

	return 0;
}