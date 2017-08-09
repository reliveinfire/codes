#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct mycompare{
	bool operator() (const ListNode* a, const ListNode* b) const {
		return a->val > b->val;
	}
};
class Solution {
	public:
	ListNode* mergeKLists(vector<ListNode*>& lists){
		priority_queue<ListNode*, vector<ListNode*>, mycompare> pq;

		for (int i = 0 ; i < lists.size() ; i++){
			if (lists[i])
				pq.push(lists[i]);
		}
		ListNode dummy(0);
		ListNode* idx = &dummy;
		while(!pq.empty()){
			ListNode* insert = pq.top();
			pq.pop();
			idx->next = insert;
			idx = idx->next;
			if (insert->next)
				pq.push(insert->next);
		}
		idx->next =NULL;
		return dummy.next;
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
