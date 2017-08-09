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
	unordered_set<int> used;
	int ans;
	vector<vector<string>> solveNQueens(int n){
		vector<int> pos(n);
		vector<vector<string>> ret;
		ans = 0;
		helper(0, pos);
		return ans;
	}
	void helper(int curr, vector<int>& pos){
		if (curr == pos.size() ){
			ans++;
			return;
		}
		for (int i = 0 ; i < pos.size() ; i++){
			bool hit = false;
			if (used.count(i)==0){
				for (int j = 1 ; j <= curr ; j++){
					if (i-j >= 0){
						if (pos[curr-j]==i-j ){
							hit = true;
							break;
						}
					}
					if (i+j<pos.size()){
						if (pos[curr-j]==i+j ){
							hit = true;
							break;
						}
					}
				}
				if (hit)
					continue;
				pos[curr] = i;
				used.insert(i);
				helper(curr+1,pos);
				used.erase(i);
			}
		}
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
	sol.solveNQueens(4);


	return 0;
}
