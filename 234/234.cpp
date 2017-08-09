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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	ListNode *slow,*fast;
	slow = fast = head;
	if (head==NULL || head->next == NULL)
		return true;
	while(fast->next !=NULL && fast->next->next !=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode* second = slow->next;
	ListNode* first;
	if (fast->next != NULL) //even
       		first = rev(head, slow->next);
	 else 
	 	first = rev(head, slow);
	cout << first->val << endl;
	cout << second->val << endl;
	while(first!=NULL){
		if (first->val != second->val)
			return false;
		first = first->next;
		second = second->next;
	}
	return true;
    }
    ListNode* rev(ListNode* head, ListNode* end){
    		ListNode *i,*j,*k;
		i = head;
		j = k = NULL;
		while(i !=end){
			j = i;
			i = i->next;
			j->next = k;
			k = j; 
		}
		return j;
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
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	Solution sol;
	cout << sol.isPalindrome(head);
	vector<int> ret_vec;
	int ret;

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
