#include "string"
#include "iostream"
#include "vector"

using namespace std;

/**


Given a string queryIP, return 

-   "IPv4" if IP is a valid IPv4 address, 

-   "IPv6" if IP is a valid IPv6 address or 

-   "Neither" if IP is not a correct IP of any type.

A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. 
For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses 
while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.

A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

-   1 <= xi.length <= 4

-   xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') 
    and upper-case English letters ('A' to 'F').

-   Leading zeros are allowed in xi.

For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" 
are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" 
are invalid IPv6 addresses.



*/

class Solution {
private:
    vector<string> split(const string& ip, char delimiter) {
        vector<string> segments;
        size_t start = 0;

        while(start <= ip.size()){
            size_t end = ip.find(delimiter, start);
            segments.push_back(ip.substr(start, end == string::npos ? string::npos : end - start)); 
            if (end == string::npos) break;
            start = end + 1;
        }
        return segments;
    }

    bool isValidIPv4(const string& ip) {
        vector<string> segments = split(ip, '.');
        if (segments.size() != 4) return false;
        
        for (const string& segment : segments){
            if (segment.empty() || segment.size() > 3)   return false;
            if (segment.size() > 1 && segment[0] == '0') return false;
            int num = 0;

            for (char character : segment) {
                if (character < '0' || character > '9') return false;
                num = num * 10 + (character - '0');
            }
            if (num > 255) return false;
        }
        return true;
    }

    bool isValidIPv6(const string& ip) {
        vector<string> segments = split(ip, ':');
        if (segments.size() != 8) return false;

        for (const string& segment : segments) {
            if (segment.empty() || segment.size() > 4) return false;

            for (char character : segment) {
                bool isDigit        = character >= '0' && character <= '9';
                bool isLowercaseHex = character >= 'a' && character <= 'f';
                bool isUppercaseHex = character >= 'A' && character <= 'F';
                if   (!isDigit && !isLowercaseHex && !isUppercaseHex) return false;
            }
        }
        return true;
    }



public:
    string validIPAddress(string queryIP) {
        if (isValidIPv4(queryIP)) return "IPv4";
        if (isValidIPv6(queryIP)) return "IPv6";
        return "Neither";
    }
};

int main(){
    Solution s;

    cout << "Want :    IPv4, Was : " << s.validIPAddress("172.16.254.1") << endl;
    cout << "Want :    IPv6, Was : " << s.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") << endl;
    cout << "Want : Neither, Was : " << s.validIPAddress("256.256.256.256") << endl;

    return 0;
}