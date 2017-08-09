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
	int magicalString(int n){
		vector<int> ms;
		if ( n <= 3)
			return 1;
		ms.push_back(1);
		ms.push_back(2);
		ms.push_back(2);

		int result = 1;
		int head =2;
		int push = 1;

		while(ms.size() < n){
			for (int i = 0 ; i < ms[head] ; i++){
				ms.push_back(push);
				if (push==1)
					result++;
				if (ms.size() >= n)
					break;
			}
			head++;
			if (push == 1)
				push = 2;
			else
				push = 1;
		}

		for (int i = 0 ; i < n ; i++){
			cout << ms[i];
		}
		cout << endl;
		return result;
		
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	int A[] = {1,2,3};
	genVector(da, A);
	Solution sol;
	cout << sol.magicalString(12);

	return 0;
}
