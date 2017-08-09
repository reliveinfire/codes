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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
	ListNode* reverseKGroup(ListNode* head, int k){
		ListNode dummy(0);
		ListNode* idx = &dummy;
		ListNode* start = head;
		while(true){
			ListNode* end = start;
			for (int i = 0 ; i < k ; i++){
				if (end!=NULL)	
					end = end->next;
				else {
					idx->next = start;
					return dummy.next;
				}
			}
			idx->next = reverse(start, end);
			idx = start;
			start = end;
		}
		
	}
	ListNode* reverse(ListNode* start, ListNode* end){
		ListNode *i,*j,*k;
		i = start->next;
		j = k = start;
		while(i!=end){
			j = i;
			i = i->next;
			j->next = k;
			k = j;
		}
		start->next = NULL;
		return j;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	ListNode* head = new ListNode(1);
	ListNode* idx = head;
	idx->next = new ListNode(2);
	idx = idx->next;
	idx->next = new ListNode(3);
	idx = idx->next;
	idx->next = new ListNode(4);
	idx = idx->next;
	idx->next = new ListNode(5);
	idx = idx->next;
	int k = 2;
	Solution sol;
	idx = sol.reverseKGroup(head, k);

	while(idx!=NULL){
		cout << idx->val << " ";
		idx = idx->next;
	}
	cout << endl;

	return 0;
}
