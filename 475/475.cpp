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
	private:
		int bs(vector<int>& nums, int l, int r, int target){

			while ( l <= r) {
			int m = (l + r) / 2;
				if (nums[m]== target)
					return m;
				if ( target > nums[m])
					l = m + 1;
				else
					r = m - 1;
				
			}
			return l;
		}
	public:
		int findRadius(vector<int>& houses, vector<int>& heaters){
			sort(heaters.begin(), heaters.end());

			int ret = 0;
			int mindiff;
			for (int i = 0 ; i < houses.size() ; i++){
				if (heaters.size() == 1) {
					mindiff = houses[i] >  heaters[0] ?
						houses[i]-heaters[0]: heaters[0]-houses[i];
				} else {
					int handle = houses[i];
					int pos = bs(heaters, 0, heaters.size()-1, handle);
					if (pos == 0)
						mindiff = heaters[pos] - handle;
					else if (pos == heaters.size()){
						mindiff = handle - heaters[pos-1];
					} else
						mindiff = min( heaters[pos] - handle,	handle - heaters[pos-1]);
				}
				ret = max(ret, mindiff);
			}
			return ret;
		}

};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
#define case3
#ifdef case1
	int A[] = {1,2,3};
	genVector(da, A);
	int B[] = {2};
	genVector(db, B);
#endif

#ifdef case2
	int A[] = {1,2,3,4};
	int B[] = {1,4};
	genVector(da, A);
	genVector(db, B);
#endif

#ifdef case3
	int A[] = {1,2,3,4,5,6,7,8,9,50};
	int B[] = {2,9};
	genVector(da, A);
	genVector(db, B);
#endif
	Solution sol;
	ret = sol.findRadius(da,db);
	cout << "answer:" << ret << "\n";

	return 0;
}
