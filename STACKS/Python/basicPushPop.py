if __name__ == "__main__" :
    size = int(input("Enter the size of the stack = "))

    STACK = []
    while True :

        choice = int(input("1. Push\n2. Pop & display the popped element\n3. Display\nEnter your choice = "))

        if choice ==  1 :
            if len(STACK) < size :
                element = int(input("\nEnter the element to push = "))
                STACK.append(element)
            else:
                print("\nStack is Full")
        elif choice == 2 :
            print("\nThe popped element is : ", STACK.pop())
        elif choice == 3 :
            print("\nStack : ", *STACK[::-1])
        else:
            break
