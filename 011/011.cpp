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
	int maxArea(vector<int>& height){
		stack<int> st;
		int i, ans = INT_MIN;
		for (i = 0 ; i < height.size() ; i++){
			if (st.empty() || height[i]>= height[st.top()])
				st.push(i);
			else {
				while(!st.empty() && height[i] < height[st.top()]){
					int ti = st.top();
					st.pop();
					if (!st.empty()){
						ans = max(ans, height[ti] * (i-st.top()-1));
					} else {
						ans = max(ans, height[ti]* i);
					}
				}
				st.push(i);
			}
		}
		i = height.size();
		while(!st.empty()){
			int ti = st.top();
			st.pop();
			if (!st.empty()){
				ans = max(ans, height[ti] * (i-st.top()-1));
			} else {
				ans = max(ans, height[ti]* i);
			}
		}
		return ans;		
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {4,2,0,3,2,5};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.maxArea(da);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
