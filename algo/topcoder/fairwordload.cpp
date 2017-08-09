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
	int FairWordload(vector<int>& folder, int part){
		vector<int> preSum(folder.size() + 1);
		int sum = 0;
		preSum[0] = 0;
		for (int i = 0 ; i < folder.size() ; i++){
			sum += folder[i];
			preSum[i+1] = sum;
		}
		return helper(folder, 0, folder.size()-1, part, preSum);
	}

	int helper(vector<int>& folder, int lo, int hi, int part, vector<int>& preSum){
		int currMin = INT_MAX;
		if (part == 1){
			return preSum[hi+1] - preSum[lo];
		}
#if 1
		for (int i = lo + part - 2; i < hi ; i++){
			int left = helper(folder, lo, i, part -1, preSum);
			int right =  preSum[hi+1] - preSum[i+1];
			int lm = max (left,right);
			currMin = min(lm, currMin);
		}
#else
		int ll = lo + part -2, rr = hi;
		while( ll < rr){
			int mid = ll + (rr - ll) / 2;
			int left = helper(folder, lo, mid, part -1, preSum);
			int right =  preSum[hi+1] - preSum[mid+1];
			if (left > right)
				rr = mid;
			else
				ll = mid + 1;
			int lm = max(left,right);
			currMin = min(lm,currMin);
		}
#endif
		return currMin;
	}
};

class Solution2 {
	public:
	int FairWordload(vector<int>& folder, int part){
		vector<int> preSum(folder.size() + 1);
		vector<vector<int> > dp(part + 1, vector<int>(folder.size(), 0));
		int sum = 0;
		preSum[0] = 0;
		for (int i = 0 ; i < folder.size() ; i++){
			sum += folder[i];
			preSum[i+1] = sum;
		}

		for (int i = 1 ; i <= part ; i++){
			for (int j = 0 ; j < folder.size() ; j++){
				int currMin = INT_MAX;
				for (int k = j - 1 ; k >= i - 1 ; k--){
					int lm = max(dp[i-1][k], preSum[j+1] - preSum[k+1]);
					currMin = min(lm, currMin);
				}
				dp[i][j] = currMin;
			}
			
		}
		return dp[part+1][folder.size() - 1];
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	//int A[] = {10,20,30,40,50,60,70,80,90};
	int A[] = {10,20,30,40,50};
	int B[] = {568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782};
	int C[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1000};
	int D[] = {950, 650, 250, 250, 350, 100, 650, 150, 150, 700};
	genVector(da, A);
	genVector(db, B);
	genVector(dc, C);
	genVector(dd, D);
	Solution sol;
	Solution sol2;
	vector<int> ret_vec;
	int ret;
	cout << sol.FairWordload(dd,6);
	cout << endl;
	cout << sol2.FairWordload(dd,6);
	cout << endl;
//	cout << sol.FairWordload(db,4);
//	cout << endl;
//	cout << sol.FairWordload(dc,2);
//	cout << endl;
//	cout << sol.FairWordload(dd,6);
//	cout << endl;

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
