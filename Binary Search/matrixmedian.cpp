/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description:
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

int solve(vector<vi> &m)
{
	int mini = INT_MAX, maxi = INT_MIN;
	int r = m.size(), c = m[0].size();

	for (int i = 0; i < r; i++)
	{
		mini = min(mini, m[i][0]);
		maxi = max(maxi, m[i][c-1]);
	}

	int desired = (r*c+1)/2;
	//printf("desired:%d\n",desired);

	while (mini < maxi)
	{
		//printf("min: %d, max:%d\n",mini,maxi);

		int mid = mini + (maxi - mini)/2;
		int place = 0;

		for (int i = 0; i < r; i++)
		{
			int add = (upper_bound(m[i].begin(), m[i].end(), mid) - m[i].begin());
			//printf("row: %d, elements less than or equal to %d : %d\n",i,mid,add);
			place = place + add;
		}

		//printf("mid: %d, place: %d\n",mid, place);

		if (place < desired)
			mini = mid + 1;
		else
			maxi = mid;
	}

	return mini;
}

void runTest()
{
	vector<vi> m;
	int R, C;
	SCD(R); SCD(C);
	FOR(i,0,R)
	{
		vi v;
		FOR(j,0,C)
		{
			int t; SCD(t); v.PB(t);
		}
		m.PB(v);
	}

	cout<<solve(m);
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