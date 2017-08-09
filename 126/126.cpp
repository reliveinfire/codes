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
#include <unordered_map>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	vector<vector<string>> ans;
	public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
		unordered_map<string, set<string>> adj;
		unordered_map<string, int> visited;
		unordered_map<string, vector<string>> pre;
		for (int i = 0 ; i < wordList.size() ; i++){
			visited[wordList[i]] = 0;
		}
		for (int i = 0 ; i < wordList.size() ; i++){
			if (diffone(beginWord, wordList[i]))
				adj[beginWord].insert(wordList[i]);
		}
		for (int i = 0 ; i < wordList.size() ; i++){
			for (int j = 0 ; j < wordList.size() ; j++)
				if (i!=j && diffone(wordList[i], wordList[j])){
					adj[wordList[i]].insert(wordList[j]);
				}
		}
		queue<string> qu;
		qu.push(beginWord);
		bool found = false;
		set<string> nowVisited;
		while(!qu.empty() && !found){
			int size = qu.size();
			for (int i = 0 ; i < size ; i++){
				string curr = qu.front();
				qu.pop();
				nowVisited.clear();
				for (set<string>::iterator iter = adj[curr].begin() ; iter!=adj[curr].end() ; iter++){
					vector<string> prevec;
					if (pre.find(*iter)!=pre.end()){
						prevec = pre[*iter];
					}
					if (*iter == endWord){
						found = true;
						prevec.push_back(curr);
					}
					if (!visited[*iter]){
						if (nowVisited[*iter].count==0){
							nowVisited.insert(*iter);
							qu.push(*iter);
						}
						prevec.push_back(curr);
					}
					pre[*iter] = prevec;
				}
			}
			for (set<string>::iterator iter = nowVisited.begin() ; iter!=nowVisited.end() ; iter++){
				visited[*iter]++;
			}
		}
		vector<string> tmp;
		helper(pre, endWord, tmp, beginWord);
		return ans;	
	}

	void helper(uordered_map<string, vector<string>>& pre, string curr, vector<string> tmp, string& bb){
		if (curr == bb){
			tmp.push_back(curr);
			reverse(tmp.begin(), tmp.end());
			ans.push_back(tmp);
			return;
		}
		for (int i = 0 ; i < pre[curr].size() ; i++){
			tmp.push_back(curr);
			helper(pre, pre[curr], tmp, bb);
		}
	
	}

	bool diffone(string a, string b){
		int diff = 0;
		for (int i = 0 ; i < a.size() ; i++){
			if (a[i]!=b[i])
				diff++;
			if (diff>1)
				return false;
		}
		return true;
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
