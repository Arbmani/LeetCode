from typing import List

class Node:
    def __init__(self):
        self.children    = {}
        self.end_of_word = False

class Trie():
    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = Node()
            node = node.children[char]
        node.end_of_word = True

    def search(self, word: str) -> bool:
        node = self.root 
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.end_of_word

    def startWith(self, prefix: str) -> bool:
        node = self.root 
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True


class Solution:
    '''
        Given an "m x n" "board" of characters and a list of strings "words", return all words on the board.

        Each word must be constructed from letters of sequentially adjacent cells, 
        where adjacent cells are horizontally or vertically neighboring. The
        same letter cell may not be used more than once in a word.
    
    
    '''
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = Trie()
        for word in words:
            root.insert(word)
        rows, cols = len(board), len(board[0])
        result, visited = set(), set()

        def Depth_First_Search(row, col, node, word):
            if (row < 0 or row >= rows or
                col < 0 or col >= cols or 
                board[row][col] not in node.children or 
                (row, col) in visited):
                return
            visited.add((row, col))
            node = node.children[board[row][col]]
            word += board[row][col]
            if node.end_of_word:
                result.add(word)
            Depth_First_Search(row + 1, col, node, word)
            Depth_First_Search(row - 1, col, node, word)
            Depth_First_Search(row, col + 1, node, word)
            Depth_First_Search(row, col - 1, node, word)
            visited.remove((row, col))

        for row in range(rows):
            for col in range(cols):
                Depth_First_Search(row, col, root.root, "")
        return list(result)

if __name__ == "__main__":
    print(Solution().findWords(board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]))