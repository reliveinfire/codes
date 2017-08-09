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
	vector<string> readBinaryWatch(int num){
		vector<string> ans;
		vector<int> hr;
		vector<int> mins;
		if (num > 10)
			return ans;
		for (int i = 0 ; i <= 4 ; i++){
			if (i > num)
				break;
			else {
				hr.clear();
				mins.clear();
				int minsCount = num - i;
				if (minsCount > 6)
					continue;
				genHr(i, 1, 0, hr);
				genMins(minsCount, 1, 0, mins);
				for (int j = 0 ; j < hr.size() ; j++){
					for (int k = 0 ; k < mins.size() ; k++){
						string tmp;
						if (hr[j]>11)
							continue;
						tmp+= to_string(hr[j]);
						tmp+= string(":");
						if (mins[k]>59)
							continue;
						if (mins[k]<10){
							tmp+= string("0");
						}
						tmp += to_string(mins[k]);
						ans.push_back(tmp);
					}
				}
			}
		}
		return ans;
	}
	void genHr(int count, int start, int curr, vector<int>& hr)
	{
			if (count == 0 ){
				hr.push_back(curr);
				return;
			}
			for (int i = start ; i+count-1 <= 4 ;i++){
				genHr(count - 1, i+1, curr + (1 << (i-1)) , hr);
			}
			return;
	}
	void genMins(int count, int start, int curr, vector<int>& mins)
	{
			if (count == 0 ){
				mins.push_back(curr);
				return;
			}
			for (int i = start ; i+count-1 <= 6 ;i++){
				genMins(count - 1, i+1, curr + (1 << (i-1)) , mins);
			}
			return;
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
	vector<string> ret_vec;
	ret_vec = sol.readBinaryWatch(2);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << endl;
	cout <<endl;

	return 0;
}
