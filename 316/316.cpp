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
#include <list>
using namespace std;
#include "../helpers.cpp"
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};


class Solution {
	public:
		string removeDuplicateLetters(string s){
			stack<char> st;
			unordered_set<char> used;
			unordered_map<char,int> count;
			string ans;
			for (char c : s)
				count[c]++;
			for (int i = 0 ; i < s.size() ; i++){
				if (used.count(s[i])==0){
					while(!st.empty()){
						if (s[i] < st.top() && count[st.top()]!=0){
							used.erase(st.top());
							st.pop();
						}
						else
							break;
					}
					st.push(s[i]);
					used.insert(s[i]);
				}
				count[s[i]]--;
			}
			while(!st.empty()){
				ans += st.top();
				st.pop();
			}
			reverse(ans.begin(), ans.end());
			return ans;
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
//	cout << sol.removeDuplicateLetters("bcabc");
//	cout << sol.removeDuplicateLetters("acdcbc");
	cout << sol.removeDuplicateLetters("bbcaac");

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
