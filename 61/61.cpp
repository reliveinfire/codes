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
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
	ListNode* rotateRight(ListNode* head, int k){
		if (head==NULL)
			return head;
		int len = 0;
		ListNode* idx = head;
		while(idx!=NULL){
			len++;
			idx = idx->next;
		}
		k = k % len;
		if (k == 0)
			return head;
		ListNode* first = head;
		ListNode* second = head;
		for (int i = 0 ; i < k ; i++){
			if (first->next!=NULL)
				first = first->next;
		}
		while(first->next != NULL){
			first = first->next;
			second = second->next;
		}
		ListNode* ans = second->next;
		first->next = head;
		second->next = NULL;
		return ans;
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
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head = sol.rotateRight(head, 3);
	cout << head->val<< endl;
	head = head->next;
	cout << head->val<< endl;

	cout <<endl;

	return 0;
}
