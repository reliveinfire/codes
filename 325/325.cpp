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
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};


class Solution {
	public:
	int maxSubArrayLen(vector<int>& nums, int k){
		unordered_map<int,int> pos;  // map<sum,index>
		pos[0] = 0;
		int sum = 0;
		int ans = INT_MIN;
		for (int i = 0 ; i < nums.size() ; i++){
			sum += nums[i];
			if (pos.find(sum-k)!=pos.end()){
				ans = max(ans, i - pos[sum-k] + 1);
			}
			if (pos.find(sum)==pos.end()){
				pos[sum] = i+1;
			}
		}
		return ans;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,-1,5,-2,3};
	vector<int> B = {-2,-1,2,1};
	Solution sol;
	int ret;
	cout << sol.maxSubArrayLen(A,3) << endl;
	cout << sol.maxSubArrayLen(B,1) << endl;
	cout <<endl;

	return 0;
}
