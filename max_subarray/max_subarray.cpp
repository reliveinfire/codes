#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution
{
	public:
	int maxSubArray(vector<int>& A){
		int i;
		int local_max;
		int ret_max;
		local_max = A[0];
		ret_max = A[0];
		for (i = 1 ; i < A.size() ; i++) {
			local_max = max(local_max + A[i], A[i]);
			ret_max = max(ret_max, local_max);
		}
		return ret_max;
	}
};

int main()
{
	int ret, i;
	vector<int> vec;
	Solution sol;
	int test[]= {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int size = sizeof(test)/sizeof(test[0]);
	for (i = 0 ; i < size ; i++)
		vec.push_back(test[i]);
	
	ret = sol.maxSubArray(vec);
	cout << ret << "\n";
	return 0;

}
