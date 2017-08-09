#include <iostream>
#include <string>
#include <unordered_map>
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
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
		vector<int> diff(gas.size());
		for (int i = 0 ; i < gas.size() ; i++){
			diff[i] = gas[i] - cost[i];
		}
		int curMax, ansMax, maxIdx;
		for (int i = 0 ; i < diff.size()*2 ; i++){
			if (i == 0){
				curMax = diff[0];
				ansMax = diff[0];
				maxIdx = 0;
			} else {
				int ti = i % diff.size();
				curMax += diff[ti];
				if (curMax < diff[ti]){
					curMax = diff[ti];
				}
				if (curMax > ansMax){
					ansMax = curMax;
					maxIdx = ti;
				}
			}
		}
		if (diff.size()==1 && ansMax == 0)
			return 0;
		if (ansMax <= 0)
			return -1;
		//cout << ansMax << endl;
		while(true){
			if (ansMax == diff[maxIdx])
				break;
			ansMax -= diff[maxIdx];
			if (maxIdx == 0)
				maxIdx = diff.size() - 1; 
			else
				maxIdx--;
		}
		int idx = (maxIdx+1 ) % diff.size();
		curMax = diff[maxIdx];
		while(idx!=maxIdx){
			curMax += diff[idx];
			if (curMax <0)
				return -1;
			idx = (idx+1)%diff.size();
		}
		return maxIdx;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2};
	int B[] = {2,1};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.canCompleteCircuit(da,db);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
