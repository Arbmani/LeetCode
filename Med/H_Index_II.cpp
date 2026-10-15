#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int smallerThan(int a, int b){
        return -1;
    }

    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, mid, right = n - 1; 
        while(left <= right){
            mid = left + (right - left) / 2;
            if (citations[mid] >= n - mid){
                right = mid  - 1;
            }
            else{
                left = mid  + 1;
            }
        }
        return n - left;
    }
};



int main() {

    Solution s;

    vector<int> c_1 = {0,1,3,5,6};
    vector<int> c_2 = {1,1,3};
    vector<int> c_3 = {100};
    vector<int> c_4 = {1, 2, 100};

    cout << "Want : 3, Was : " << s.hIndex(c_1) << endl;
    cout << "Want : 1, Was : " << s.hIndex(c_2) << endl;
    cout << "Want : 1, Was : " << s.hIndex(c_3) << endl;
    cout << "Want : 2, Was : " << s.hIndex(c_4) << endl;



    return -1;
}