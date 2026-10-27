#include "string" 
#include "iostream" 
#include <cctype>
#include <string>
#include <vector>
#include <map>

using namespace std;

/**

Given a string formula representing a chemical formula, 
return the count of each atom.

The atomic element always starts with an uppercase character, 
then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow 
if the count is greater than 1. If the count is 1, no digits will follow.

For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
Two formulas are concatenated together to produce another formula.

For example, "H2O2He3Mg4" is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula.

For example, "(H2O2)" and "(H2O2)3" are formulas.
Return the count of all elements as a string in the following form: the first name (in sorted order), 
followed by its count (if that count is more than 1), followed by the second name (in sorted order), 
followed by its count (if that count is more than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.



*/

class Solution {
private:
    int readNumber(const string& formula, int& index){
        int number = 0;
        while(index < formula.size() && isdigit(formula[index])){
            number = number * 10 + (formula[index] - '0');
            index++;
        }
        return number == 0 ? 1 : number;
    }
public:
    string countOfAtoms(string formula) {
        vector<map<string, int>> stack;
        stack.push_back({});

        int index = 0;

        while(index < formula.size()){
            if (formula[index] == '('){
                stack.push_back({});
                index++;
            }
            else if (formula[index] == ')') {
                map<string, int> group = stack.back();
                stack.pop_back();
                index++;

                int multiplier = readNumber(formula, index);

                for (const auto& atom : group){
                    const string&   element = atom.first;
                    int             count   = atom.second;
                    stack.back()[element]  += count * multiplier;
                }
            }
            else{
                string element = "";
                element += formula[index];
                index++;
                while(index < formula.size() && islower(formula[index])){
                    element += formula[index];
                    index++;
                }
                int count = readNumber(formula, index);
                stack.back()[element] += count;
            }
        }
        string ans = "";
        for (const auto& atom : stack.back()) {
            const string& element = atom.first;
            int           count   = atom.second;
            ans += element;
            if (count > 1) ans += to_string(count);
        }
        return ans;
    }
};


int main(){
    Solution s;

    cout << "Want :        H2O, Was : " << s.countOfAtoms("H2O") << endl;
    cout << "Want :     H2MgO2, Was : " << s.countOfAtoms("Mg(OH)2") << endl;
    cout << "Want :  K4N2O14S4, Was : " << s.countOfAtoms("K4(ON(SO3)2)2") << endl;

    return 0;
}