// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


int sumOfLongRootToLeafPath(Node* root);

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<sumOfLongRootToLeafPath(root)<<endl;
  }
  return 0;
}// } Driver Code Ends


//User function Template for C++
/*
structure of the node of the binary tree is as
struct Node {
	int data;
	Node* left, *right;
};
*/
// your task is to complete this function
vector<int> sum(Node *root)
{
    if(root==NULL)
    {
        return {0,0};
    }
    vector<int> a = sum(root->left);		//a[height,sum]
    vector<int> b = sum(root->right);
    if(a[0] > b[0])
    {
        return {a[0]+1 , a[1]+root->data};
    }
    if(a[0] < b[0])
    {
        return {b[0]+1 , b[1]+root->data};
    }
    if(a[0]==b[0])
    {
        return {a[0]+1 , max(a[1],b[1])+root->data};
    }
}

int sumOfLongRootToLeafPath(Node* root)
{
	vector<int> ans = sum(root);
	return ans[1];
}