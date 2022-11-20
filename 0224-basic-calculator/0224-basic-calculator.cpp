class Solution {
public:
int calculate(string s) {

    stack<int> sta;
    int sign=1;
    int currNum=0;
   
    
    int ans=0;
    
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            currNum=s[i]-'0';
            // cout<<currNum<<"\n";
            while(i+1<s.size() and isdigit(s[i+1])){
                currNum=currNum*10+(s[i+1]-'0');
                // cout<<currNum<<"\n";
                i+=1;
            }
            
            currNum=sign*currNum;
            ans+=currNum;
            currNum=0;
            sign=1;
            
        }else if(s[i]=='+'){
            sign=1;
        }else if(s[i]=='-'){
            sign=-1;
        }else if(s[i]=='('){
            sta.push(ans);
            sta.push(sign);
            ans=0;
            currNum=0;
            sign=1;
        }else if(s[i]==')'){
            int prevSign=sta.top();
            sta.pop();
            int prevAns=sta.top();
            sta.pop();
            
            ans=prevAns+prevSign*ans;
            
        }
    }
    
    return ans;
    
}
};