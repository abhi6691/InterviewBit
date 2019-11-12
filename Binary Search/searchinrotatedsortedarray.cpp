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

int BinarySearch(const vector<int> &A, int B, int low, int high)
{
   	if (low > high) return 0;

   	int mid = low + (high-low)/2;

   	printf("BinarySearch low:%d, high:%d, mid:%d B:%d\n",low, high, mid, B);

	if (A[mid] == B) return 1;

    if (A[mid] < B) return BinarySearch(A, B, mid+1, high);

    return BinarySearch(A, B, low, mid-1);
}

int findPivot(const vector<int> A, int low, int high)
{
    printf("low:%d, high:%d\n", low, high);
    if (high < low) return -1;
    if (high == low) return low;
    
    int mid = low + (high - low)/2;
    
    if (mid < high && A[mid] > A[mid+1])
        return mid;
        
    if (mid > low && A[mid] < A[mid-1])
        return mid-1;
        
    if (A[low] >= A[mid]) return findPivot(A, low, mid-1);
    
    return findPivot(A, mid+1, high);
}

int search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int n = A.size();
    int pivot = findPivot(A, 0, A.size() - 1);

    PRD(pivot); PRD(A[pivot]); PRD(A[0]); NL;

    if (pivot == -1) return BinarySearch(A, B, 0, n-1);
    
    if (A[pivot] == B) return 1;

    if (A[0] <= B){printf("chota h\n"); return BinarySearch(A, B, 0, pivot-1);}
    printf("bada h\n");
    return BinarySearch(A, B, pivot+1, n-1); 
}


void runTest()
{
	vi v = inputVec();
	int B; SCD(B);
	cout<<search(v, B);
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