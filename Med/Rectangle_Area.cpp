#include "iostream"

using namespace std;
/**
[Medium Problem]

Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.

The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).

The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).




*/


class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // Area of rec1 + rec2 - overlap
        int rec1 = abs(ax2 - ax1) * abs(ay2 - ay1);
        int rec2 = abs(bx2 - bx1) * abs(by2 - by1);
        

        int shared_bot = max(ay1, by1);
        int shared_top = min(ay2, by2);
        int shared_lef = max(ax1, bx1);
        int shared_rig = min(ax2, bx2);

        if (shared_lef > shared_rig  || shared_top < shared_bot){
            return rec1 + rec2;

        } 
        int overlap    = abs(shared_rig - shared_lef) * abs(shared_top - shared_bot);
        return rec1 + rec2 - overlap;
    }
};



int main(){
    Solution s;

    cout << "Want : 45, Was : " << s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    cout << "Want : 16, Was : " << s.computeArea(-2, -2, 2, 2, -2, -2, 2, 2) << endl;
    cout << "Want : 32, Was : " << s.computeArea(-2, -2, 2, 2, -20, -20, -24, -24) << endl;


    return -1;
}