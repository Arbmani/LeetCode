from collections import defaultdict
class Solution:
    '''
    [Hard Problem]

        You are given an array of strings "ideas" that represent a list of names to be used in the 
        process of naming a company. The process of naming a company is as follows:

        1.   Choose 2 distinct names from "ideas", call them "idea_a" and "idea_b"

        2.  Swap the first letters of "idea_a" and "idea_b" with each other.

        3.  If both of the new names are not found in the original ideas, then the name 
            "idea_a idea_b" (the concatentation of "idea_a" and "idea_b", seperated by a space)
            is a valid company name.

        4.  Otherwise, it is not a valid name.

        Return the number of distinct valid names for the company. 


    '''
    def distinctNames(self, ideas: list[str]) -> int:
        prefix_to_suffix = defaultdict(set)
        for word in ideas:
            prefix_to_suffix[word[0]].add(word[1:])
        letters = list(prefix_to_suffix)
        len_letters = len(letters)
        res = 0
        for a_i in range(len_letters):
            for b_i in range(a_i + 1, len_letters):
                a = prefix_to_suffix[letters[a_i]]
                b = prefix_to_suffix[letters[b_i]]
                common = len(a & b)
                unique_a = len(a) - common
                unique_b = len(b) - common 
                res += 2* unique_a * unique_b

        return res 
    def distinctNames_slow(self, ideas: list[str]) -> int:
        prefix_to_suffix = defaultdict(set)
        for word in ideas:
            prefix_to_suffix[word[0]].add(word[1:])
        res = 0
        for prefix_1 in prefix_to_suffix:
            for prefix_2 in prefix_to_suffix:
                if prefix_1 == prefix_2: continue
                intersect = 0
                for suffix_a in prefix_to_suffix[prefix_1]:
                    if suffix_a in prefix_to_suffix[prefix_2]:
                        intersect += 1
                distinct_1 = len(prefix_to_suffix[prefix_1]) - intersect
                distinct_2 = len(prefix_to_suffix[prefix_2]) - intersect
                res += distinct_1 * distinct_2
                
        

        return res

if __name__ == "__main__": 
    print(f"Want : {6}, Was : {Solution().distinctNames(ideas = ["coffee","donuts","time","toffee"])}")
    print(f"Want : {0}, Was : {Solution().distinctNames(ideas = ["lack","back"])}")