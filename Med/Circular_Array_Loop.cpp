#include "vector"
#include "iostream"

using namespace std;


/**

You are playing a game involving a circular array of non-zero integers nums. 
Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:

-   If nums[i] is positive, move nums[i] steps forward, and

-   If nums[i] is negative, move abs(nums[i]) steps backward.

Since the array is circular, you may assume that moving forward from the last element puts you on the first element, 
and moving backwards from the first element puts you on the last element.

A cycle in the array consists of a sequence of indices seq of length k where:

-   Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...

-   Every nums[seq[j]] is either all positive or all negative

-   k > 1

Return true if there is a cycle in nums, or false otherwise.
.

*/
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        auto nextIndex = [&](int i, bool forward) -> int {
            if (nums[i] == 0 || (nums[i] > 0) != forward) return -1;
            int next = ((long long)i + nums[i]) % n;
            if (next < 0) next += n;
            if (next == i) return -1;
            return next;
        };
        for (int i = 0; i < n; i++){
            if (nums[i] == 0) continue;
            bool forward = nums[i] > 0;
            int snail   = i;
            int turtle  = i;
            while (true) {
                snail = nextIndex(snail, forward);
                if (snail  == -1) break;
                turtle = nextIndex(turtle, forward);
                if (turtle == -1) break;
                turtle = nextIndex(turtle, forward);
                if (turtle == -1) break;
                if (turtle == snail) return true;
            }
            int curr = i;
            while (curr != -1 && nums[curr] != 0 && (nums[curr] > 0) == forward){
                int next = nextIndex(curr, forward);
                nums[curr] = 0;
                curr = next;
            }
        }


        return false;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {2, -1, 1, 2, 2};
    vector<int> nums2 = {-1, -2, -3, -4, -5, 6};
    vector<int> nums3 = {1, -1, 5, 1, 4};

    cout << "\nWant : true\nWas  : " <<boolalpha << s.circularArrayLoop(nums1) << endl;
    cout << "\nWant : false\nWas  : "<<boolalpha  << s.circularArrayLoop(nums2) << endl;
    cout << "\nWant : true\nWas  : " <<boolalpha << s.circularArrayLoop(nums3) << endl;


    return 0;
}