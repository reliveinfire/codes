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
};

class Solution {
	public:
	ListNode* swapPairs(ListNode* head){
		if (!head)
			return head;
		ListNode da(0);
		ListNode db(0);
		ListNode dc(0);
		ListNode* idx = head;
		ListNode* ia = &da, *ib = &db;
		int num = 0;
		while(idx != NULL){
			if (!num){
				ia->next = idx;
				ia = ia ->next;
			} else {
				ib->next = idx;
				ib = ib->next;
			}
			idx = idx->next;
			num = num^1;
		}
		idx = &dc;
		ia = da.next, ib = db.next; num = 0;
		while(ia && ib){
			if (!num){
				idx->next = ib;
				ib = ib->next;
			} else {
				idx->next = ia;
				ia = ia->next;
			}
			num = num^1;
			idx = idx->next;
		}
		if (ia)
			idx->next = ia;
		else if(ib)
			idx->next = ib;
		idx = idx->next;
		idx->next = NULL;
		return dc.next;
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
