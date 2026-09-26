import heapq
class Solution:
    '''
    [Medium Problem]

        You are given a deck of cards represented by a string array cards, and each card displays two lowercase letters.

        You are also given a letter x, You play a game with the following rules:

        -   Start with 0 points.

        -   On each turn, you must find two compatible cards from the deck that both contains the letter x in any position.

        -   Remove the pair of cards and earn 1 point.

        -   The game ends when you can no longer find a pair of compatible cards.

        Return the maximum number of points you can gain with optimal play.

        Two cards are compatible if the strings differ in exactly 1 point. 
    
    
    
    '''
    def score(self, cards: list[str], x: str) -> int:
        left_letter, right_letter, both_letters, ord_a = [0] * 26, [0] * 26, 0, ord('a')

        for card in cards:
            left, right = card

            if left == x:
                if right == x:
                    both_letters += 1
                else:
                    left_letter[ord(right) - ord_a] += 1

            elif right == x:
                right_letter[ord(left) - ord_a] += 1

        def solve_groups(letter_count: list[int]) -> tuple[int, int]:
            total = sum(letter_count)
            largest = max(letter_count)

            pairs = min(total // 2, total - largest)
            leftover = total - 2 * pairs

            return pairs, leftover

        left_pairs, left_over = solve_groups(left_letter)
        right_pairs, right_over = solve_groups(right_letter)

        base = left_pairs + right_pairs

        use_both = min(both_letters, left_over + right_over)
        both_letters -= use_both

        return use_both + min(base * 2, base + both_letters // 2)




    def score_failure(self, cards: list[str], x: str) -> int:
        left_letter, right_letter, both_letters, ord_a = [0] * 26, [0] * 26, 0, ord('a')
        for card in cards:
            if x not in card: continue

            left, right = card 
            if   left == x and right == x   : both_letters += 1
            elif left == x                  : left_letter[ord(right) - ord_a] += 1
            else                            : right_letter[ord(left) - ord_a] += 1
        def solve_groups(counts: list[int]) -> tuple[int, int]:
            total, largest = sum(counts), max(counts)
            pairs          = min(total // 2, total - largest)
            carry_over     = total - 2*pairs 
            return pairs, carry_over
        left_pairs , left_over  = solve_groups(left_letter)
        right_pairs, right_over = solve_groups(right_letter)

        pairs = left_pairs + right_pairs
        use_both = min(both_letters, left_over + right_over)
        pairs += use_both

        return pairs


    def score_Best(self, cards: list[str], x: str) -> int:
        left_letter, right_letter, both_letters, ord_a = [0] * 26, [0] * 26, 0, ord('a')
        for card in cards:
            if x not in card: continue

            left, right = card 
            if   left == x and right == x   : both_letters += 1
            elif left == x                  : left_letter[ord(right) - ord_a] += 1
            else                            : right_letter[ord(left) - ord_a] += 1
        sum_left, sum_right = sum(left_letter), sum(right_letter)
        max_left, max_right = max(left_letter), max(right_letter)

        def pairs(total: int, largest: int, universal: int) -> int:
            limit = (total + universal) // 2
            largest_remaining = max(0, largest - universal)
            distribution_limit = total - largest_remaining
            return min(limit, distribution_limit)
        ans = 0
        for use_left in range(both_letters + 1):
            use_right   = both_letters - use_left
            pairs_left  = pairs(sum_left, max_left, use_left)
            pairs_right = pairs(sum_right, max_right, use_right)
            ans = max(ans, pairs_left + pairs_right)
        return ans


    def score_Wrong(self, cards: list[str], x: str) -> int:
        '''
        Fails on : 
            print(f"Want : {1}, Was : {Solution().score(["ba","ab","be","ee","bd"], x = "b")}")
            Since output is 2
        
        
        '''
        left_letter, right_letter, both_letters, ord_a = [0] * 26, [0] * 26, 0, ord('a')
        for card in cards:
            if x not in card: continue

            left, right = card 
            if   left == x and right == x   : both_letters += 1
            elif left == x                  : left_letter[ord(right) - ord_a] += 1
            else                            : right_letter[ord(left) - ord_a] += 1

        valid_cards = both_letters + sum(left_letter) + sum(right_letter)
        if valid_cards < 2: return 0
        max_left, max_right = max(left_letter), max(right_letter)
        unvalid_combination = max(both_letters, max_left + max_right)
        return min(valid_cards // 2, valid_cards - unvalid_combination)







# 2, 2 , 2 word case we get 2 matches
# (0,1)(0,2) (1, 1, 1) then we can also get 1 more match i.e., either (0,1)/(0,2)/(1,2)


if __name__ == "__main__":
    print(f"Want : {1}, Was : {Solution().score(["ba","ab","be","ee","bd"], x = "b")}")

    print(f"Want : {0}, Was : {Solution().score(cards = ["ab","ab"], x = "a")}")
    print(f"Want : {0}, Was : {Solution().score(cards = ["ab","ab", "ca", "ca"], x = "a")}")
    print(f"Want : {2}, Was : {Solution().score(cards = ["ab","ab", "ac", "ac"], x = "a")}")
    print(f"Want : {2}, Was : {Solution().score(cards = ["aa","ab","ba","ac"], x = "a")}")
    print(f"Want : {1}, Was : {Solution().score(cards = ["aa","ab","ba"], x = "a")}")
    print(f"Want : {0}, Was : {Solution().score(cards = ["aa","ab","ba","ac"], x = "b")}")