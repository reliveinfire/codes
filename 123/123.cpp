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
	int maxProfit(vector<int>& prices){
		if (prices.size() < 2)
			return 0;
		vector<int> value(prices.size());
		vector<int> valueEnd(prices.size()); //i, i to end, max
		int curMax = INT_MIN, curMin = INT_MAX;
		int profit = 0;
		for (int i = prices.size() - 1 ; i>=0 ; i--){
			if (prices[i] > curMax){
				curMax = prices[i];
			} else {
				profit = max(profit, curMax - prices[i]);
			}
			valueEnd[i] = profit;
		}
		
		profit = 0;
		for (int i = 0 ; i <  prices.size() ; i++){
			if (prices[i] < curMin){
				curMin = prices[i];
			} else {
				profit = max(profit, prices[i]-curMin);
			}
			value[i] = profit;
		}

		int localMax = 0;
		for (int i = 1 ; i < prices.size() - 2 ; i++){
			localMax = max(localMax, value[i] + valueEnd[i+1]);
		}
		return max(value[prices.size()-1], localMax);
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
