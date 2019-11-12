/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://www.interviewbit.com/problems/valid-path/
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

bool isInside(int x, int y, int xo, int yo, int rad)
{
	return (xo-x)*(xo-x) + (yo-y)*(yo-y) <= rad*rad;
}

string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    int isTouched[A+1][B+1];
    memset(isTouched, 0, sizeof(isTouched));
    
    for (int i = 0; i <= A; i++)
    {
        for (int j = 0; j <= B; j++)
        {
        	for (int k = 0; k < C; k++)
        	{
        		if ( isInside(i, j, E[k], F[k], D) )
        			isTouched[i][j] = 1;
        	}
        }
    }

	if (isTouched[0][0] || isTouched[A][B]) return "NO";

	queue<pair<int, int>> q;
	q.push({0,0});
	isTouched[0][0] = 1;

	int rowNbr[] = {-1,-1,-1,0,0,1,1,1};
	int colNbr[] = {-1,0,1,-1,1,-1,0,1};

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == A && y == B) return "YES";

		for (int i = 0; i < 8; i++)
		{
			int newX = x + rowNbr[i];
			int newY = y + colNbr[i];

			if (newX >= 0 && newX <= A && newY >= 0 && newY <= B && isTouched[newX][newY] == 0)
			{
				isTouched[newX][newY] = 1;
				q.push({newX,newY});
			}
		}
	}

	return "NO";
}


void runTest()
{
	int A, B, C, R;
	SCD(A); SCD(B); SCD(C); SCD(R);

	vi xCor, yCor;
	xCor = inputVec();
	yCor = inputVec();

	cout<<solve(A, B, C, R, xCor, yCor);
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