#include <cassert>
#include <cstddef>
#include <deque>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

/**

Design a data structure that can efficiently manage data packets in a network router.
Each data packet consists of the following attributes:

-   source:         A unique identifier for the machine that generated the packet.

-   destination:    A unique identifier for the target machine.

-   timestamp:      The time at which the packet arrived at the router.

Implement the Router class:

Router(int memoryLimit): Initializes the Router object with a fixed memory limit.

-   memoryLimit:    Is the maximum number of packets the router can store at any given time.

-   If adding a new packet would exceed this limit, the oldest packet must be removed to free up space.

bool addPacket(int source, int destination, int timestamp): Adds a packet with the given attributes
to the router.

-   A packet is considered a duplicate if another packet with the same source, destination, 
    and timestamp already exists in the router. 

-   Return true if the packet is successfully added (i.e., it is not a duplicate); otherwise return false.

int[] forwardPacket(): Forwards the next packet in FIFO (First In First Out) order.

-   Remove the packet from storage.

-   Return the packet as an array [source, destination, timestamp].

-   If there are not packets to forward, return an empty array.

int getCount(int destination, int startTime, int endTime):

-   Returns the number of packets currently stored in the router (i.e., not yet forwarded) that have the specified
    destination and have timestamps in the inclusive range [startTime, endTime]

Note that queries for addPacket will be made in non-decreasing order of timestamp.

*/

class Router {
private:
    struct Packet {
        int source;
        int destination;
        int timestamp;

        bool operator==(const Packet& other) const {
            return source == other.source && destination == other.destination && timestamp == other.timestamp;
        }
    };

    struct PacketHash {
        size_t operator()(const Packet& packet) const {
            size_t hashValue = hash<int>{}(packet.source);
            hashValue ^=    (hash<int>{}(packet.destination)
                            + 0x9e3779b9 + (hashValue << 6)
                            + (hashValue >> 2));
            hashValue ^=    (hash<int>{}(packet.timestamp)
                            + 0x9e3779b9 + (hashValue << 6)
                            + (hashValue >> 2));
            return hashValue;
        }
    };

    int memoryLimit;
    queue<Packet> packets;
    unordered_set<Packet, PacketHash> packetSet;
    unordered_map<int, deque<int>> timestampsByDestination;

    void removeOldestPacket(){
        Packet oldestPacket = packets.front();
        packets.pop();
        packetSet.erase(oldestPacket);

        auto& timestamps = timestampsByDestination[oldestPacket.destination];
        timestamps.pop_front();
        if (timestamps.empty()) timestampsByDestination.erase(oldestPacket.destination);
    }


public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}
    
    bool addPacket(int source, int destination, int timestamp) {
        Packet newPacket{source, destination, timestamp};
        if (packetSet.count(newPacket))                        return false;
        if (packets.size() == static_cast<size_t>(memoryLimit))   removeOldestPacket();
        packets.push(newPacket);
        packetSet.insert(newPacket);
        timestampsByDestination[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (packets.empty()) return {};
        Packet packet = packets.front();
        removeOldestPacket();
        return {packet.source, packet.destination, packet.timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = timestampsByDestination.find(destination);
        if (it == timestampsByDestination.end()) return 0;
        const auto& timestamps = it->second;
        auto first = lower_bound(timestamps.begin(), timestamps.end(), startTime);
        auto last  = upper_bound(timestamps.begin(), timestamps.end(), endTime);

        return static_cast<int>(last - first);
    }
};

int main(){
    Router router(3);

    assert(router.addPacket(1, 4, 90) == true);
    assert(router.addPacket(2, 5, 90) == true);

    assert(router.addPacket(1, 4, 90) == false);

    assert(router.addPacket(3, 5, 95) == true);
    assert(router.addPacket(4, 5, 105) == true);


    assert(router.forwardPacket() == (vector<int>{2, 5, 90}));

    assert(router.addPacket(5, 2, 110) == true);
    assert(router.getCount(5, 100, 110) == 1);

    cout << "All tests passed" << endl;

    return 0;
}