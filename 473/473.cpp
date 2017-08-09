#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
class Solution {
	public:
	vector<bool> used;
	vector<int> subsetSum;
	bool makesquare(vector<int>& nums){
		int k = 4;
		int size = nums.size();
		int sum = 0;
		if (size < k)
			return false;
		for (int i = 0 ; i < nums.size() ; i++)
			sum+= nums[i];
		if (sum%k != 0)
			return false;
		int target = sum/k;
		
		used.clear();
		for (int i = 0 ; i < size ; i++)
			used.push_back(false);
		
		subsetSum.clear();
		for (int i = 0 ; i < size ; i++)
			subsetSum.push_back(0);

		return isKpHelper(nums, 0, subsetSum, 0, target, k);
	}

	bool isKpHelper(vector<int>& nums, int start,
					vector<int>& setSum, int setIdx, int target,int k)
	{
		if(setSum[setIdx] == target){
			if (setIdx == k-2)// already finished 3 set, dont have to do last set
				return true;
			return isKpHelper(nums, 0, setSum, setIdx+1, target, k);
		} else if (setSum[setIdx] >= target) {
			return false;
		}
		
		for (int i = start ; i < nums.size() ; i++){
			bool nxt;
			if (!used[i]){
				used[i] = true;
				setSum[setIdx] += nums[i];
				nxt = isKpHelper(nums, i+1, setSum, setIdx, target, k);
				setSum[setIdx] -= nums[i];
				used[i] = false;
			}
			if (nxt)
				return true;
		}
		return false;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	bool ret;
	int A[] = {1,1,2,2,2};
	//int A[] = {2,1,4,5,3,3};
	genVector(da, A);
	Solution sol;
	ret = sol.makesquare(da);
	cout << ret << "\n";

	return 0;
}
