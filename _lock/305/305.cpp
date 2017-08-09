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
	int toIdx(int row, int col, int n){
		return row*n + col;
	}
	int find(int id, vector<int>& roots){
		while(id != roots[id]){
			roots[id] = roots[roots[id]];
			id = root[id];
		}
		return id;
	}
	vector<int> lands(vector<pair<int,int>>& nums, int m, int n)
	{
		vector<int> ret;
		vector<int> roots(m*n, -1);
		int ans = 0;
		int direct[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
		for (int i = 0 ; i < nums ; i++){
			int cr = nums[i].first;
			int cc = nums[i].second;
			int cidx = toIdx(cr,cc,n)
				int theroot = -1;
			for (int j = 0 ; j < 4 ; j++){
				int nr = cr + direct[j][0];
				int nc = cc + direct[j][1];
				int nidx = toIdx(nr,nc,n);
				if (nr >= 0 && nr < m && nc >= 0 && nc < n){
					if (roots[nidx]!= -1){
						if (theroot == -1){
							roots[cidx] = nidx;
							theroot = find(cidx);
						} else {
							int other = find(nidx);
							if (other != theroot){
								roots[other] = theroot;
								ans--;
							}
						}
					}
				}
			}
			if (theroot == -1){
				roots[cidx] = cidx;
				ans++;
			}
			ret.push_back(ans);
		}
		return ret;
	}

};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string tre("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
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
