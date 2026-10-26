#include "string"
#include <cassert>
#include <vector>
#include "iostream"

using namespace std;

/**
There is a stream of n (idKey, value) pairs arriving in an arbitrary order, 
where idKey is an integer between 1 and n and value is a string. 
No two pairs have the same id.

Design a stream that returns the values in increasing order of their IDs 
by returning a chunk (list) of values after each insertion. 
The concatenation of all the chunks should result in a list of the sorted values.
*/
// Implement the OrderedStream class:
class OrderedStream {
private:
    vector<string> values;
    int ptr;

public:
    
    // OrderedStream(int n) Constructs the stream to take n values.
    OrderedStream(int n) : values(n + 1), ptr(1) {}
    
    // String[] insert(int idKey, String value) Inserts the pair (idKey, value) into the stream, 
    // then returns the largest possible chunk of currently inserted values that appear next in the order.
    vector<string> insert(int idKey, string value) {
        values[idKey] = std::move(value);
        vector<string> result;

        while(ptr < static_cast<int>(values.size()) && !values[ptr].empty()){
            result.push_back(std::move(values[ptr]));
            ++ptr;
        }
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

int main() {
    OrderedStream os(5);

    assert(os.insert(3, "ccccc") == vector<string>{});
    assert(os.insert(1, "aaaaa") == vector<string>{"aaaaa"});

    assert(os.insert(2, "bbbbb") ==
           (vector<string>{"bbbbb", "ccccc"}));

    assert(os.insert(5, "eeeee") == vector<string>{});

    assert(os.insert(4, "ddddd") ==
           (vector<string>{"ddddd", "eeeee"}));

    cout << "All tests passed!\n" << endl;
}