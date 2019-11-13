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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int isBalancedUtil(TreeNode *root, int *height) // 1
{
    if (root == nullptr)
    {
        *height = 0;
        return 1;
    }
        
    if (root->left == nullptr && root->right == nullptr)
    {
        *height = 1;
        return 1;
    }
        
    int lheight, rheight;
    int lbalanced = isBalancedUtil(root->left, &lheight); // 1 2
    int rbalanced = isBalancedUtil(root->right, &rheight); // 1 1
    
    *height = max(lheight, rheight) + 1; // 2
    
    return ((lbalanced == 1) && 
            (rbalanced == 1) && 
            ((abs(lheight - rheight) == 0) || abs(lheight - rheight) == 1));
}
 
int isBalanced(TreeNode* A) {
    int height;
    return isBalancedUtil(A, &height);
}


void runTest()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    /*root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);*/
    cout<<isBalanced(root);
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