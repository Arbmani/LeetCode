#include "string"
#include "iostream"

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool AllCap     = true;
        bool NoCap      = true;
        bool FirstCap   = true;
        for(int index = 0 ; index < word.size(); index++){
            if(!(AllCap || NoCap || FirstCap)) return false;
            if ((word[index] < 'A') || (word[index] > 'Z')){
                if(index == 0) FirstCap = false;
                AllCap = false;
            }
            if ((word[index] < 'a') || (word[index] > 'z')){
                if(index != 0) FirstCap = false;
                NoCap = false;
            }    
        }
        return (AllCap || NoCap || FirstCap);        
    }
};


int main(){
    Solution s;

    cout << "Want :  true, Was : "  << boolalpha << s.detectCapitalUse("USA") << endl;
    cout << "Want : false, Was : " << boolalpha << s.detectCapitalUse("FlaG") << endl;

    return -1;
}