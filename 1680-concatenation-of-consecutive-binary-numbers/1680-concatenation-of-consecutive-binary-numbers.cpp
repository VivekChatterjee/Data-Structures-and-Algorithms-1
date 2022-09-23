#define ll unsigned long long int
const int K = 1e9+7;


class Solution {
public:
    
    string decimalToBinary(int n) { 
        string ans="";
         string str="";
        for(int i=n;i>=1;--i){
            int no=i;
            while(no){
                str+=(no%2)+'0';
                no/=2;
            }
        }
        return str;
//                 for(int i=1;i<=n;i++)
//         {
               
//         string with = bitset<32>(i).to_string();
//             int bits = log2(i)+1;
//             string without = with.substr(32-bits,bits);
//             ans+=without;
//                 }
//     return ans;
        
    } 
    
    int concatenatedBinary(int n) {
        string ans="";
        
        ans = decimalToBinary(n);
        
     
        ll res=0,powe=1;
        for(int j=0;j<ans.size();++j){
                ll now=(ans[j]-'0')*(powe);
                powe*=2;
                powe%=1000000007;
                res%=1000000007;
                res+=now;
        }
        // cout<<ans<<endl;
        
        return res % 1000000007;
    }
};