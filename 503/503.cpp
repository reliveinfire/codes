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
#if 0
class Solution {
	public:
	vector<int> nextGreaterElements(vector<int>& nums){
		int j;
		vector<int> result;
		for (int i = 0 ; i < nums.size() ; i++)	{
			int target = nums[i];
			j = (i+1) % nums.size();
			while(j!=i) {
				if (nums[j] > target) {
					result.push_back(nums[j]);
					break;
				}
				j = (j+1) % nums.size();
			}
			if (j == i)
				result.push_back(-1);
		}
		return result;
	}
};
#else
class Solution {
	public:
	vector<int> nextGreaterElements(vector<int>& nums){
		int j;
		vector<int> result(nums.size(), -1);
		stack<int> ss;
		for (int k = 0 ; k < nums.size() * 2 ; k++){
			int i = k % nums.size();
			while(!ss.empty() && nums[i] >nums[ ss.top()]){
				result[ss.top()] = nums[i];
				ss.pop();
			}
			ss.push(i);
		}
		return result;
	}
};
#endif

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	int A[] = {1,2,1};
	int B[] = {1,2,3};
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	ret_vec = sol.nextGreaterElements(da);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
