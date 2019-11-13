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

struct ListNode {
    int val;
    ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
 };

 void printList(ListNode *root)
 {
 	printf("head");
 	while(root)
 	{
 		printf("->%d",root->val);
 		root = root->next;
 	}
 	printf("\n");
 }
 
 void reverseLinkList(ListNode **head)
 {
     ListNode *curr = *head, *prev = nullptr, *next = nullptr;
     while (curr != nullptr)
     {
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
     }
     
     *head = prev;
 }
 
int lPalin(ListNode* A) {
    ListNode *root = A;
    ListNode *slow = A, *fast = A;
    while (fast->next && fast->next->next)
    {
    	slow = slow->next;
    	fast = fast->next->next;
    }

    ListNode *head = slow->next;
    reverseLinkList(&head);
    slow->next = head;
    
    ListNode *it1 = A, *it2 = slow->next;
    while (it2)
    {
    	if (it1->val != it2->val)
    		return 0;

    	it1 = it1->next;
    	it2 = it2->next;
    }

    return 1;
}

void runTest()
{
	ListNode *head = new ListNode(1);
	//head->next = new ListNode(1);
	//head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(2);
	//head->next->next->next->next = new ListNode(1);

	cout<<lPalin(head);
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