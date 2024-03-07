from InfixToPostfix import Stack

def isOperand(c):
    return c not in "+-*/"

def Evaluate(postfix):
    st = Stack()
    st.s = [0] * len(postfix)
    for i in postfix:
        if isOperand(i):
            st.push(int(i))
        else:
            if i=='+':
                c = st.pop() + st.pop()
                st.push(c)
            elif i=='-':
                temp = st.pop()
                c = st.pop() - temp
                st.push(c)
            elif i=='*':
                c = st.pop() * st.pop()
                st.push(c)
            elif i=='/':
                temp = st.pop()
                c = st.pop() / temp
                st.push(int(c))
    return st.stackTop()

print(Evaluate('35*62/+4-'))

# 3*5 + 6/2 - 4
# 15 + 3 -4
# 14