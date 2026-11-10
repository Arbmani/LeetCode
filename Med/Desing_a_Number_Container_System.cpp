#include "iostream"
#include "set"
#include "unordered_map"



using namespace std;

/**

Design a number container system that can do the following:

-   Insert or Replace a number at the given index in the system.

-   Return the smallest index for the given number in the system.

*/


//      Implement the NumberContainers class:
class NumberContainers {
private:
    unordered_map<int, int> indexToNumber;
    unordered_map<int, set<int>> numberToIndex;

public:
    //  NumberContainers() Initializes the number container system.
    NumberContainers() {}
    //  void change(int index, int number) Fills the container at index with the number. 
    //  If there is already a number at that index, replace it.
    void change(int index, int number) {
        if (indexToNumber.count(index)){
            int old_number = indexToNumber[index];
            if (old_number == number) return;
            numberToIndex[old_number].erase(index);
            if (numberToIndex[old_number].empty()) numberToIndex.erase(old_number);
        } 
        indexToNumber[index] = number;
        numberToIndex[number].insert(index);
    }
    
    //  int find(int number) Returns the smallest index for the given number, 
    //  or -1 if there is no index that is filled by number in the system.
    int find(int number) {
        if (numberToIndex.count(number)) return *numberToIndex[number].begin();
        return -1;     
    }
};

// hashmap index  -> number
// hasmap  number -> a sorted list of all indexes in ascending order


int main(){
    NumberContainers nc;

    cout << "\nWant : -1\nWas  : " << nc.find(10) << endl;
    nc.change(2, 10);
    nc.change(1, 10);
    nc.change(3, 10);
    nc.change(5, 10);
    cout << "\nWant : 1\nWas  : " << nc.find(10) << endl;
    nc.change(1, 20);
    cout << "\nWant : 2\nWas  : " << nc.find(10) << endl;
    return 0;
}

