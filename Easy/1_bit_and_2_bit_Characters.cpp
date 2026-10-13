#include <vector>
#include <iostream>

using namespace std;

class Solution {
    /**
     *  [Easy Problem]
     * 
     *      We have two special characters:
     *
     *      -   The first character can be represented by one bit 0.
     *      
     *      -   The second character can be represented by two bits (10 or 11).
     *      
     *      Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.
     * 
     */
public:
    // every 1 needs to be followed by a 1 or a 0
    // every 0 needs to be followed by a 0 or a leading 1 
    bool isOneBitCharacter(vector<int>& bits) {
        for (int i = 0; i < bits.size(); i++){
            if (bits[i] == 1){
                i++;
            }
            else if(i + 1 == bits.size()) return true;
        }
        return false;
    }
};



int main(){
    Solution solution;
    vector<int> bits1 = {1, 0, 0};
    vector<int> bits2 = {1, 1, 1, 0};
    vector<int> bits3 = {0, 1, 1, 1, 0};

    cout << "Want : true, Was : "  << boolalpha << solution.isOneBitCharacter(bits1) << endl;
    cout << "Want : false, Was : " << boolalpha << solution.isOneBitCharacter(bits2) << endl;
    cout << "Want : false, Was : " << boolalpha << solution.isOneBitCharacter(bits3) << endl;

}

