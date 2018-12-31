def balancedParanthesis(Text):

    stack = [] # Create empty list (stack)
    brackets = {'}':'{', ']':'[', ')':'('}

    for i in Text:
        if( i in '[{(' ):
            stack.append(i)
        elif( i in ']})' ):
            if( len(stack) == 0 ):
                return False;

            if( stack[-1] == brackets[i] ): #if bracket is same as the top element of the stack
                stack.pop()

    return len(stack) == 0

if __name__ == "__main__" :

    Text = input("Enter string = ")

    if( balancedParanthesis(Text) ):
        print("BRACKETS ARE BALANCED")
    else:
        print("BRACKETS NOT BALANCED")
