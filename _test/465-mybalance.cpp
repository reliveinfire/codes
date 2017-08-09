#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;
#include "../helpers.cpp"

bool pass(vector<int>& nums, vector<int>& bucket)
{
	for (int i = 0 ; i < nums.size() ; i++)
		if (nums[i]!=0)
			return false;
	for (int item : bucket)
		if(item!=0)
			return false;
	return true;
}
void helper(vector<int>& nums, vector<int>& bucket, int& ans, int count)
{
	if (pass(nums, bucket)){
		ans = min(ans, count);
		return;
	}
	for (int i = 0 ; i < nums.size() ; i++ ){
		if (nums[i]==0)
			continue;
		for (int j = 0 ; j < bucket.size() ; j++){
			if (bucket[j]==0)
				continue;
			int in = nums[i];
			int out = bucket[j];
			if (in + out >= 0){
				nums[i] += out;
				bucket[j] = 0;
				helper(nums, bucket, ans, count+1);
				nums[i] -= out;
				bucket[j] = out;
			} else {
				nums[i] = 0;
				bucket[j] += in;
				helper(nums, bucket, ans, count+1);
				nums[i] = in;
				bucket[j] -= in;
			}
		}
	}
	return;
}

int minTrans(vector<int>& nums, vector<int>& bucket)
{
	int ans = INT_MAX;
	helper(nums, bucket, ans, 0);
	return ans;
}

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	//vector<int> A = {1,2,3,4,4,5,6};
	vector<int> nums = {8,2,2};
	vector<int> bucket = {-3,-4,-5};
	cout << minTrans(nums, bucket);

	return 0;
}
