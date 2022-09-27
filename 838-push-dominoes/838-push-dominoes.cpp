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
        int nl=0,nr=0;
        int i=0;
        while(right<=left && left<ans.size())
        {    
            // cout<<(i++)<<"left="<<left<<" right="<<right<<endl;
            
            // if(nr==1 && nl==0 && left>=ans.size()-1)
            //     {
            //         // cout<<"dd\n";
            //         rt(ans,right+1);
            //         nr--;
            //     }
            
            if(right==left && domi[right]!='R')
            {
                // cout<<"!=r"<<endl;
//                 if(domi[right]=='L')
//                     nl++;
                
//                 if(nl==1 && nr==0)
//                 {
//                     // cout<<"ok\n";
//                     lt(ans,right-1);
//                     // nl--;
//                 }                
                right++;
                left++;
                // continue;
            }
            if(right==left && domi[right]=='R')
            {
                // cout<<"r==r\n";
                // nr++;
                left++;   
                
                // if(nr==1 && nl==0 && left>=ans.size()-1)
                // {
                //     // cout<<"dd\n";
                //     rt(ans,right+1);
                //     // nr--;
                // }
                
                // continue;
            }
            if(left>right && domi[left]=='.')
                left++;
            
            if(left>right && domi[left]=='R')
            {
                // cout<<"l==r\n";
                right=left;
                left++;
                // continue;
            }
            if(left>right && domi[left]=='L')
            {
                // cout<<"l==l\n";
                fall(ans,right+1,left-1);
                right=left+1;
                left++;
                // nl++;
                // nr--;
                // nl--;
                // continue;
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