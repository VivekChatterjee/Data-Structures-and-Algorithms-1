// class Solution {
// public:
//     int longestPalindrome(vector<string>& words) {
//         map<string,int>m;
//         for(string a:words) m[a]++;
//         bool pal=false;
//         for(auto i:m)
//         {
//             string a=i.first;
//             string b=a;
//             reverse(b.begin(), b.end());
//             if(a == b || !m.count(b))
//             {
//                 if(a==b) pal=true;
                
//                 m.erase(a); 
//             }
//         }
//         if(pal) return max(2, (int)(m.size()*2));
//         else return m.size()*2;
//     }
// };

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
       int count[26][26] = {}; 
       int ans = 0;
			for(auto w : words){
				int a = w[0] - 'a';
				int b = w[1] - 'a'; 

				if(count[b][a]){
					ans+= 4;          
					count[b][a]--;
				}else
					count[a][b]++;
			}
			for(int i=0;i<26;i++){
				if(count[i][i]){
					ans+=2;
					break;
				}
			 }
	return ans;
    }
};