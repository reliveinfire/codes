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
	string countAndSay(int n){
		string pre("1"), curr;
		for(int i = 2 ; i <= n ; i++){
			curr.clear();
			int count;
			for (int j = 0 ; j < pre.size() ; j++){
				if (j==0){	
					count = 1;
				} else {
					if (pre[j] == pre[j-1]){
						count++;
					} else {
						curr += to_string(count);
						curr += pre[j-1];
						count = 1;
					}
				}
			}
			curr += to_string(count);
			curr += pre[pre.size()-1];
			pre = curr;
		}
		return pre;	
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
