#include "iostream" 
#include "vector"

using namespace std;

/**

Your music player contains n different songs. 
You want to listen to goal songs (not necessarily different) during your trip.
To avoid boredom, you will create a playlist so that:

-   Every song is played at least once.

-   A song can only be played again only if k other songs have been played.

Given n, goal, and k, return the number of possible playlists that you can create. 
Since the answer can be very large, return it modulo 10**9 + 7.


*/

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int mod = 1e9 + 7;
        int totalSongs = n, targetPlayListLength = goal, minimumSongsBeforeReplay = k;
        vector<long long> playListCounts(totalSongs + 1, 0);
        playListCounts[0] = 1;
        for(int playListLength = 0; playListLength < targetPlayListLength; playListLength++){
            vector<long long> nextPlayListCounts(totalSongs + 1, 0);
            for (int uniqueSongsPlayed = 0; uniqueSongsPlayed <= totalSongs; uniqueSongsPlayed++){
                long long currentPlayListCount = playListCounts[uniqueSongsPlayed];
                if (currentPlayListCount == 0) continue;
                int unusedSongs = totalSongs - uniqueSongsPlayed;
                if(unusedSongs > 0){
                    nextPlayListCounts[uniqueSongsPlayed + 1] = (nextPlayListCounts[uniqueSongsPlayed + 1] + currentPlayListCount *unusedSongs) % mod;
                }
                int usablePlayedSongs = uniqueSongsPlayed - minimumSongsBeforeReplay;
                if (usablePlayedSongs > 0){
                    nextPlayListCounts[uniqueSongsPlayed] = (nextPlayListCounts[uniqueSongsPlayed] + currentPlayListCount * usablePlayedSongs) % mod;
                }
            }
            playListCounts = nextPlayListCounts;
        }
        return playListCounts[totalSongs];      
    }
};


int main(){
    Solution s;

    cout << "Want : 6, Was : " << s.numMusicPlaylists(3, 3, 1) << endl;
    cout << "Want : 6, Was : " << s.numMusicPlaylists(2, 3, 0) << endl;
    cout << "Want : 2, Was : " << s.numMusicPlaylists(2, 3, 1) << endl;

    return 0;
}