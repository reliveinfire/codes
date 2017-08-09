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
	bool wordPatternMatch(string pattern, string str){
		unordered_map<char, string> map;
		unordered_set<string> used;
		return helper(pattern, str, map, used);
	}

	bool helper(string pattern, string str, unordered_map<char, string>& map,
		unordered_set<string>& used){
		if (str.size() < pattern.size() || (pattern.size() == 0 && str.size()!=0) ||
			(pattern.size()!= 0 && str.size() == 0))
			return false;
		if (pattern.size() == 0 && str.size() == 0)
			return true;
		auto iter = map.find(pattern[0]);
		if (iter!=map.end()){
			string tmp = iter->second;
			string ss = str.substr(0, tmp.size());
			if (ss == tmp){
				string tp = pattern.substr(1, pattern.size() -1);
				string ts = str.substr(ss.size(), str.size() - ss.size());
				return helper(tp, ts, map, used);
			} else
				return false;
		} else {
			for (int i = 1 ; i + pattern.size() - 1 <= str.size()  ; i++){
				string ss = str.substr(0, i);
				if (used.count(ss)!=0)
					continue;
				map[pattern[0]] = ss;
				used.insert(ss);
				string tp = pattern.substr(1, pattern.size() -1);
				string ts = str.substr(i, str.size() - i);
				int ret = helper(tp, ts, map, used);
				map.erase(pattern[0]);
				used.erase(ss);
					if (ret)
						return true;
			}
		}
		return false;
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
	cout << sol.wordPatternMatch("abab","redblueredblue") << endl;
	cout << sol.wordPatternMatch("aaaa","asdasdasdasd") << endl;
	cout << sol.wordPatternMatch("aabb","xybabcxzyabc") << endl;
	cout << sol.wordPatternMatch("abcd","aabb") << endl;
	cout << sol.wordPatternMatch("aba","asdasdddecdasd") << endl;

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
