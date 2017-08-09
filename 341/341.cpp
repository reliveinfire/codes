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

class NestedIterator {
public:
    stack< pair< vector<NestedInteger>, int>> st;
    NestedIterator(vector<NestedInteger> &nestedList) {
    		if (!nestedList.empty())
		       st.push(pair<vector<NestedInteger>,int>(nestedList,0));
    }

    int next() {
	    int ans;
	    pair<vector<NestedInteger>,int> tmp;
	    tmp = st.top();
	    st.pop();
	    vector<NestedInteger> ni = tmp.first;
	    int idx = tmp.second;
	    ans = ni[idx].getInteger();
	    idx++;
	    if (idx!=ni.size()){
		    tmp.second = idx;
		    st.push(tmp);
		    return ans;
	    }
    }
    bool hasNext() {
    	if (st.empty())
		return false;
	else {
		while(true){
			pair<vector<NestedInteger>,int> tmp;
			tmp = st.top();
			st.pop();
			vector<NestedInteger> ni = tmp.first;
			int idx = tmp.second;
			if (ni[idx].isInteger()){
				st.push(tmp);
				return true;
			} else {
				vector<NestedInteger> vv = ni[idx].getList();
				idx++;
				if (idx!=ni.size()){
					tmp.second = idx;
					st.push(tmp);
				}
				if (!vv.empty()){
					tmp.first = vv;
					tmp.second = 0;
					st.push(tmp);
				}
				if (st.empty())
					break;
			}

		}
		return false;
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
