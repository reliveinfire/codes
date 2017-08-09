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
	int maxProfit(vector<int>& prices){
		int profit = 0;
		int min;
		for (int i = 0 ; i < prices.size() ; i++){
			if (i==0){
				min = prices[i];
			} else {
				if (prices[i] > min)
					profit = max(profit, prices[i]-min);
				else
					min = prices[i];
			}
		}
		return profit;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {7,1,5,3,6,4};
	int B[] = {7,6,5,4,3,1};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	int ret;
	ret = sol.maxProfit(da);
	cout << ret << "\n";
	ret = sol.maxProfit(db);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
