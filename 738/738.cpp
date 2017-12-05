#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int monotoneIncreasingDigits(int N){
		int res = 0;
		if (N<10)
			return N;
		string nn = to_string(N);
		int i = 1;
		for (;i < nn.size() ; i++){
			if (nn[i]<nn[i-1])
				break;
		}
		if (i==nn.size())
			return N;
		while(i>0){
			if (nn[i]-1>=nn[i-1])
				break;
			else
				i--;
		}
		for (int j = 0 ; j < nn.size() ; j++){
			res = res * 10;
			if (j < i){
				res += nn[j] - '0';
			} else if (j==i){
				res += nn[j] - '0' - 1;
			} else
				res += 9;
		}
		return res;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	int ret;
	ret = sol.monotoneIncreasingDigits(1234);
	cout << ret << "\n";


	return 0;
}
