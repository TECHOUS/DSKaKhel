if __name__ == "__main__" :
    stack = []
    stack.append(1)
    stack.append(2)
    stack.append(3)
    stack.append(4)
    stack.append(5)
    
    print("Stack = ", *stack)
    stack = stack[::-1]
    print("Reverse Stack = ", *stack)
