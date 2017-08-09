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
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k){
		return helper(nums1, nums2, 0, 0, k);
	}

	vector<int> helper(vector<int>& nums1, vector<int>& nums2, int idx1, int idx2, int k)
	{
		cout << idx1 <<":" <<idx2 << "  k:"<<k <<endl;
		int curMax = INT_MIN;
		int n1_maxIdx = -1, n2_maxIdx = -1;
		int n1_left = nums1.size() - idx1;
		int n2_left = nums2.size() - idx2;
		vector<int> ret;
		if (k==0)
			return ret;
		int bound =  min(nums1.size() + n2_left - k+1,nums1.size());
		for (int i = idx1 ; i < bound; i++){
			cout << i << endl;
			if (nums1[i] > curMax){
				n1_maxIdx = i;
				curMax = nums1[i];
			}
		}
		curMax = INT_MIN;
		bound =  min(nums2.size() + n1_left - k+1,nums2.size());
		for (int i = idx2 ; i < bound; i++){
			cout << i << endl;
			if (nums2[i] > curMax){
				n2_maxIdx = i;
				curMax = nums2[i];
			}
		}
		cout << "  n1_maxIdx:" << n1_maxIdx;
		cout << "  n2_maxIdx:" << n2_maxIdx;
		cout << endl;
		if (n1_maxIdx < 0){
			ret = helper(nums1,nums2, idx1, n2_maxIdx+1, k-1);
			ret.insert(ret.begin(), nums2[n2_maxIdx]);	
			return ret;
		} else if (n2_maxIdx < 0){
			ret = helper(nums1, nums2, n1_maxIdx+1, idx2, k-1);
			ret.insert(ret.begin(), nums1[n1_maxIdx]);
			return ret;
		}
		if (nums1[n1_maxIdx] > nums2[n2_maxIdx]){
			ret = helper(nums1, nums2, n1_maxIdx+1, idx2, k-1);
			ret.insert(ret.begin(), nums1[n1_maxIdx]);
		} else if (nums2[n2_maxIdx] > nums1[n1_maxIdx]){
			ret = helper(nums1,nums2, idx1, n2_maxIdx+1, k-1);
			ret.insert(ret.begin(), nums2[n2_maxIdx]);
		} else {
			cout << "same\n";
			vector<int> ret1 = helper(nums1, nums2, n1_maxIdx+1, idx2, k-1);
			vector<int> ret2 = helper(nums1,nums2, idx1, n2_maxIdx+1, k-1);
			cout << "ret1:";
			for (int i = 0 ; i < ret1.size() ;i++){
				cout << ret1[i]<< " ";
			}
			cout << endl;
			cout << "ret2:";
			for (int i = 0 ; i < ret2.size() ;i++){
				cout << ret2[i]<< " ";
			}
			cout << endl;
			ret = ret1;
			for (int i = 0 ; i < ret1.size() ;i++){
				if(ret1[i] > ret2[i]){
					cout << "pick ret1\n" << endl;
					ret = ret1;
					break;
				}
				else if(ret1[i] < ret2[i]){
					ret = ret2;
					break;
				}
			}
			cout << "ret:";
			for (int i = 0 ; i < ret.size() ;i++){
				cout << ret[i]<< " ";
			}
			cout << endl;
			ret.insert(ret.begin(), nums1[n1_maxIdx]);
		}
		return ret;
	}
};


#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
#if 0
	int A[] = {3,4,6,5};
	int B[] = {9,1,2,5,8,3};
//	int A[] = {6,7};
//	int B[] = {6,0,4};
	int k = 5;
#else
	int A[] = {5,1,0};
	int B[] = {5,2,1};
	int k = 3;
#endif
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret_vec = sol.maxNumber(da,db,k);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
