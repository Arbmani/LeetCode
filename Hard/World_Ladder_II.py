from typing import List 
from collections import defaultdict, deque

'''
    A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence
    of words beginWord -> s1 -> s2 -> ... -> sk such that:

    - Every adjacent pair of words differs by a single letter.

    - Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList

    - sk == endWord

    Given two words, beginWord and endWord, and a dictionary wordList, return all the 
    shortest transformation sequences from beginWord to endWord, or an empty list if
    no such sequences exists. Each sequence should be returned as a list of
    words [beginWord, s1, s2, s3, ..., sk].
'''
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        if endWord not in wordList:
            return []
        neighbors = defaultdict(list)

        for word in wordList: 
            for index in range(len(word)):
                pattern = word[:index] + "*" + word[index + 1:]
                neighbors[pattern].append(word)

        level           = {beginWord: 0}
        parents         = defaultdict(list)
        queue           = deque([beginWord])
        shortest_level  = None 

        while queue:
            word = queue.popleft()
            current_level = level[word]

            if shortest_level is not None and current_level >= shortest_level:
                continue
            for index in range(len(word)):
                pattern = word[:index] + "*" + word[index + 1:]
                for neighbor in neighbors[pattern]:
                    if neighbor not in level:
                        level[neighbor] = current_level + 1
                        parents[neighbor].append(word)
                        queue.append(neighbor)

                        if neighbor == endWord:
                            shortest_level = current_level + 1
                    elif level[neighbor] == current_level + 1:
                        parents[neighbor].append(word)
        if endWord not in level:
            return []

        result = []
        path = [endWord]
        def backtrack(word: str) -> List[List[str]]:
            if word == beginWord:
                result.append(path[::-1])
                return
            for parent in parents[word]:
                path.append(parent)
                backtrack(parent)
                path.pop()

        backtrack(endWord)

        return result



if __name__ == "__main__":
    print(Solution().findLadders(beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]))