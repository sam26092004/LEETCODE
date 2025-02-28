class Solution {
public:
    int numberOfSubstrings(string s) {
        int aidx=-1,bidx=-1,cidx=-1;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                aidx=i;
            }else if(s[i]=='b'){
                bidx=i;
            }else{
                cidx=i;
            }
            cnt+=(1+min({aidx,bidx,cidx}));
        }
      return cnt;
        
    }
};