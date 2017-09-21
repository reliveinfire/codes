#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        bool canMeasureWater(int x, int y, int z){
		int water = 0;
		int small = x < y ? x : y;
		int large = x > y ? x : y;
		if (z== x || z == y)
			return true;
		if (large==0)
			return false;
		while(true){
			water += small;
			if (water == z)
				return true;
			if ((z==water+large && water+large <= x+y) || (z==water+small && water+small<=x+y))
				return true;
			water = water % large;
			if (z==water)
				return true;
			if (water==0)
				break;
		}
		return false;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	Solution sol;
	ret = sol.canMeasureWater(104659, 104677, 142424);
	cout << ret << "\n";


	return 0;
}
