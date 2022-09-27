class Solution {
public:
    void lt(string &ans,int left)
    {
        if(left<0 || ans[left]!='.')
            return;
        ans[left]='L';
        lt(ans,left-1);
    }
    
    void rt(string &ans,int right)
    {
        if(right>=ans.size() || ans[right]!='.')
            return;
        ans[right]='R';
        rt(ans,right+1);
    }
    
    void fall(string &ans,int right, int left)
    {
        if(right == left || right>left || ans[right]!='.' || ans[left]!='.')
            return;
        ans[right]='R';
        ans[left]='L';
        fall(ans,right+1,left-1);
    }
    
    string pushDominoes(string domi) {
        string ans=domi;
        int right=0,left=0;
        while(right<=left && left<ans.size())
        {    
            if(right==left && domi[right]!='R')
            {         
                right++;
                left++;
            }
            if(right==left && domi[right]=='R')
                left++;   
            if(left>right && domi[left]=='.')
                left++;
            if(left>right && domi[left]=='R')
            {
                right=left;
                left++;
            }
            if(left>right && domi[left]=='L')
            {
                fall(ans,right+1,left-1);
                right=left+1;
                left++;
            }
        }
        
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]=='L')
            {
                if(i-2>=0)
            {
               if(i!=0 && ans[i]=='L' && ans[i-1]=='.' && ans[i-2]!='R')
                lt(ans,i-1); 
            }
            else if(i!=0 && ans[i]=='L' && ans[i-1]=='.')
                lt(ans,i-1);
            }
            else if(ans[i]=='R')
            {
                if(i+2<ans.size())
            {
                if(ans[i]=='R' && ans[i+1]=='.' && ans[i+2]!='L')
                rt(ans,i+1);
            }
            else if(ans[i]=='R' && ans[i+1]=='.')
                rt(ans,i+1);
            } 
        }
        return ans;
    }
};