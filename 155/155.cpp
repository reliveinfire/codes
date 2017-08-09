#include <iostream>
#include <string>
#include <unordered_map>
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

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
	data.clear();
	mindata.clear();
    }
    void push(int x) {
	data.push_back(x);
	if (mindata.empty())
		mindata.push_back(x);
	else {
		if (x < mindata.top())
			mindata.push(x);
		else
			mindata.push(mindata.top());
	}
    }

    void pop() {
	data.pop_back();
	mindata.pop_back();
    }

    int top() {
	return data.top();
    }

    int getMin() {
	if (!mindata.empty())
		return mindata.top();
    }
private:
	vector<int> data;
	vector<int> mindata;
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
