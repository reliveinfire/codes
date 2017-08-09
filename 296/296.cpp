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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
TreeNode* genBST(vector<int>& pre)
{
        int idx = 0;
        TreeNode* node = new TreeNode(pre[idx++]);
        stack<TreeNode*> st;
        st.push(node);
        while(idx < pre.size()){
                if (pre[idx] < st.top()->val){
                        st.top()->left = new TreeNode(pre[idx++]);
                        st.push(st.top()->left);
                } else {
                        TreeNode* tmp;
                        while(!st.empty() && st.top()->val < pre[idx]){
                                tmp = st.top();
                                st.pop();
                        }
                        tmp->right = new TreeNode(pre[idx++]);
                        st.push(tmp->right);
                }
        }
        return node;
}


class Solution {
	public:
	int minTotalDistance(vector<vector<int>>& grid){
		int m = grid.size();
		int n = grid[0].size();
		queue<pair<int,int>> qu;
		vector<pair<int,int>> homes;
		for (int i = 0 ; i < grid.size() ; i++){
			for (int j = 0 ; j < grid[0].size() ; i++){
				if (grid[i][j]){
					qu.push(pair<int,int>(i,j));
					homes.push_back(pair<int,int>(i,j));
				}
			}
		}
		int target = qu.size();
		pair<int,int> pos;
		vector<vector<int>> direct = {{1,0},{-1,0},{0,1},{0,-1}};
		while(!qu.empty()){
			int sz = qu.size();
			for (int i = 0 ; i < sz ; i++){
				int row = qu.front().first;
				int col = qu.front().second;
				qu.pop();
				for (int j = 0 ; j < 4 ; j++){
					int nr = row + direct[j][0];
					int nc = col + direct[j][1];
					if (nr>=0 && nr < m && nc>=0 && nc < n){
						grid[nr][nc]++;
						qu.push(pair<int,int>(nr,nc));
						if (grid==target){
							pos.first = nr;
							pos.second = nc;
							break;
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0 ; i < homes.size() ; i++){
			ans += abs(pos.first-homes[i].first) + abs(pos.second - homes[i].second);
		}
		return ans;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
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
