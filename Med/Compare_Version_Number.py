class Solution:
    '''
    [Medium Problem]
    
        Given two version strings, version1 and version2, compare them. 
        A version string consists of revisions separated by dots '.'. 
        The value of the revision is its integer conversion ignoring leading zeros.

        To compare version strings, compare their revision values in left-to-right order. 
        If one of the version strings has fewer revisions, treat the missing revision values as 0.

        Return the following:

        -   If version1 < version2, return -1.
        
        -   If version1 > version2, return 1.
        
        -   Otherwise, return 0.

    '''


    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split(".")
        v2 = version2.split(".")

        for a, b in zip(v1, v2):
            a, b = int(a), int (b)
            if a < b: return -1
            if a > b: return  1
        for a in v1[len(v2):]:
            if int(a) != 0: return  1
        for b in v2[len(v1):]:
            if int(b) != 0: return -1 
        return 0



    #    def getList(s: str) -> list[int]:
    #        result       = []
    #        num, leading = "", True
    #        for char in s:
    #            if char == ".":
    #                result.append(int(num or "0"))
    #                num, leading = "", True
    #            elif not(char == "0" and leading): 
    #                num    += char 
    #                leading = False
    #        if num: result.append(int(num))
    #        return result
    #    v1, v2 = getList(version1), getList(version2)
    #    min_len = min(len(v1), len(v2))
    #    for index in range(min_len):
    #        if   v1[index] < v2[index]: return -1
    #        elif v2[index] < v1[index]: return  1
    #    if   len(v1) > len(v2): return  1
    #    elif len(v1) < len(v2): return -1
    #    return 0



# idea casta till float

if __name__ == "__main__":
    print(f"Want : {-1}, Was : {Solution().compareVersion(version1 = "0.1", version2 = "1.0")}")


    print(f"Want : {-1}, Was : {Solution().compareVersion(version1 = "7.5.2.4", version2 = "7.5.3")}")

    print(f"Want : {-1}, Was : {Solution().compareVersion(version1 = "1.2", version2 = "1.10")}")
    print(f"Want : {0}, Was : {Solution().compareVersion(version1 = "1.01", version2 = "1.001")}")
    print(f"Want : {0}, Was : {Solution().compareVersion(version1 = "1.0", version2 = "1.0.0.0")}")