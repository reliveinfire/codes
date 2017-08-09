#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	public:
		vector<vector<string> > result;
		vector<string> tmp;
		vector<vector<string> > partition(string s) {
			vector<vector<bool> > pal(s.size(), vector<bool>(s.size(), false));
			int i;
			for (int j = 0 ; j < s.size() ; j++){
				for (i = j ; i >= 0 ; i--){
					if (i==j){
						pal[i][j] = 1;
					}else if (s[i] == s[j]){
						if (i+1==j)
							pal[i][j] = 1;
						else
							pal[i][j] = pal[i+1][j-1];
					} 
				}
			}
			helper(s, 0, s.size()-1, pal);
			return result;
		}
		void helper(string s, int ll, int rr, vector<vector<bool> >& pal){
			if ( ll > rr){
				result.push_back(tmp);
				return;
			}
		
			for (int i = ll ; i <= rr ; i++) {
				if (pal[ll][i]){
					tmp.push_back(s.substr(ll, i-ll+1));
					helper(s, i+1, rr, pal);
					tmp.pop_back();
				}
			}
			return;
		}

};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	Solution sol;
	vector<vector<string> > ret;
	ret = sol.partition("aabb");
	
	for (int i = 0 ; i < ret.size() ; i++){
		vector<string> rr = ret[i];
		for (int j = 0 ; j < rr.size() ; j++)
			cout << rr[j] << " ";
		cout << endl;
	}

	return 0;
}
