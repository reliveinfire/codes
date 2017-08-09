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

class Solution {
	public:
	string alienOrder(vector<string>& words){
		unordered_map<char,int> inedge;
		unordered_map<char, unordered_set<char>> edges;
		string ans;
		for (int i = 0 ; i < words.size() ; i++){
			for (int j = i+1 ; j < words.size() ; j++){
				string aa = words[i];
				string bb = words[j];
				for (int k = 0 ; (k < aa.size()) && (k <bb.size()); k++){
					if (aa[k] != bb[k]){
						edges[aa[k]].insert(bb[k]);
						inedge[aa[k]] = 0;
						break;
					}
				}
			}
		}
		for (auto it = edges.begin(); it != edges.end() ; it++){
			for (auto ii = it->second.begin() ; ii!= it->second.end() ; ii++){
				//cout << it->first << "=" << *ii << endl;
				inedge[*ii]++;
			}
		}
#if 0		
			for (auto it = inedge.begin() ; it!=inedge.end() ; it++){
				cout << it->first << "=" << it->second << endl;
			}
#endif

		while(inedge.size() > 0){
			vector<char> tmp;
			bool found = false;
			for (auto it = inedge.begin() ; it!=inedge.end() ; it++){
				if (it->second == 0){
					tmp.push_back(it->first);
					ans += it->first;
					found = true;
				}
			}
			if (!found)
				return string("");
			for (int i = 0 ; i < tmp.size() ; i++){
				inedge.erase(tmp[i]);
				unordered_set<char> set = edges[tmp[i]];
				for (auto it = set.begin() ; it!=set.end() ; it++){
					inedge[*it]--;
				}
			}
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
	vector<string> ret_vec;
	vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
	string ret;
	ret = sol.alienOrder(words);
	cout << ret << endl;

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
