#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
class Solution {
	public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration){
		int i,j;
		int result = 0;
		for (i = 0, j = 1 ; j < timeSeries.size() ; i++,j++){
			if (timeSeries[j] - timeSeries[i] > duration)
				result += duration;
			else
				result += timeSeries[j] - timeSeries[i];
		}
		result += duration;
		return result;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	int A[] = {1,4};
	int B[] = {1,2};
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	ret = sol.findPoisonedDuration(da,2);
	cout << ret << "\n";
	ret = sol.findPoisonedDuration(db,2);
	cout << ret << "\n";

	return 0;
}
