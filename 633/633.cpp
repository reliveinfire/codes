#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        bool judgeSquareSum(int c){
                unordered_set<int> tt;
                for (long i = 0 ; i*i <= (long)c ; i++){
			cout<< i << endl;
                        int tmp = i*i;
                        tt.insert(tmp);
                        if (tt.count(c-tmp)!=0)
                                return true;
                }
                return false;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string tre("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	int ret;
	ret = sol.judgeSquareSum(2147482647);

	cout << ret << endl;
	return 0;
}
