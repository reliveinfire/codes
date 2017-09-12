#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
	public:
		int findRadius(vector<int>& houses, vector<int>& heaters){
			int ans = INT_MIN;
			sort(heaters.begin(), heaters.end());
			for (int hh : houses){
				auto it = lower_bound(heaters.begin(), heaters.end(), hh);
				int diff = INT_MAX; 
				if (it!=heaters.end())
					diff = min(diff, abs(*it-hh));
				if (it!=heaters.begin())
					diff = min(diff, abs(*(--it) - hh));
				ans = max(ans, diff);
			}
			return ans;
		}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B =  {2};
	Solution sol;
	int ret;
	ret = sol.findRadius(A, B);
	cout << ret << "\n";


	return 0;
}
