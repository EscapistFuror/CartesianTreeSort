#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

typedef pair<int, Node*> Pair;

void pQBasedTraversal(Node* root)
{
	priority_queue <Pair, vector<Pair>, greater<Pair> > pQ;
	pQ.push (make_pair (root->data,root));
	while (! pQ.empty())
	{
		Pair pop = pQ.top();
		printf("%d ",pop.first);
		pQ.pop();
		if (pop.second->left != NULL)
			pQ.push (make_pair(pop.second->left->data,
								pop.second->left));
		if (pop.second->right != NULL)
			pQ.push (make_pair(pop.second->right->data,
									pop.second->right));
	}
	return;
}

Node *buildCartesianTree(int root, int arr[],
		int parent[], int lchild[], int rchild[])
{
	if (root == -1)
		return NULL;
	Node *temp = new Node;
	temp->data = arr[root];
	temp->left = buildCartesianTree(lchild[root],
				arr, parent, lchild, rchild);
	temp->right = buildCartesianTree(rchild[root],
				arr, parent, lchild, rchild);
	return temp ;
}

Node *makeCartesianTree(int arr[], int n)
{
	int parent[n],lchild[n],rchild[n];
	memset(parent, -1, sizeof(parent));
	memset(lchild, -1, sizeof(lchild));
	memset(rchild, -1, sizeof(rchild));
	int root = 0, last;
	for (int i=1; i<=n-1; i++)
	{
		last = i-1;
		rchild[i] = -1;
		while (arr[last] >= arr[i] && last != root)
			last = parent[last];
		if (arr[last] >= arr[i])
		{
			parent[root] = i;
			lchild[i] = root;
			root = i;
		}
		else if (rchild[last] == -1)
		{
			rchild[last] = i;
			parent[i] = last;
			lchild[i] = -1;
		}
		else
		{
			parent[rchild[last]] = i;
			lchild[i] = rchild[last];
			rchild[last]= i;
			parent[i] = last;
		}
	}
	parent[root] = -1;
	return (buildCartesianTree(root, arr, parent,lchild, rchild));
}
int main()
{
	int arr[] = {3, 4, 7, 34, 45,19,80};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Input array is-\n");
	printf("3 4 7 34 45 19 80\n");
	Node *root= makeCartesianTree(arr,n);
	printf("The sorted array is-\n");
	pQBasedTraversal(root);
	return(0);
}
