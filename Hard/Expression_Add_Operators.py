from typing import List


class Solution:
    '''
        Given a string "num" that contains only digits and an integer "target",
        return all possibilities to insert the binary operators "+", "-", and/or
        "*" between the digits of "num" so that the resultant expression
        evaluates to the "target" value.

        Note that operands in the returned expression should not contain leading zeros.

        Note that a number can contain multiple digits. 
    
    '''

    def addOperators(self, num: str, target: int) -> List[str]:
        len_num, result, path = len(num), [], []
        def dfs(i: int, value: int, prev: int) -> None:
            if i == len_num:
                if value == target:
                    result.append(''.join(path))
                return
            curr = 0
            path_len = len(path)
            for j in range(i, len_num):
                if num[i] == "0" and j > i:
                    break
                curr = curr * 10 + (ord(num[j]) - 48)
                curr_str = num[i:j + 1]
                if i == 0:
                    path.append(curr_str)
                    dfs(j + 1, curr, curr)
                    path.pop()
                    continue
                path.extend(("+", curr_str))
                dfs(j + 1, value + curr, curr)
                path.pop()
                path.pop()

                path.extend(("-", curr_str))
                dfs(j + 1, value - curr, -curr)
                path.pop()
                path.pop()

                path.extend(("*", curr_str))
                dfs(j + 1, value - prev + prev * curr, prev*curr)
                path.pop()
                path.pop()
        dfs(0, 0, 0)
        return result

    def addOperators_Really_Slow(self, num: str, target: int) -> List[str]:
        result = []

        def Depth_First_Search(index, path, path_sum, last_val) -> None:
            if index >= len(num):
                if path_sum == target:
                    result.append("".join(path))
            else:
                for i in range(index, len(num)):
                    curr_val_str = num[index:i + 1]
                    curr_val_int = int(curr_val_str)

                    if not path:
                        Depth_First_Search(index + 1, [curr_val_str], curr_val_int, curr_val_int)
                    else:
                        Depth_First_Search(index + 1, path + ["+"] + [curr_val_str], path_sum + curr_val_int, curr_val_int)
                        Depth_First_Search(index + 1, path + ["-"] + [curr_val_str], path_sum - curr_val_int, curr_val_int)
                        Depth_First_Search(index + 1, path + ["*"] + [curr_val_str], path_sum - last_val + curr_val_int * last_val, curr_val_int * last_val)

                    if num[index] == "0":
                        break
        Depth_First_Search(0, [], 0, 0)

        return result

if __name__ == "__main__":
    print(f"Expected solution is : {["1*2*3","1+2+3"]}, Mine is : {Solution().addOperators(num = "123", target = 6)}")