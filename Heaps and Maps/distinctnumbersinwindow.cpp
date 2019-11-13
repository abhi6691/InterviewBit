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

vi solve(vi &A, int B)
{
	vector<int> res;

	int n = A.size();
	if (B > n)
		return res;

	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		m[A[i]]++;
		if (i-B+1 >= 0)
		{
			res.push_back(m.size());
			m[A[i-B+1]]--;

			if (m[A[i-B+1]] == 0) m.erase(A[i-B+1]);
		}
	}

	return res;
}

void runTest()
{
	vi v = inputVec();
	int B; SCD(B);

	vi res = solve(v, B);
	printVec(res);
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