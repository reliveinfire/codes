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

class Solution {
	public:
	ListNode* oddEvenList(ListNode* head){
		if (head == NULL)
			return NULL;
		ListNode od(0);
		ListNode ev(0);
		ListNode* odd = &od;
		ListNode* even = &ev;
		ListNode* cur = head;
		int isOdd = 1;
		while(cur!=NULL){
			if (isOdd){
				odd->next = cur;
				odd = odd->next;
			} else{
				even->next = cur;
				even = even->next;
			}
			isOdd ^= 1;
			cur = cur->next;
		}
		odd->next = ev.next;
		even->next == NULL;
		return od.next;
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
