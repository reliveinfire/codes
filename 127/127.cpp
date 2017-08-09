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
	public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList){
		unordered_map<string, set<string>> adj;
		unordered_map<string, int> visited;
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
		int ans = 0;
		while(!qu.empty()){
			int size = qu.size();
			ans++;
			for (int i = 0 ; i < size ; i++){
				string curr = qu.front();
				qu.pop();
				for (set<string>::iterator iter = adj[curr].begin() ; iter!=adj[curr].end() ; iter++){
					if (*iter == endWord)
						return ans;
					if (!visited[*iter]){
						visited[*iter]++;
						qu.push(*iter);
					}
				}
			}
		}
		return 0;	
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
