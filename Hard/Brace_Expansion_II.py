class Solution:
    '''
    [Hard Problem]

        Under the grammar given below, strings can represent a set of lowercase words.
        Let R(expr) denote the set of words the expression represents.

        The grammar can best be understood through simple examples:

        -   Single letters represent a singleton set containing that word.

            -   R("a") = {"a"}

            -   R("w") = {"w"}

        -   When we take a comma delimited list of two or more expressions,
            we take the union of possibilities.

            -   R("{a,b,c}") = {"a","b","c"}

            -   R("{{a,b}, {b,c}}) = {"a","b","c"}

        -   When we concatentate two expressions, we take the set of possible concatenations between
            two words where the first word comes from the first expression and the second word 
            comes from the second expression.

            -   R("{a,b}{c,d}") = {"ac","ad","bc","bd"}

            -   R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}
        
        Formally, the three rules of our grammar:

            -   For every lowercase letter x, we have R(x) = {x}

            -   For expressions e1, e2, ..., ek with k >= 2, we have R({e1, e2, ...}) = R(e1) ∪ R(e2) ∪ ...

            -   For expression e1 and e2, we have R(e1 + e2) = {a + b for (a, b) in R(e1) × R(e2)} where
                "+" denotes concatenation, and "×" denotes the cartesian product.

        Given an expression representing a set of words under the given grammar, return the sorted list
        of words that the expression represents.
    
    
    '''

    def braceExpansionII(self, expression: str) -> list[str]:
        def parser(i: int) -> tuple[set[str], int]:
            ans  = set()
            curr = {""}
            while i < len(expression) and expression[i] != "}":
                if expression[i] == "{":
                    nested, i = parser(i + 1) 
                    curr      = {a + b
                                for a in curr
                                for b in nested}
                elif expression[i].isalpha():
                    curr = {word + expression[i] for word in curr}
                    i += 1
                elif expression[i] == ",":
                    ans.update(curr)
                    curr = {""}
                    i += 1
            ans.update(curr)
            if i < len(expression) and expression[i] == "}":
                i += 1
            return ans, i 
        ans, _ = parser(0)
        return sorted(ans)

if __name__ == "__main__":
    print(f"Want : {["ac","ad","ae","bc","bd","be"]}, Was : {Solution().braceExpansionII(expression = "{a,b}{c,{d,e}}")}")
    
    print(f"Want : {["a","ab","ac","z"]}, Was : {Solution().braceExpansionII(expression = "{{a,z},a{b,c},{ab,z}}")}")