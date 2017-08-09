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

class Solution {
	public:
	vector<int> find_perm(vector<char>& num){
		vector<int> ans;
		priority_queue<int, vector<int>, greater<int>> pq;
		stack<int> st;
		for (int i = 1 ; i <= num.size()+1 ; i++)
			pq.push(i);
		int dcount = 0;
		for (int i = 0 ; i < num.size() ; i++){
			if (num[i] == 'D'){
				dcount++;
			} else {
				dcount++;
				for (int i = 0 ; i < dcount ; i++){
					st.push(pq.top());
					pq.pop();
				}
				while(!st.empty()){
					ans.push_back(st.top());
					st.pop();
				}
				dcount = 0;
			}
		}
		while(!pq.empty()){
			st.push(pq.top());
			pq.pop();
		}
		while(!st.empty()){
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	vector<char> seq;
	seq.push_back('I');
	seq.push_back('I');
	seq.push_back('D');
	seq.push_back('I');
	int ret;
	vector<int> ret_vec;
	ret_vec = sol.find_perm(seq);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
