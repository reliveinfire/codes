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
class Solution {
	public:
	int findMinDifference(vector<string>& timePoints){
		vector<bool> times(60*24, false);
		int result = 1550;
		if (timePoints.size() > 1440)
			return 0;
		for (int i = 0 ; i < timePoints.size() ; i++){
			string target = timePoints[i];
			string h = target.substr(0,2);
			string m = target.substr(3,2);
			int hh = atoi(h.c_str());
			int mm = atoi(m.c_str());
			int tt = 60*hh + mm;
			if (times[tt])
				return 0;
			else
				times[tt] = true;
		}
		int pre=-1, next = -1;
		int first;
		for (int i = 0 ; i < 1440 ; i++){
			if (times[i]){
				pre = next;
				next = i;
			}
//			cout << pre << ":" << next << endl;
			if (pre >= 0){
				result = min(result, next - pre);
			} else 
				first = next;
		}
		cout << result << " f:"<<first <<" next:" << next<< endl;
		result = min (result, first + 1440 - next);
		return result;
		
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	vector<string> ss;
	ss.push_back("01:01");
	ss.push_back("02:01");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	int ret;
	ret = sol.findMinDifference(ss);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
