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

class element{
	public:
	int pos1;
	int pos2;
	int val;
	element(int p1, int p2, int val):pos1(p1), pos2(p2), val(val){}
};
struct mycompare{
	bool operator()(const element& ll, const element& rr) const{
		return ll.val > rr.val;
	}
};
class Solution {
	public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
		vector<pair<int,int>> ans;
		if (nums1.empty() || nums2.empty())
			return ans;
		priority_queue<element, vector<element>, mycompare> pq;
		for (int i = 0 ; i < nums1.size() ; i++){
			element elm(i, 0, nums1[i] + nums2[0]);
			pq.push(elm);
		}
		for (int i = 0 ; i < k ; i++){
			if (i == nums1.size() * nums2.size())
				break;
			element elm = pq.top();
			pq.pop();
			cout << elm.pos1 ":" << elm.pos2 << endl;
			ans.push_back(pair<int,int>(nums1[elm.pos1], nums2[elm.pos2]));
			if (elm.pos2 < nums2.size()){
				element elm2(elm.pos1, elm.pos2+1, nums1[elm.pos1] + nums2[elm.pos2+1]);
				pq.push(elm2);
			}
		}
		return ans;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,1,2};
	int B[] = {1,2,3};
	genVector(da, A);
	genVector(db, B);
	vector<pair<int,int>> ret_vec;
	Solution sol;
	ret_vec = sol.kSmallestPairs(da,db,10);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i].first << "," << ret_vec[i].second<<endl;
	cout <<endl;

	return 0;
}
