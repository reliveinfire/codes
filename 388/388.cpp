#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int lengthLongestPath(string input){
		int ans = 0;
		vector<int> st(100);
		int isfile = 0;
		int idx = 0;
		int count = 0, tans = 0;
		for (int i = 0 ; i < input.size() ; i++){
			if (input[i]!='\n' && input[i]!='\t')
				count++;
			if (isfile && (input[i] == '\n' || input[i] == '\t' || i == input.size() - 1)){
				//cout  << "count:" << count<<endl;
				ans = max(ans,tans+count);
			}
			if (input[i] == '\n'){
				st[idx] = count+1;
				idx = 0;
				count = 0;
				isfile = 0;
				tans = 0;
			} else if (input[i] == '\t'){
				//cout << "idx:" <<idx<< ":"<< st[idx] << endl;
				tans += st[idx++];
				count = 0;
			} else if (input[i] == '.'){
				isfile = 1;
			}
		}
		return ans;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	int ret;
	//ret = sol.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
	ret = sol.lengthLongestPath("dir\n\t        file.txt\n\tfile2.txt");
	cout << ret << "\n";

	return 0;
}
