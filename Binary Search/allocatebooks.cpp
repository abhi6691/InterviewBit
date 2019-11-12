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

bool isPossible(vector<int> A, int m, int k) //[12,34,67,90] k:101
{
    int n = A.size();
    long long curr_sum = 0;
    int req = 1;
    
    for (int i = 0; i < n; i++)
    {
        if (A[i] > k)
            return false;
            
        if (A[i] + curr_sum > k)
        {
            req++;
            
            curr_sum = A[i];
            
            if (req > m)
                return false;
        }
        else
        {
            curr_sum += A[i];
        }
    }
    
    return true;
}

int books(vector<int> &A, int B) {
    long long sum = 0;
    int n = A.size(), res = INT_MAX;
    
    if (B > n)
        return -1;
    
    for (int i = 0; i < n; i++)
        sum += A[i];
        
    long long start = 0, end = sum;
    
    while (start <= end)
    {
        //printf("start: %d, end: %d\n", start, end);
        int mid = start + (end-start)/2;
        
        if (isPossible(A, B, mid))
        {
            //printf("%d is possible\n", mid);
            res = min(res, mid);
            
            end = mid - 1;
        }
        else
        {
            //printf("%d is not possible\n", mid);
            start = mid + 1;
        }
    }
    
    return res;
}



void runTest()
{
	vi v = inputVec();
	int m; SCD(m);
	int res = books(v, m);
	PRD(res);
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