// Approch - (i) Jo character word1 m present h vahi character word2 m present hona chahiye 
//           (ii) characters ki frequencys same honi chahhiye
// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size() , n2 = word2.size() ;
        if(n1 != n2)
            return false ;

        vector<int> freq1(26, 0), freq2(26, 0) ;
        for(int i=0 ; i<n1 ; i++){
            freq1[word1[i] - 'a']++ ;
            freq2[word2[i] - 'a']++ ;
        }

        for(int i=0 ; i<26 ; i++){
            if(freq1[i] != 0 && freq2[i] == 0) return false ;
            if(freq1[i] == 0 && freq2[i] != 0) return false ; 
        }

        sort(freq1.begin(), freq1.end()) ;
        sort(freq2.begin(), freq2.end()) ;

        return (freq1 == freq2) ;
    }
};