'''
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]

Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
'''

class Solution:
    def diffWaysToCompute(self, input):
        result = []
        ''' 关键：for循环内的递归'''
        '''
        e.g., 2*3-4*5
        i = 0, pass
        i = 1, we meet a "*", result1 = self.diffWaysToCompute(2) = [2], result2 = self.diffWaysToCompute(3-4*5), recursively: 
            i = 0, pass
            i = 1:
            result2::result1 = [3], result2::result2 = self.diffWaysToCompute(4*5), recursively:
                i = 0，pass
                i = 1:
                result2::result2::result1 = [4], result2::result2::result2 = [5], result = [4*5] = [20], return
                result2::result2 = [20], return
            result2::result1 = [3], result2::result2 = [20], result = [-17], this is 3-(4*5)
            i = 2: pass
            i = 3: similarly, we will get: (3-4)*5 = -5, result = [-17, -5]
            i = 4, pass
            return [-17, -5]
        result1 = [2], result[2] = [-17, -5]
        so, result = [-34, -10]
            
        next, i = 2, pass
        next, i = 3, result1 = [2*3] = [6], result2 = [4*5] = [20], result.append(6-20), result = [-34, -10, -14]
        next, i = 4, pass
        next, i = 5, similarly, result1 = self.diffWaysToCompute(2*3-4), result2 = 5
            i = 0, pass
            i = 1, result1::result1 = 2, result1::result2 = -1, result1 = [-2]
            i = 2, pass
            i = 3, result1.append(2*3-4), result1 = [-2, 2]
        result.append(-2*5), result.append(2*5), result = [-34,-10,-14, -10, 10]
        '''
        for i in range( len(input) ):
            if input[i] in '+-*':
                result1 = self.diffWaysToCompute(input[:i]) ##result1是从0到i（不包括i）的式子所得的结果
                result2 = self.diffWaysToCompute(input[i+1:]) ##result2是从i+1到末尾）的式子所得的结果
                
                for num1 in result1:
                    for num2 in result2:
                        if input[i] == '-':
                            result.append(num1 - num2)
                        elif input[i] == '+':
                            result.append(num1 + num2)
                        else:
                            result.append(num1 * num2)
        
        ##如果只是一个数(没有操作符),那么就把这个数压入result
        if len(result) == 0:
            result.append(int(input))
        return result
                        
            
