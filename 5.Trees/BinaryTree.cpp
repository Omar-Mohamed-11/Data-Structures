#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"

class Node
{
public:
	int data;
	Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

class Tree
{
private:
	Node *root;

	void inorder(Node *root) // left -> root -> right
	{
		if (root == NULL)
			return;
		inorder(root->left);
		cout << root->data << ' ';
		inorder(root->right);
	}

	void preorder(Node *root) // root -> left -> right
	{
		if (root == NULL)
			return;
		cout << root->data << ' ';
		preorder(root->left);
		preorder(root->right);
	}

	void postorder(Node *root) // left -> right ->root
	{
		if (root == NULL)
			return;
		postorder(root->left);
		postorder(root->right);
		cout << root->data << ' ';
	}

	Node *insert(Node *root, int value)
	{
		if (root == NULL)
		{
			return new Node(value);
		}
		else
		{
			if (value < root->data)
			{
				root->left = insert(root->left, value);
			}
			else
			{
				root->right = insert(root->right, value);
			}
			return root;
		}
	}

	int size(Node *root)
	{
		if (root == NULL)
			return 0;
		else
		{
			return 1 + size(root->left) + size(root->right);
		}
	}

	int min(Node *root)
	{
		if (root == NULL)
			exit(1);
		if (root->left == NULL)
			return root->data;
		return min(root->left);
	}

	Node *minNode(Node *root)
	{
		if (root == NULL)
			return NULL;
		if (root->left == NULL)
			return root;
		return minNode(root->left);
	}

	int max(Node *root)
	{
		if (root == NULL)
			exit(1);
		if (root->right == NULL)
			return root->data;
		return max(root->right);
	}

	Node *maxNode(Node *root)
	{
		if (root == NULL)
			return NULL;
		if (root->right == NULL)
			return root;
		return maxNode(root->right);
	}

	bool search(Node *root, int value)
	{
		if (root == NULL)
			return 0;
		if (root->data == value)
		{
			return 1;
		}
		else if (value < root->data)
		{
			return search(root->left, value);
		}
		else
		{
			return search(root->right, value);
		}
	}

	int maxDepth(Node *root)
	{
		if (root == NULL || (root->left == NULL && root->right == NULL))
			return 0;
		else
		{
			int l = maxDepth(root->left);
			int r = maxDepth(root->right);
			if (l > r)
				return l + 1;
			else
				return r + 1;
		}
	}

	Node *deleteNode(Node *root, int value)
	{
		if (root == NULL)
			return root;
		else if (value < root->data)
		{
			root->left = deleteNode(root->left, value);
		}
		else if (value > root->data)
		{
			root->right = deleteNode(root->right, value);
		}
		else
		{
			if (root->left == NULL)
			{
				Node *p = root->right;
				delete root;
				return p;
			}
			else if (root->right == NULL)
			{
				Node *p = root->left;
				delete root;
				return p;
			}
			else
			{
				int minVal = min(root->right);
				root->data = minVal;
				root->right = deleteNode(root->right, minVal);
			}
		}
		return root;
	}

	void clearTree(Node *root)
	{
		if (root == NULL)
			return;
		else
		{
			clearTree(root->left);
			clearTree(root->right);
			delete root;
		}
	}

public:
	Tree()
	{
		root = NULL;
	}

	void inorder()
	{
		inorder(root);
	}

	void preorder()
	{
		preorder(root);
	}

	void postorder()
	{
		postorder(root);
	}

	void insert(int value)
	{
		root = insert(root, value);
	}

	int size()
	{
		return size(root);
	}

	int min()
	{
		return min(root);
	}

	int max()
	{
		return max(root);
	}

	bool search(int value)
	{
		return search(root, value);
	}

	int maxDepth()
	{
		return maxDepth(root);
	}

	Node *deleteNode(int value)
	{
		return deleteNode(root, value);
	}

	~Tree()
	{
		clearTree(root);
		root = NULL;
	}
};

int main()
{
	Tree t;
	t.insert(40);
	t.insert(60);
	t.insert(30);
	t.insert(10);
	t.insert(80);
	t.insert(50);

	cout << "PreOrder: ";
	t.preorder();
	cout << nl;
	cout << "InOrder: ";
	t.inorder();
	cout << nl;
	cout << "PostOrder: ";
	t.postorder();
	cout << nl;
	cout << "Size: " << t.size() << nl;
	cout << "Max: " << t.max() << nl;
	cout << "Min: " << t.min() << nl;
	cout << "Search: " << t.search(10) << nl;
	cout << "MaxDepth: " << t.maxDepth() << nl;

	return 0;
}