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

int searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int R = A.size(), C = A[0].size(); // R:4 C:5
    
    int start = 0, end = R-1, mid, cand = -1;
    
    //printf("Determining row candidate\n");
    /*for (int i = 0; i < R; i++)
    {
        if (B >= A[i][0] && B <= A[i][C-1] )
        {
            cand = i;
            break;
        }
    }
    
    if (cand == -1) return 0;*/
    
    while (start <= end) // 3 3
    {
        //printf("start:%d end:%d\n",start,end);
        mid = start + (end - start)/2; // 2
        if (A[mid][0] < B)
        {
            cand = mid; // 2
            start = mid + 1;
        }
        else if (A[mid][0] > B)
        {
            end = mid - 1;
        }
        else
            return 1;
    }
    
    if (cand == -1)
        return 0;
        
    //printf("Row candidate:%d, now finding column\n",cand);
    start = 0, end = C-1;
    while (start <= end) // 4 4
    {
        //printf("start:%d end:%d\n",start,end);   
        mid = start + (end - start)/2; // 3
        if (A[cand][mid] == B)
            return 1;
        if (A[cand][mid] < B)
            start = mid + 1;
        else
            end = mid - 1;
    }
    //printf("Not found, returning 0\n");
    return 0;
}


void runTest()
{
	vector<vi> v;
	int R, C, B;
	SCD(R); SCD(C);
	FOR(i,0,R)
	{
		vi t; int k;
		FOR(j,0,C)
		{
			SCD(k); t.PB(k);
		}
		v.PB(t);
	}
	SCD(B);
	cout<<searchMatrix(v, B);
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