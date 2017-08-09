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

class NumArray {
public:
    NumArray(vector<int> nums) {
    	int sum = 0;
	for (int i = 0 ; i < nums.size() ; i++){
		sum += nums[i];
		preSum.push_back(sum);
	}
    }

    int sumRange(int i, int j) {
    		if (preSum.empty())
			return 0;
		if (i == 0 )
			return preSum[j];
		else
			return preSum[j] - preSum[i-1];
    }
private:
	vector<int> preSum;
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
	vector<int> ret_vec;
	int ret;
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
