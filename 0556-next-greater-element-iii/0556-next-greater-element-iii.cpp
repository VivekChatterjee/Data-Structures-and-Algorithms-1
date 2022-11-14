#define ll long long int
class Solution {
public:
    int K=1e9+7;
    int nextGreaterElement(int n) {
        int num = n;
        int digits = floor(log10(n) + 1);
        vector<int>number(digits);
        int i=digits-1;
        while(num > 0)
        {
            int r=num%10;
            number[i--]=r;
            num/=10;
        }
        int smallerInd = -1;
        for(int i=digits-2; i>=0; i--)
        {
            if(number[i] < number[i+1])
            {
                smallerInd = i;
                break;
            }
        }
        if(smallerInd == -1) return -1;
        else
        {
            for(int i=digits-1; i>smallerInd; i--)
            {
                if(number[i] > number[smallerInd])
                {
                    swap(number[i], number[smallerInd]);
                    break;
                }
            }
            reverse(number.begin()+smallerInd+1, number.end());
            int k=digits-1;
            ll ans = 0;
            for(int i=0; i<number.size(); i++)
            {
                ans+=number[i] * (pow(10,abs(k--) ));
                if(ans > INT_MAX) return -1;
            }
            return ans;
        }
    }
};