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
#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};

void Iterpreorder(TreeNode* node){
	stack<TreeNode*> st;
	st.push(node);
	string ans;
	while(!st.empty()){
		if (st.top()!=NULL){
			cout << st.top()->val << " ";
			st.push(st.top()->left);
		} else {
			st.pop();
			if (!st.empty()){
				TreeNode* tmp = st.top()->right;
				st.pop();
				st.push(tmp);
			}
		}
	}
	ans = ans.substr(0, ans.size() - 1);
	cout << endl << ans << endl;
	return;
}

void Iterinorder(TreeNode* node){
	stack<TreeNode*> st;
	st.push(node);
	while(!st.empty()){
		if (st.top()!=NULL){
			st.push(st.top()->left);
		} else {
			st.pop();
			if (!st.empty()){
				cout << st.top()->val << " ";
				TreeNode* tmp = st.top()->right;
				st.pop();
				st.push(tmp);
			}
		}
	}
	return;
}

bool detX(vector<int>& nums){
	map<int,int> map;
	for (int item : nums)
		map[item]++;
	return helper(map);
}

bool helper(map<int,int> map)
{
	if (map.size() == 0){
		return true;
	}
	for (int i = 3 ; i <= map.size() ; i++){
		map<int,int> tmp = map;
		if (checkX(i, tmp)){
			int ret = helper(tmp);
			if (ret)
				return true;
		}
	}
	return false;
}

bool checkX(int X, map<int,int>& map){
	if (map.size() < X)
		return false;
	int pre;
	for (auto iter = map.begin(), i = 0; i < X ; i++){
		if (i == 0){
			pre = iter->first;
		} else {
			if (pre != iter->first - 1)
				return false;
			else
				pre = iter->first;
		}
	}
	vector<map<int,int>::iterator> erase;
	for (auto iter= map.begin(), i < 0 ; i < X ; i++){
		iter->second--;
		if (iter->second == 0)
			erase.push_back(iter);
	}
	for (int i = 0 ; i < erase.size() ; i++){
		map.erase(erase[i]);
	}
	return true;
}

void preorder(TreeNode* node){
        if (node == NULL)
                return;
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
}

void inorder(TreeNode* node){
        if (node == NULL)
                return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
}


#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	vector<int> ret_vec;
	int ret;
	Codec cc;
	string treA("1,#,3,2,#,#,4,#,5,#,#");
	string treB("9,3,4,#,#,1,#,#,2,#,6,#,#");
	TreeNode* rootA= cc.deserialize(treA);
	TreeNode* rootB= cc.deserialize(treB);
	cout << "\npre recursive:\n";
	preorder(rootB);
	cout << "\npre iterator:\n";
	Iterpreorder(rootB);
	
	cout << "\ninorder recursive:\n";
	inorder(rootB);
	cout << "\ninorder iterator:\n";
	Iterinorder(rootB);


	return 0;
}
