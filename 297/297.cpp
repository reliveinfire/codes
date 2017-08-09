#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
TreeNode* genBST(vector<int>& pre)
{
        int idx = 0;
        TreeNode* node = new TreeNode(pre[idx++]);
        stack<TreeNode*> st;
        st.push(node);
        while(idx < pre.size()){
                if (pre[idx] < st.top()->val){
                        st.top()->left = new TreeNode(pre[idx++]);
                        st.push(st.top()->left);
                } else {
                        TreeNode* tmp;
                        while(!st.empty() && st.top()->val < pre[idx]){
                                tmp = st.top();
                                st.pop();
                        }
                        tmp->right = new TreeNode(pre[idx++]);
                        st.push(tmp->right);
                }
        }
        return node;
}


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		string ans;
		preorder(root, ans);
		ans = ans.substr(0, ans.size() - 1);
		return ans;
    }

    void preorder(TreeNode* node, string& ans){
    	if (node == NULL){
		ans += string("#") + string(",");
		return;
	}
	ans += to_string(node->val) + string(",");
	preorder(node->left, ans);
	preorder(node->right, ans);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
    	stringstream ss(s);
	string token;
	queue<string> data;
	while(getline(ss, token, ',')){
		data.push(token);
	}
	return genTree(data);
    }

    TreeNode* genTree(queue<string>& data){
    	if (data.front() == string("#")){
		data.pop();
		return NULL;
	} else {
		TreeNode* node = new TreeNode(stoi(data.front()));
		data.pop();
		node->left = genTree(data);
		node->right = genTree(data);
		return node;
	}
    }
};

void preorder(TreeNode* node){
	if (node == NULL)
		return;
	cout << node->val << " ";
	preorder(node->left);
	preorder(node->right);
}

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	string tre("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	TreeNode* node = cc.deserialize(tre);
	cout <<  cc.serialize(node) << endl;
	preorder(node);


	return 0;
}
