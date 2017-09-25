#include "../../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int androidlock(int m, int n){
		int res = 0;
		int tmp = 0;
		vector<int> visit(10);
		helper(m,n, 1, 1, visit, tmp);
		res+= tmp*4;
		tmp = 0;
		helper(m,n,2, 1, visit, tmp);
		res+= tmp*4;
		tmp = 0;
		helper(m,n,5, 1, visit, tmp);
		res +=tmp;
		return res;
        }
	void helper(int m,int n, int pos, int cnt, vector<int>& visit, int& res){
		if (cnt>n)
			return;
		if ( m<=cnt && cnt<=n)
			res++;
		visit[pos] = 1;
		for (int i = 1 ; i <= 9 ; i++){
			if (!visit[i] && cango(pos, i, visit))
				helper(m,n, i, cnt+1, visit, res);
		}
		visit[pos] = 0;
		return;
	}
	bool cango(int from, int to, vector<int>& visit){
		vector<vector<int>> map(10, vector<int>(10));
		map[1][3] = map[3][1] = 2;
		map[4][6] = map[6][4] = 5;
		map[7][9] = map[9][7] = 8;
		map[1][7] = map[7][1] = 4;
		map[2][8] = map[8][2] = 5;
		map[3][9] = map[9][3] = 6;
		map[1][9] = map[9][1] = map[3][7] = map[7][3] = 5;
		if (map[from][to]){
			return visit[map[from][to]];
		}
		return true;
	}
};
class Verify {
public:
    int numberOfPatterns(int m, int n) {
        return count(m, n, 0, 1, 1, 1, 1);
    }
private:
    int count(int m, int n, int used, int i1, int j1, int i2, int j2) {
        int number = m <= 0;
        if (!n) return 1;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                int I = i2 + i, J = j2 + j, used2 = used | (1 << (i*3 + j));
                if (used2 > used && (I % 2 || J % 2 || used2 & (1 << (I/2*3 + J/2))))
                    number += count(m-1, n-1, used2, i2, j2, i, j);
            }
        }
        return number;
    }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	Verify verify;
	int ret;
	cout << sol.androidlock(2,7) << endl;
	cout << verify.numberOfPatterns(2,7) << endl;

	return 0;
}
