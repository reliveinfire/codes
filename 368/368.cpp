#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
class Solution {
	public:
	vector<int> largestDivisibleSubset(vector<int>& nums){
		sort(nums.begin(), nums.end());
		vector<int> pre(nums.size(), -1);
		vector<int> dp(nums.size(), 1);
		vector<int> result;
		if (nums.empty())
			return result;
		int maxpos = 0;
		int maxdp = -1;

		for (int i = 1 ; i < nums.size() ; i++){
			for (int j = 0 ; j < i ; j++){
				if (nums[i] % nums[j] == 0){
					if (dp[j]+1 > dp[i]){
						dp[i] = dp[j]+1;
						pre[i] = j;
					}
					if (dp[i] > maxdp){
						maxpos = i;
						maxdp = max(maxdp, dp[i]);
					}
				}
			}
		}
#if 0
		cout << maxpos << endl;
		for (int i = 0 ; i < pre.size() ; i++)
			cout << " " << pre[i];
		cout << endl;
		for (int i = 0 ; i < pre.size() ; i++)
			cout << " " << dp[i];
		cout << endl;
#endif
		while(true){
			result.push_back(nums[maxpos]);
			if (pre[maxpos] == -1)
				break;
			else
				maxpos = pre[maxpos];
		}
		return result;
	}

};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {2,3,4,8,9};
	int B[] = {3,5,7};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	int ret;
	ret_vec = sol.largestDivisibleSubset(da);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;
	
	ret_vec = sol.largestDivisibleSubset(db);
	
	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
