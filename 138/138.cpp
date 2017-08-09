#include <iostream>
#include <string>
#include <unordered_map>
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

class Solution {
	public:
	RandomListNode *copyRandomList(RandomListNode *head){
		unordered_map<RandomListNode*,RandomListNode*> map; // orig, copy
		return clone(head,map);
	}

	RandomListNode* clone(RandomListNode* node, unordered_map<RandomListNode*,RandomListNode*>& map){
		if (node == NULL)
			return NULL;

		if (map.find(node)!=map.end()){
			return map[node];
		}
		RandomListNode* cur = new RandomListNode(node->label);
		map[node] = cur;
		cur->next = clone(node->next,map);
		cur->random = clone(node->random,map);
		return cur;
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
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.
	ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
