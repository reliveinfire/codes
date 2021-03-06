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

#if 0
class ZigIter
{
	public:
		ZigIter(vector<vector<int>>& mi){
			mm = mi;
			row = 0;
			col = 0;
			maxCol = INT_MIN;
			for (int i = 0 ; i < mi.size() ; i++){
				int sz = mi[i].size();
				maxCol = max(maxCol, sz);
			}
			mm[0][0] = 100;
			mm[0][1] = 200;
		}
	bool hasNext(){
		if (col == maxCol)
			return false;
		else
			return true;
	}
	int next(){
		int ret = mm[row][col];
		while(true){
			nextRow();
			if (col < mm[row].size())
				break;
			if (col == maxCol)
				break;
		}
		return ret;
	}
	void nextRow(){
		row = (row + 1) % mm.size();
		if (row == 0)
			col++;
	}
	private:
		vector<vector<int>> mm;
		int row, col;
		int maxCol;
};
#else
class ZigIter
{
	public:
		ZigIter(vector<vector<int>>& mi){
			for (int i = 0 ; i < mi.size() ; i++){
				auto iter = mi[i].begin();
				iters.push_back(iter);
				ends.push_back(mi[i].end());
			}
			endCount = mi.size();
			row = 0;
		}
	bool hasNext(){
		return endCount != 0;
	}
	int next(){
		int ret;
		ret = *iters[row];
		iters[row]++;
		if (iters[row] == ends[row])
			endCount--;
		if (endCount == 0)
			return ret;
		while(true){
			row = (row + 1) % ends.size();
			if (iters[row]!= ends[row])
				break;
		}
		return ret;
	}
	private:
		vector<vector<int>::iterator> iters;
		vector<vector<int>::iterator> ends;
		int endCount;
		int row;
};
#endif

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<vector<int>> A = {{1,2,3},
			 	 {4,5,6},
			  	 {8,9,10,11,12}
				};
	ZigIter zz(A);
	A[0][0] = 100;
	while(zz.hasNext()){
		cout << zz.next() << " ";
	}

	return 0;
}
