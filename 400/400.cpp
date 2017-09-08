#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int findNthDigit(int n){
		long i = 1;
		long ten = 1;
		if (n<10)
			return n;
		while (true){
			long count = i * 9 * ten;
			long tmp = n - count;
			if (tmp <= 0)
				break;
			n = tmp;
			i++;
			ten = ten * 10;
		}
		n--;
		int dif = n / i;
		int mod = n % i;
		int num = ten + dif;
		//cout << num << endl;
		string str = to_string(num);
		int ans = str[mod] - '0';
		return ans;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	int ret;
	ret = sol.findNthDigit(2147483647);
	cout << ret << "\n";


	return 0;
}
