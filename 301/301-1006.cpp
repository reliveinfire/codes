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
#include <unordered_set>

using namespace std;

class Solution {
	public:
	vector<string> removeInvalidParentheses(string s){
		vector<string> res;
		vector<string> rleft;
		unordered_set<string> used;
		remove(s, '(', ')', rleft, used);
		for (int i = 0 ; i < rleft.size() ; i++){
#if 1
			reverse(rleft[i].begin(), rleft[i].end());
			used.clear();
			remove(rleft[i], ')', '(', res, used);
#endif
		}
		if (res.empty())
			return {""};
		for (auto& ss : res )
			reverse(ss.begin(), ss.end());
		return res;
	}
	void remove(string s, char ll, char rr, vector<string>& res, unordered_set<string>& used){
		int idx = 0;
		int cnt = 0;
		if (used.count(s)==0)
			used.insert(s);
		else
			return;
		for (;idx < s.size() ; idx++){
			if (s[idx]==ll)
				cnt++;
			else if (s[idx]==rr)
				cnt--;
			if (cnt < 0){
				for (int j = 0 ; j <= idx ; j++){
					if (s[j]==rr){
						string t = s.substr(0, j) + s.substr(j+1);
						remove(t,ll,rr, res, used);
					}
				}
				return;
			}
		}
		if (idx==s.size())
			res.push_back(s);
		return;
	}

};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("((()m)(");
	string sb("(a)())()");
	string sd("()())()");
	string sc("(r(()()(");
	Solution sol;
	vector<string> ret_vec;
	
	ret_vec = sol.removeInvalidParentheses("n");
	//ret_vec = sol.removeInvalidParentheses("");
	cout << "ans\n";
	for (auto s : ret_vec)
		cout << s << endl;

	

	return 0;
}
