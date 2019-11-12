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

//template <typename T>
//void swap(T *a, T *b) { T t = *a; *a = *b; *b = t;}

void printVec(vi v){for(int i = 0; i < v.size(); i++) cout<<v[i]<<" "; cout<<endl;}
vi inputVec(){vi v; int n,t; SCD(n); FOR(i,0,n) {SCD(t); v.PB(t);} return v;}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapify(vector<int> &v, int ind)
{
	//printf("maxHeapify called for index:%d\n",ind);
    int largest = ind, r = 2*ind+2, l = 2*ind+1;
    
    if (l < v.size() && v[largest] < v[l]) largest = l;
    if (r < v.size() && v[largest] < v[r]) largest = r;
    
    if (largest != ind)
    {
    	//printf("swapping %d and %d\n",largest, ind);
        swap(&v[largest], &v[ind]);
        maxHeapify(v, largest);
    }
}

int kthsmallest(const vector<int> &A, int B) {
    vector<int> v(A.begin(), A.begin() + B);
    for (int i = B/2; i >= 0; i--)
    {
        maxHeapify(v, i);
    }
    //printf("Initial vector:"); printVec(v);
    
    for (int i = B; i < A.size(); i++)
    {
        if (A[i] < v[0])
        {
        	//printf("Adding:%d, Removing:%d\n",A[i],v[0]);
            v[0] = A[i];
            maxHeapify(v, 0);
            //printVec(v);
        }
    }
    
    sort(v.begin(), v.end());
    //printVec(v);
    
    return v[B-1];
}


void runTest()
{
	vi v = inputVec();
	int B; SCD(B);
	cout<<kthsmallest(v, B);
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
		NL;
	}

	return 0;
}