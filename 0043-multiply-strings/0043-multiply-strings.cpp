class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        if(num1.size() < num2.size()) swap(num1, num2);
        vector<string>v;
        int k=0;
        for(int i=num2.size()-1;i>=0;i--)
        {
            int end = num1.size()-1;
            string row="";
            int first=num2[i]-'0';
            int carry=0;
            int j=k;
            while(j--)
            {
                row+='0';
            }
            k++;
            while(end>=0)
            {
                int second = num1[end]-'0';
                int cur = (first * second) + carry;
                if(cur > 9)
                {
                    row+=to_string(cur % 10);
                    carry=(cur/10);
                }
                else
                {
                    row+=to_string(cur);
                    carry=0;
                }
                end--;
            }
            if(carry>0) row+=to_string(carry);
            reverse(row.begin(), row.end());
            v.push_back(row);
        }
        string ans="";
        int carry=0;
        while(v.back().size()>0)
        {
            int j=v.size()-1;
            int num=0;
            while(j>=0)
            {
                if(v[j].size()>0)
                {
                    int s=v[j].size();
                    num+=v[j][s-1]-'0';
                    v[j].pop_back();
                }
                j--;
            }
            num+=carry;
            ans+=to_string(num%10);
            carry = num/10;
        }
        if(carry>0)ans+=to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};