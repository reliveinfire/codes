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

int std_bs(vector<int>& num, int target){
	int lo = 0, hi = num.size();
	while(lo < hi){
		int mid = lo + (hi-lo)/2;
		if (num[mid] >= target)
			hi = mid;	
		else
			lo = mid + 1;
	}
	return lo;
}

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,4,6,7,7,7,7,7,7,7,7,10};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	vector<int> ret_vec;
	int ret = std_bs(da, 11);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
