from typing import List

'''
    Given an array of strings "number_of_words" and a width "maxWidth", format the text such that each line has exactly
    "maxWidth" characters and is fully (left and right) justified.

    You should pack your number_of_words in a greedy approach; that is, pack as many number_of_words as you can in each line.
    Pad extra spaces '' when necessary so that each line has exactly maxWidth characters.
    
    Extra spaces between number_of_words should be distributed as evenly as possible. If the number of spaces on a 
    line does not divide evenly between number_of_words, the empty slots on the left will be assigned
    more spaces than the slots on the right.

    For the last line of text, it should be left-justified, and no extra space is inserted between number_of_words.


    Notes:

        - A word is defined as character sequence consisting of non-space characters only.

        - Each word's length is guranteed to be greater than 0 and not exceed maxWidth.

        - The input array number_of_words contains at least one word. 



'''



from typing import List


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        cache = {}

        width = 0
        number_of_words = 0
        number_of_words_size = 0
        index = 0

        for word in words + [None]:

            if word is None:
                cache[index] = {
                    "number_of_words": number_of_words,
                    "number_of_words_size": number_of_words_size
                }
                break

            word_size = len(word) if number_of_words == 0 else len(word) + 1

            if width + word_size > maxWidth:
                cache[index] = {
                    "number_of_words": number_of_words,
                    "number_of_words_size": number_of_words_size
                }

                index += 1
                width = len(word)
                number_of_words_size = len(word)
                number_of_words = 1

            else:
                width += word_size
                number_of_words += 1
                number_of_words_size += len(word)


        result = []
        word_index = 0

        for line_number, line_info in cache.items():

            number_of_words = line_info["number_of_words"]
            number_of_words_size = line_info["number_of_words_size"]

            line_words = words[
                word_index:word_index + number_of_words
            ]

            word_index += number_of_words

            if line_number == len(cache) - 1:
                line = " ".join(line_words)
                line += " " * (maxWidth - len(line))

            else:
                total_spaces = maxWidth - number_of_words_size
                gaps = number_of_words - 1

                if gaps == 0:
                    line = line_words[0] + " " * total_spaces

                else:
                    spaces_per_gap = total_spaces // gaps
                    extra_spaces = total_spaces % gaps

                    line = ""

                    for i, word in enumerate(line_words):
                        line += word

                        if i < gaps:
                            line += " " * (
                                spaces_per_gap +
                                (1 if i < extra_spaces else 0)
                            )

            result.append(line)

        return result




if __name__ == "__main__":
    sol = Solution()
    print(sol.fullJustify(words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16))