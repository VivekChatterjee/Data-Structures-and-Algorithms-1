class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int carry=0;
        int s=num1.size()-1;
        int e=num2.size()-1;
        while(s>=0 && e>=0)
        {
            int n1 = num1[s]-'0';
            int n2 = num2[e]-'0';
            int res=0;
            if(n1+n2+carry > 9)
            {
                res = (n1+n2+carry) % 10;
                carry=0;
                carry+=1;
            }
            else
            {
                res = n1+n2+carry;
                carry=0;
            }
            ans+=to_string(res);
            s--;
            e--;
        }
        while(s>=0)
        {
            int n1 = num1[s]-'0';
            int res=0;
            if(n1+carry > 9)
            {
                res = (n1+carry)%10;
                carry=0;
                carry+=1;
            }
            else
            {
                res = n1+carry;
                carry=0;
            }
            ans+=to_string(res);
            s--;
        }

        while(e>=0)
        {
            int n2 = num2[e]-'0';
            int res=0;
            if(n2+carry > 9)
            {
                res = (n2+carry) %10;
                carry=0;
                carry+=1;
            }
            else
            {
                res = n2+carry;
                carry=0;
            }
            ans+=to_string(res);
            e--;
        }
        if(carry>0)
        {
            ans+=to_string(carry);
            carry=0;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};