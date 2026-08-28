from typing import List
from collections import defaultdict, deque

'''
    A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence
    of words beginWord -> s1 -> s2 -> ... -> sk such that:

    - Every adjacent pair of words differs by a single letter.

    - Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList

    - sk == endWord

    Given two words, beginWord and endWord, and a dictionary wordList, return the number of words
    in the shortest transformation sequence from beginWord to endWord, or 0 if no such
    sequence exists. 




'''



class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        if beginWord not in wordList:
            wordList.append(beginWord)
        neighbors = defaultdict(list)

        for word in wordList: 
            for index in range(len(word)):
                pattern = word[:index] + "*" + word[index + 1:]
                neighbors[pattern].append(word)

        visited = set([beginWord])
        que     = deque([beginWord])
        result = 1
        while que:
            for words in range(len(que)):
                word = que.popleft()
                if word == endWord:
                    return result
                for index in range(len(word)):
                    pattern = word[:index] + "*" + word[index + 1:]
                    for neighbor in neighbors[pattern]:
                        if neighbor not in visited:
                            visited.add(neighbor)
                            que.append(neighbor)
            result += 1
        return 0

if __name__ == "__main__":
    print(Solution().ladderLength(beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]))