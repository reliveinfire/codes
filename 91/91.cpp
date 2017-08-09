#include "../helpers.cpp"
#ifdef I2C
static void i2c_flush_rxfifo(struct i2c_adapter *adap)
{
        struct i2c_regs *i2c_base = i2c_get_base(adap);
        while (readl(&i2c_base->ic_status) & IC_STATUS_RFNE) {
                readl(&i2c_base->ic_cmd_data);
                //debug("flush rxfifo: read data %02x\n", data);
        }
}
static int i2c_wait_for_bb(struct i2c_adapter *adap)
{
        struct i2c_regs *i2c_base = i2c_get_base(adap);
        int count = 0;

        //debug("wait for BB: ic status %08x\n", readl(&i2c_base->ic_status));
        while ((readl(&i2c_base->ic_status) & IC_STATUS_MA) ||
               !(readl(&i2c_base->ic_status) & IC_STATUS_TFE)) {
                /* Evaluate timeout */
                udelay(1000);
                count++;
                if (count > TIMEOUT_LOOP)
                        return 3;
        }

        return 0;
}
static int i2c_xfer_init(struct i2c_adapter *adap, uchar chip, uint addr,
                         int alen)
{
        struct i2c_regs *i2c_base = i2c_get_base(adap);

        int ret = i2c_wait_for_bb(adap);
        if (ret){
                return ret;
        }

        i2c_setaddress(adap, chip);
        while (alen) {
                alen--;
                /* high byte address going out first */
                writel((addr >> (alen * 8)) & 0xff,
                       &i2c_base->ic_cmd_data);
        }
static int i2c_xfer_finish(struct i2c_adapter *adap)
{
        struct i2c_regs *i2c_base = i2c_get_base(adap);

        int count = 0;
        while (1) {
                if ((readl(&i2c_base->ic_raw_intr_stat) & IC_STOP_DET)) {
                        readl(&i2c_base->ic_clr_stop_det);
                        break;
                } else if (count > TIMEOUT_LOOP){
                        break;
                } else {
                        udelay(1000);
                        count++;
                }
        }

        if (i2c_wait_for_bb(adap)) {
                return 5;
        }

        i2c_flush_rxfifo(adap);

        return 0;
}

static int dw_i2c_read(struct i2c_adapter *adap, u8 dev, uint addr,
                       int alen, u8 *buffer, int len)
{
        struct i2c_regs *i2c_base = i2c_get_base(adap);
        int count = 0;
        int ret = i2c_xfer_init(adap, dev, addr, alen);
        if (ret){
                return ret;
        }

        if (len == 1)
                writel(IC_CMD | IC_STOP, &i2c_base->ic_cmd_data);
        else if (len > 0)
                writel(IC_CMD, &i2c_base->ic_cmd_data);

        while (len) {
                if ((readl(&i2c_base->ic_status) & IC_STATUS_RFNE) != 0) {
                        *buffer++ = (uchar)readl(&i2c_base->ic_cmd_data);
                        len--;
                        if (len == 1)
                                writel(IC_CMD | IC_STOP, &i2c_base->ic_cmd_data);
                        else if (len > 0)
                                writel(IC_CMD, &i2c_base->ic_cmd_data);
                } else if (count > TIMEOUT_LOOP){
                        return 7;
                } else {
                        count++;
                        // 4bytes + address, start/stop bit, take it as 8 bytes
                        // 8 bytes = 256 bits
                        udelay(5000);
                }
        }

        return i2c_xfer_finish(adap);
}
int giu_i2c_read(unsigned int reg)
{
        unsigned int val;
        dw_i2c_read(NULL, GIU_SLAVE_ADDR, reg, 1, (u8*)&val, 4);
        val = (val &0x00FFFF00) | (val &0xFF) << 24 | (val &0xFF000000) >> 24;
        val = (val &0xFF0000FF) | (val &0xFF00) << 8 | (val&0xFF0000) >> 8;
        return val;
}

int giu_i2c_write(unsigned int reg, unsigned int val){
        int ret = 0;
        val = (val &0x00FFFF00) | (val &0xFF) << 24 | (val &0xFF000000) >> 24;
        val = (val &0xFF0000FF) | (val &0xFF00) << 8 | (val&0xFF0000) >> 8;
        ret = dw_i2c_write(NULL, GIU_SLAVE_ADDR, reg, 1, (uint8_t*)&val, 4);
        return ret;
}

#else

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
	int mod = 1000000007;
        int numDecodings(string s){
		if (s.empty())
			return 0;
		vector<long> dp(s.size()+1, 0);
		dp[0] = 1;
		for (int i = 0 ; i < s.size() ; i++){
			if (s[i]!='0'){
				if (s[i]=='*'){
					dp[i+1] = (dp[i+1] + dp[i]*9) % mod;
				} else
					dp[i+1] = (dp[i+1] + dp[i])%mod;
			}
			if (i-1 >= 0){
				if (s[i-1] == '1'){
					if (s[i] == '*')
						dp[i+1] = (dp[i+1] + dp[i-1] * 9)%mod;
					else
						dp[i+1] = (dp[i+1] + dp[i-1]) % mod;
				} else if (s[i-1]=='2'){
					if(s[i]>='0' && s[i]<='6')
						dp[i+1] = (dp[i+1] + dp[i-1]) % mod;
					else if (s[i] == '*')
						dp[i+1] = (dp[i+1] + dp[i-1]*6) % mod;
				} else if(s[i-1] == '*'){
					if (s[i]>='0' && s[i] <='6')
						dp[i+1] = (dp[i+1] + dp[i-1]*2) % mod;
					else if (s[i] == '*')
						dp[i+1] = (dp[i+1] + dp[i-1]*15) % mod;
					else
						dp[i+1] = (dp[i+1] + dp[i-1]) % mod;
				}
			}
		}
		return dp[s.size()];

        }
};
#if 0
	int helper(string s, int cur, unordered_map<int,int>& cnt){
		if (cur == s.size())
			return 1;
		if (s[cur]=='0')
			cnt[cur] = 0;
		else {
			if (cnt.count(cur)!=0)
				return cnt[cur];
			long one=0, two=0;
			one = helper(s, cur+1, cnt);
			if (s[cur]=='*')
				one = (one * 9 ) % mod;
			if (cur<s.size()-1){
				if (s[cur]=='1'){
					two = helper(s, cur+2, cnt);
					if (s[cur+1]=='*')
						two = (two*9)%mod;
				} else if (s[cur]=='2'){
					if (s[cur+1]>='0' && s[cur+1]<='6' )
						two = helper(s, cur+2, cnt);
					if (s[cur+1]=='*'){
						two = helper(s, cur+2, cnt);
						two = (two*6)%mod;
					}
				} else if (s[cur]=='*'){
					two = helper(s, cur+2, cnt);
					if (s[cur+1]>='0' && s[cur+1]<='6')
						two = (two * 2 )%mod;
					else if(s[cur+1]=='*')
						two = (two * 15)%mod;
				} 
			}
//			cout << cur <<":" << one <<":"<<two << endl;
			cnt[cur] = (one + two) % mod;
		}

		return cnt[cur];
	}
#endif
#endif
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
//	ret = sol.numDecodings("**********1111111111");
//	ret = sol.numDecodings("1*");
	ret = sol.numDecodings("*1*1*0");
	cout << ret << "\n";

	cout <<endl;

	return 0;
}
