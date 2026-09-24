class Solution:
    '''
    [Easy Problem]
    
        You are given an integer money denoting the amount of money (in dollars) that you have
        and another integer children denoting the number of children that must distribute the money to.

        You have to distribute the money according to the following riles:

        -   All money must be distributed.

        -   Everyone must receive at least 1 dollar.

        -   Nobody receives 4 dollars.

        Return the maximum number of children who may recieve exactly 8 dollars if you distribute the
        money according to the aforementioned rules. If there is no way to distribute the money,
        return -1.


    '''

    def distMoney(self, money: int, children: int) -> int:
        if money < children: return -1
        money -= children
        eights = min(money // 7, children)  
        money -= eights * 7
        if (eights == children and money > 0) or (eights == children -1 and money == 3):
            eights -=1
        return eights

if __name__ == "__main__":
    print(f"Want : {1}, Was : {Solution().distMoney(money = 20, children = 3)}")
    print(f"Want : {2}, Was : {Solution().distMoney(money = 16, children = 2)}")