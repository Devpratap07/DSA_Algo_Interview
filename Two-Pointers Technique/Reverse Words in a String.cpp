// Approach -> 1
// T.C -> O(n^2)
// S.C -> O(1)
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int i=0;
        int l=0,r=0;
        int n =s.length();
        while(i<n){
            while(i<n && s[i]!= ' '){
                s[r] = s[i];
                i++;
                r++;
            }
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                s[r]=' ';
                r++;
                l=r;
            }
            i++;
        }
        s=s.substr(0,r-1);
        return s;
    }
};
