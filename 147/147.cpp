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
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
	public:
	ListNode* insertionSortList(ListNode* head){
		ListNode dummy(0);
		ListNode* k = &dummy;
		ListNode* idx = head;
		
		ListNode orig(0);
		orig.next = head;

		while(orig.next != NULL){
			int curMin = INT_MAX;
			ListNode* pre = &orig;
			ListNode* maxPre;
			while(pre->next!=NULL){
				if (pre->next->val <= curMin){
					curMin = pre->next->val;
					maxPre = pre;
				}
				pre = pre->next;
			}
			k->next = maxPre->next;
			k = k->next;
			maxPre->next = maxPre->next->next;
		}
		k->next = NULL;
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
#if 1
	ListNode* head = new ListNode(2147483647);
	head->next = new ListNode(2147483646);
#else
	ListNode* head = new ListNode(1);
	head->next = new ListNode(9);
	head->next->next = new ListNode(3);
#endif

	ListNode* rr = sol.insertionSortList(head);
	while(rr!=NULL){
		cout << rr->val << endl;
		rr=rr->next;
	}


	return 0;
}
