from typing import List 


class Solution:
    '''
        How does it work?

        Well in the question statement, the sentance: 
        
            "Extra space between words should be distributed
            as evenly as possible. If the number of spaces on a line do not divide evenly between words,
            the empty slot on the left will be assigned more spaces than the slot on the right"

        Was just a really long and awkward way to say "Round Robin". The following line implements the round robin logic:

            for i in range(maxWidth - current_line_letters):
                current_line[i%(len(current_line)-1 or 1)] += ' '

        So how does it work?

        Once you determine that there are only "k" words that fit on a given line, you know what the total length 
        of those words is "current_line_letters". Then the resultt are spaces, and there are (maxWidth - current_line_letters)
        of spaces. The "or 1" part is for dealing with the edge case len(current_line) == 1.
    '''
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        result, current_line, current_line_letters = [], [], 0
        for current_word in words:
            number_of_words_on_line = len(current_line)
            if current_line_letters + number_of_words_on_line + len(current_word)  > maxWidth:  # Given atleast 2 words
                spaces_needed = maxWidth - current_line_letters                                 # Need  atleast 1 space

                for i in range(spaces_needed):                                                  # Adding spaces in
                    current_line[i % (number_of_words_on_line - 1 or 1)] += ' '                 # Round Robin skip last word

                result.append(''.join(current_line))
                current_line, current_line_letters = [], 0

            current_line.append(current_word)
            current_line_letters += len(current_word)

        return result + [' '.join(current_line).ljust(maxWidth)]



if __name__ == "__main__":
    sol = Solution()
    print(sol.fullJustify(words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16))

