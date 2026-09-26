class Solution:
    '''
    [Medium Problem]

        You are given a string "s" that contains some bracket pairs, with each pair containing a non-empty key.

        -   For example, in the string "(name)is(age)yearsold, there are two bracket pairs that contain the keys "name" and "age".

        You know the value of a wide range of keys. This is represented by a 2D string array knowledge where each knowledge[i] = [key_i, value_i]
        indicates that key "key_i" has a value of value_i.

        You are tasked to evaluate all of the bracket pairs. When you evaluate a bracket pair that contians some key key_i, you will:

        -   Replace key_i and the bracket pair with the key's corresponding value_i.

        -   If you do not knwo the value of the key, you will replace key_i and the bracket pair with a question mark "?" 
            (without the quotation marks).
            
        Each key will appear at most once in your knowledge. There will not be any nested brackets in "s".

        Return the resulting string after evaluating all of the bracket pairs.
    
    
    '''
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        ans, knowledge, start = [], dict(knowledge), 0
        while(start < len(s)):
            if s[start] == "(":
                end = s.find(")", start)
                ans.append(knowledge.get(s[start + 1 : end], "?"))
                start = end + 1
            else:
                ans.append(s[start])
                start += 1

        return "".join(ans)



    def evaluate_slow(self, s: str, knowledge: list[list[str]]) -> str:
        knowledge = dict(knowledge)
        len_s     = len(s)
        ans = []
        left = 0
        while left < len(s):
            if s[left] == "(":
                right = left + 1
                while right < len_s and s[right] != ")":
                    right += 1

                key = s[left + 1: right]
                if key in knowledge: ans.append(knowledge[key])
                else: ans.append("?")
                left = right + 1
            else:
                ans.append(s[left])
                left += 1

        return "".join(ans)

if __name__ == "__main__":
    print(f"Want : {"yes"}, Was : {Solution().evaluate(s = "(a)", knowledge = [["a","yes"]])}")

    print(f"Want : {"bobistwoyearsold"}, Was : {Solution().evaluate(s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]])}")

    print(f"Want : {"hi?"}, Was : {Solution().evaluate(s = "hi(name)", knowledge = [["a","b"]])}")

    print(f"Want : {"yesyesyesaaa"}, Was : {Solution().evaluate(s = "(a)(a)(a)aaa", knowledge = [["a","yes"]])}")