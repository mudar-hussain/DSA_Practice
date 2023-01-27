class Solution {
    unordered_set<string> dict;
    unordered_set<string> formed_words;
public:
    bool canBeFormed(string word){
        if(formed_words.find(word) != formed_words.end())
            return true;
        
        for(int i = 1; i<word.length(); i++){
            string s1 = word.substr(0, i);
            if(dict.find(s1) != dict.end()){
                string s2 = word.substr(i);
                if(dict.find(s2) != dict.end() || canBeFormed(s2)){
                    formed_words.insert(word);
                    return true;
                }
                
            }
        }
        return false;
        
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        for(auto w: words){
            dict.insert(w);
        }
        for(auto word: words){
            if(canBeFormed(word))
                res.push_back(word);
        }
        return res;
        
    }
};