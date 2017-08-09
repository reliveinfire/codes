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
	int maxRotateFunction(vector<int>& A){
		int sum = 0;
		int n = A.size() - 1;
		for (int i = 0 ; i < A.size() ; i++)
			sum += A[i];
		int first = 0;
		for (int i = 0 ; i < A.size() ; i++)
			first += i * A[i];
		int ans = first;
		for (int i = A.size() - 1 ; i > 0 ; i--){
			first = first + sum - A[i] - A[i]* n;
			ans = max(ans, first);
		}
		return ans;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {4,3,2,6};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.maxRotateFunction(da);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
