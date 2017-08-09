#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
	public:
	void connect(TreeLinkNode *root){
		if (root == NULL)
			return;
		TreeLinkNode* pre, *curr,*first,*idx;
		root->next = NULL;
		first = root;
		while(true){
			curr = first;
			pre = NULL;
			while(true){
				if (curr->left && curr->right)
					curr->left->next = curr->right;
				if (pre){
					if (pre->right){
						if (curr->left){
							pre->right->next = curr->left;
						} else if (curr->right){
							pre->right->next = curr->right;
						}
					} else if (pre->left){
						if (curr->left){
							pre->left->next = curr->left;
						} else if (curr->right){
							pre->left->next = curr->right;
						}
					}
				}
				if (curr->next == NULL){
					if (curr->right)
						curr->right->next = NULL;
					else if (curr->left)
						curr->left->next = NULL;
					else if (pre){
						if (pre->right)
							pre->right->next = NULL;
						else if (pre->left)
							pre->left->next = NULL;
					}
					break;
				} else{
					if (curr->left || curr->right)
						pre = curr;
					curr = curr->next;
				}
			}
			idx = first;
			first = NULL;
			while(idx!=NULL){
				if (idx->left){
					first = idx->left;
					break;
				} else if (idx->right){
					first = idx->right;
					break;
				}
				idx = idx->next;
			}
			if (!first)
				break;
		}
		return;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	vector<int> ret_vec;
	TreeLinkNode* root = new TreeLinkNode(1);
	int ret;
	Solution sol;
	sol.connect(root);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
