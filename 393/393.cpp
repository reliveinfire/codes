#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        bool validUtf8(vector<int>& data){
		int cnt = 0;
		for (int i = 0 ; i < data.size() ; i++){
			int d = data[i];
			if (cnt==0){
				if (d>>5 == 0b110)
					cnt = 1;
				else if (d >> 4 == 0b1110)
					cnt = 2;
				else if (d >> 3 == 0b11110)
					cnt = 3;
				else if (d >> 7 == 0b0)
					cnt = 0;
				else
					return false;
			} else {
				if (d>>6 == 0b10)
					cnt--;
				else
					return false;
			}
		}
		if (cnt!=0)
			return false;
		return true;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {197, 130, 1};
	Solution sol;
	int ret;
	ret = sol.validUtf8(A);
	cout << ret << "\n";


	return 0;
}
