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
	void reorderList(ListNode* head){
		if (!head || head->next == NULL)
			return;
		ListNode *slow, *fast;
		slow = fast = head;
		while(fast->next && fast->next->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* second = slow->next;
		slow->next = NULL;
		ListNode *i, *j, *k;
		j = k = second;
		i = second->next;
		while(i!=NULL){
			j = i;
			i = i->next;
			j->next = k;
			k = j;
		}
		second->next = NULL;
		i = head;
		ListNode dummy(0);
		k = &dummy;
		while(i!=NULL && j!=NULL){
			k->next = i;
			i = i->next;
			k = k->next;

			k->next = j;
			j = j->next;
			k = k->next;
		}

		if (i!=NULL){
			k->next = i;
			k = k->next;
		}
		k->next = NULL;
		head = dummy.next;
		return;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	ListNode* head = new ListNode(1);
	ListNode* idx = head;
	idx->next = new ListNode(2);
	idx = idx->next;
	idx->next = new ListNode(3);
	Solution sol;
	sol.reorderList(head);

	while(head!=NULL){
		cout << head->val<<endl;
		head = head->next;
	}


	return 0;
}
