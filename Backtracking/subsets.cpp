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

void subsetsUtil(vector<int> &A, vector<vector<int> > &res, vector<int> &set, int index)
{
	//printf("index: %d pushing set:",index); printVec(set);
	res.push_back(set);

	for (int i = index; i < A.size(); i++)
	{
		//printf("processing index: %d\n",i);
		set.push_back(A[i]);
		//printf("pushing %d new set:",A[i]); printVec(set);
		subsetsUtil(A, res, set, i+1);
		set.pop_back();
		//printf("set after popping:"); printVec(set);
	}
}

vector<vector<int> > subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int> > res;
    vector<int> set;
    
    subsetsUtil(A, res, set, 0);

    return res;
}

void runTest()
{
	vi v = inputVec();
	vector<vi> res = subsets(v);
	for (int i = 0; i < res.size(); i++)
	{
		printVec(res[i]);
	}
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