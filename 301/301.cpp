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

class Solution {
	public:
	vector<string> removeInvalidParentheses(string s){
		vector<string> ret;
		set<string> myset;
		queue<string> qu;

		qu.push(s);
		bool found = false;
		while(!qu.empty()){
			string curr = qu.front();
			qu.pop();
			if (myset.find(curr) == myset.end()){
				myset.insert(curr);

				if (validstr(curr)){
					ret.push_back(curr);
					found = true;
				}
				if (!found){
					for (int i = 0 ; i < curr.size() ; i++){
						if (curr[i] == '(' || curr[i] == ')'){
							string ns = curr.substr(0,i) +
								curr.substr(i+1, curr.size()-i-1);
							qu.push(ns);
						}
					}
				}
			}
		}
		return ret;
	}

	bool validstr(string s){
		int count = 0;
		for (int i = 0 ; i < s.size() ; i++){
			if (s[i] == '(')
				count++;
			else if (s[i] == ')'){
				if (count == 0)
					return false;
				count--;
			}
		}
		return count == 0;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("((()m)(");
	//string sb("(a)())()");
	string sc("))");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	int ret;
	vector<string> ret_vec;
	
	//ret_vec = sol.removeInvalidParentheses("())(((()m)(");
	ret_vec = sol.removeInvalidParentheses("");

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << endl;
	cout <<endl;
	

	return 0;
}
