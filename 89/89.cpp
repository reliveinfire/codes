#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	vector<int> ans;
	bool found;
	vector<int> grayCode(int n){
		vector<int> ans;
		unordered_set<int> used;
		int count = 1;
		for (int i = 0 ; i < n ; i++){
			count = count * 2;
		}
		int now = 0;
		ans.push_back(now);
		used.insert(now);
		for (int i = 0 ; i < count -1 ; i++){
			for (int j = 0 ; j < 32 ; j++){
				int next = now ^ (0x1<<j);
				if (used.count(next)==0){
					now = next;
					used.insert(now);
					ans.push_back(now);
					break;
				}
			}
		}

		return ans;
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
	ret_vec = sol.grayCode(3);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
