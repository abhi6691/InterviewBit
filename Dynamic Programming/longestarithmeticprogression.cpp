/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://www.interviewbit.com/problems/longest-arithmetic-progression/
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

int solve(vi &v)
{
	sort(v.begin(), v.end());

	int n = v.size();

	if (n <= 2) return n;

	int m[n][n];
	int ans = 2;

	for (int i = 0; i < n; i++)
	{
		m[i][n-1] = 2;
	}

	for (int j = n-2; j > 0; j--)
	{
		int i = j-1, k = j+1;
		while (i >= 0 && k <= n-1)
		{
			//printf("checking %d, %d and %d\n", v[i], v[j], v[k]);
			if (v[i] + v[k] == 2*v[j])
			{
				//printf("1. setting m[%d][%d]: %d\n",i,j,m[j][k] + 1);
				m[i][j] = m[j][k] + 1;
				ans = max(ans, m[i][j]);
				i--, k++;
			}
			else if (v[i] + v[k] < 2*v[j])
				k++;
			else
			{
				//printf("2. setting m[%d][%d]: 2\n",i,j);
				m[i][j] = 2;
				i--;
			}
		}

		while (i >= 0)
		{
			printf("3. setting m[%d][%d]: 2\n",i,j);
			m[i][j] = 2;
			i--;
		}
	}

	return ans;
}

void runTest()
{
	vi v = inputVec();
	cout<<solve(v); NL;
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