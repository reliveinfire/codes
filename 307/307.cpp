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

class NumArray {
public:
    NumArray(vector<int> nums) {
    	BIT.clear();
	orig.clear();
	BIT.push_back(0);
	for (int i = 0 ; i < nums.size() ; i++){
		orig.push_back(nums[i]);
		BIT.push_back(0);
	}
	for (int i = 0 ; i <nums.size() ; i++){
		bitupdate(i, orig[i], BIT.size());
	}
    }

    void update(int i, int val) {
    		int diff = val - orig[i];	
		orig[i] = val;
		bitupdate(i, diff, orig.size());
    }

    int sumRange(int i, int j) {
	    if (i == 0)
		    return bitsum(j);
	    else
		    return bitsum(j) - bitsum(i-1);
    }
private:
	vector<int> BIT;
	vector<int> orig;
	int bitsum(int idx){
		int sum = 0;
		idx++;
		while (idx > 0){
			sum += BIT[idx];
			idx -= idx&(-idx);
		}
		return sum;	
	}
	void bitupdate(int idx, int val, int max){
		idx++;
		while(idx <= max){
			BIT[idx] += val;
			idx += idx & (-idx);
		}
		return;
	}
};


#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {0,9,5,7,3};
//	int A[] = {1,3,5,7,9};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	vector<int> ret_vec;
	int ret;
	NumArray *na = new NumArray(da);
	cout << na->sumRange(4,4) << endl;
	cout << na->sumRange(2,4) << endl;
	cout << na->sumRange(3,3) << endl;
	na->update(4,5);
	na->update(1,7);
	na->update(0,8);
	cout << na->sumRange(1,2) << endl;
	na->update(1,9);
	cout << na->sumRange(4,4) << endl;
	na->update(3,4);
	free(na);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
