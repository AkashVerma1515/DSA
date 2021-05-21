// { Driver Code Starts
//

#include<bits/stdc++.h>
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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int preIndex = 0;
    // int index;
    Node *build(int in[], int pre[], int l, int r)
    {
        if(l>r)
        {
            return NULL;
        }
        Node *head = new Node(pre[preIndex]);
        preIndex++;
        int index = search(in,l,r,head->data);
        
        head->left = build(in,pre,l,index-1);
        head->right = build(in,pre,index+1,r);
        
        return head;
    }
    
    int search(int in[], int l, int r, int d)
    {
        for(int i=l;i<=r;i++)
        {
            if(in[i] == d)
            {
                return i;
            }
        }
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int r = n-1;
        // Node *head = NULL;
        Node *ans = build(in,pre,0,r);
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends