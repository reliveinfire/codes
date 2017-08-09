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
	ListNode* removeNthFromEnd(ListNode* head, int n){
		ListNode* ll, *rr;
		ListNode dummy(0);
		dummy.next = head;
		ll = rr =  head;
		for (int i = 0 ; i < n ; i++)
			rr = rr->next;
		if (rr==NULL){
			dummy.next = dummy.next->next;
			return dummy.next;
		}
		while(rr->next!=NULL){
			ll = ll->next;
			rr = rr->next;
		}
		ll->next = ll->next->next;
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
