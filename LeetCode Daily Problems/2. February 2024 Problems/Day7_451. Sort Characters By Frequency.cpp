https://leetcode.com/problems/sort-characters-by-frequency/description/


// Approch -> 1: 
// T.C. = O(n * log(n))
// S.C. = O(log(n))
class Solution {
public:
    
    string frequencySort(string s) {
        vector<int> freq(128, 0) ;
        for(auto ch: s) freq[ch]++ ;
        
        auto cmp = [&] (char a, char b){
            if(freq[a] == freq[b])
                return a < b ;

            return freq[a] > freq[b] ;
        };

        sort(s.begin(), s.end(), cmp) ;

        return s ;
    }
};


// Approch -> 2: 
// T.C. = O(n + klog(k)))
// S.C. = O(n)
class Solution {
public:
    
    string frequencySort(string s) {
        unordered_map<char, int> mp ;
        for(auto ch: s) mp[ch]++ ;

        vector<pair<char, int>> freq ;
        for(auto it: mp) freq.push_back(it) ;
        
        auto cmp = [&] (pair<char, int> &a, pair<char, int> &b){
            return a.second > b.second ;
        } ;

        sort(freq.begin(), freq.end(), cmp) ;

        string ans = "" ;
        for(auto it: freq){
            ans.append(it.second, it.first) ;
        }

        return ans ;
    }
};


// Approch -> 3: 
// T.C. = O(n * k)
// S.C. = O(n)
class Solution {
public:
    
    string frequencySort(string s) {
        int n = s.length() ;
        unordered_map<char, int> freq ;
        for(auto ch: s) freq[ch]++ ;

        vector<vector<char>> bucketData(n + 1) ;
        for(auto [ch, fq]: freq){ 
            bucketData[fq].push_back(ch) ;
        }

        string ans = "" ;
        for(int fq = n ; fq >=1 ; fq--){
            for(auto ch: bucketData[fq]){
                ans.append(fq, ch) ;
            }
        }

        return ans ;
    }
};



class Solution {
public:
    string frequencySort(string s) {
        int n = s.size() ;
        string ans = "" ;
        unordered_map<char, int> frequecnyCount ;
        for(int i=0 ; i<n ; i++) frequecnyCount[s[i]]++ ;

        priority_queue<pair<int, char> > pq ;
        for(auto it: frequecnyCount) pq.push({it.second, it.first}) ;

        while(!pq.empty()){
            int len = pq.top().first ;
            char ch = pq.top().second ;
            pq.pop() ;
            while(len--) ans += ch ;
        }

        return ans ;
    }
};





class Solution {
public:
    
    string frequencySort(string s) {
        int n = s.size() ;
        string ans = "" ;
        unordered_map<char, int> frequecnyCount ;
        for(int i=0 ; i<n ; i++) frequecnyCount[s[i]]++ ;

        for(int i=0 ; i<frequecnyCount.size() ; i++){
            pair<char, int> maxFreq ;
            maxFreq.second = 0 ;
            for(auto it: frequecnyCount){
                if(it.second > maxFreq.second){
                    maxFreq = it ;
                }
            }
            frequecnyCount[maxFreq.first] = -1 ;
            string temp(maxFreq.second, maxFreq.first) ;
            ans += temp ;
        }

        return ans ;
    }
};

