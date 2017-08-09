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

class Solution {
	public:
	 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	 	int lenA = 0, lenB = 0;
		ListNode* idx = headA, idxA, idxB;
		while(idx!= NULL){
			lenA++;	idx = idx->next;
		}
		idx = headB;
		while(idx != NULL){
			lenB++; idx = idx->next;
		}
		idxA = headA;
		idxB = headB;
		if (lenA > lenB){
			for (int i = 0 ; i < lenA-lenB ; i++)
				idxA = idxA->next;
		} else if (lenB > lenA){
			for (int i = 0 ; i < lenB-lenA ; i++)
				idxB = idxB->next;
		}
		while(idxA != NULL && idxB != NULL){
			if (idxA==idxB)
				return idxA
			else{
				idxA = idxA->next;
				idxB = idxB->next;
			}
		}
		return NULL;
		
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
