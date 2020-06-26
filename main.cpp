#include<iostream>
#include <vector>
#include <map>
using namespace std;
#define NULL 0

struct Node {
	int data;
	Node* lptr;
	Node* rptr;
};

void CreateArrayWithLevel(Node* root,int index,vector<pair<int,int>> &Tree) {
	if (root == NULL)
		return;
	pair<int, int> x(index, root->data);
	Tree.push_back(x);
	CreateArrayWithLevel(root->lptr, index+1, Tree);
	CreateArrayWithLevel(root->rptr, index+1, Tree);
}

void Sort(vector<pair<int, int>> &Tree) {
	int n = Tree.size();
	for (int i = 1; i < n; i++) {
		int k = i;
		for (int j = i - 1; j > -1; j--) {
			if (Tree[j].first > Tree[k].first) {
				pair<int, int> ch = Tree[k];
				Tree[k] = Tree[j];
				Tree[j] = ch;
				k = j;
			}
		}
	}
}

Node* CreateNode(int x) {
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->lptr = NULL;
	p->rptr = NULL;
	return p;
}

int main() {
	Node* root = CreateNode(4);
	root->lptr = CreateNode(2);
	root->rptr= CreateNode(5);
	root->lptr->lptr = CreateNode(1);
	root->lptr->rptr = CreateNode(3);
	int index = 0,n;
	vector<pair<int, int>> Tree;
	CreateArrayWithLevel(root, index, Tree);
	n = Tree.size();
	for (int i = 0; i < n; i++) {
		cout << Tree[i].second << " ";
	}
	return 0;
}
