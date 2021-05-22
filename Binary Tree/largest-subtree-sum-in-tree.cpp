// C++ program to find largest subtree
// sum in a given binary tree.
#include <bits/stdc++.h>
using namespace std;

// Structure of a tree node.
struct Node {
	int key;
	Node *left, *right;
};

// Function to create new tree node.
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

// Helper function to find largest
// subtree sum recursively.
int findLargestSubtreeSumUtil(Node* root, int& ans)
{
	if (root == NULL)	
		return 0;
	int currSum = root->key + findLargestSubtreeSumUtil(root->left, ans) + findLargestSubtreeSumUtil(root->right, ans);

	ans = max(ans, currSum);

	return currSum;
}

// Function to find largest subtree sum.
int findLargestSubtreeSum(Node* root)
{
	// If tree does not exist,
	// then answer is 0.
	if (root == NULL)	
		return 0;
	
	// Variable to store maximum subtree sum.
	int ans = INT_MIN;

	// Call to recursive function to
	// find maximum subtree sum.
	findLargestSubtreeSumUtil(root, ans);

	return ans;
}

// Driver function
int main()
{
	/*
			1
			/ \
			/	 \
		-2	 3
		/ \	 / \
		/ \ / \
		4	 5 -6	 2
	*/

	Node* root = newNode(1);
	root->left = newNode(-2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(-6);
	root->right->right = newNode(2);

	cout << findLargestSubtreeSum(root);
	return 0;
}
