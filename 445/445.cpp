#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	void insertNode(ListNode* head, int value){
		ListNode* node;
		node = new ListNode(value);
		node->next = head->next;
		head->next = node;
		return;
	}
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			vector<int> A;
			vector<int> B;
			ListNode* idx;
			ListNode* dummy = new ListNode(0);
			int tmp;
			if (l1 == NULL)
				return l2;
			if (l2 == NULL)
				return l1;

			idx = l1;
			while(l1 != NULL) {
				A.push_back(l1->val);
				l1 = l1->next;
			}
			
			idx = l2;
			while(l2 != NULL) {
				B.push_back(l2->val);
				l2 = l2->next;
			}

			int carry = 0;
			ListNode* add;
			while( !A.empty() && !B.empty()){
				tmp = carry + A.back() + B.back();
				A.pop_back();
				B.pop_back();
				carry = tmp /10;
				tmp = tmp % 10;
				insertNode(dummy, tmp);
			}

			while (!A.empty()){
				tmp = carry + A.back();
				A.pop_back();
				carry = tmp /10;
				tmp = tmp % 10;
				insertNode(dummy, tmp);
			}
			
			while (!B.empty()){
				tmp = carry + B.back();
				B.pop_back();
				carry = tmp /10;
				tmp = tmp % 10;
				insertNode(dummy, tmp);
			}

			if (carry){
				insertNode(dummy, 1);
			}
			return dummy->next;

		}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));


ListNode* genList(int A[], int size)
{
	ListNode* head = new ListNode(A[0]);
	ListNode* idx = head;
	for (int i = 1 ; i < size ; i++){
		idx->next = new ListNode(A[i]);
		idx = idx->next;
	}
	idx->next = NULL;
	return head;
}
int main()
{
	int ret;
	int A[] = {7,2,4,3};
	int B[] = {9,9,6,4};
	ListNode* L1 = genList(A,4);
	ListNode* L2 = genList(B,4);
	Solution sol;
	ListNode* ans = sol.addTwoNumbers(L1,L2);
	while(ans!=NULL){
		cout << " " << ans->val;
		ans = ans->next;
	}
	

	return 0;
}
