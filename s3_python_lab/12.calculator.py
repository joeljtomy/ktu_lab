# 12. Implement a calculator with functions like add, subtract, multiply, divide, exponent etc.

def add(a, b): return a + b

def subtract(a, b): return a - b

def multiply(a, b): return a * b

def divide(a, b): return a / b

def exponent(a, b): return a ** b

n1 = int(input("Enter 1st operand: "))
n2 = int(input("Enter 2nd operand: "))

while True:
    print("Calculator operations")
    print("1. Addition\n2. Subtraction\n3. Multiplication")
    print("4. Division\n5. Exponent\n6. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        print(f"Addition: {n1} + {n2} = {add(n1, n2)}")
    elif choice == 2:
        print(f"Subtraction: {n1} - {n2} = {subtract(n1, n2)}")
    elif choice == 3:
        print(f"Multiplication: {n1} x {n2} = {multiply(n1, n2)}")
    elif choice == 4:
        print(f"Division: {n1} / {n2} = {divide(n1, n2)}")
    elif choice == 5:
        print(f"Exponent: {n1} ^{n2} = {exponent(n1, n2)}")
    elif choice == 6:
        print("Program exited!!!")
        break
    else :
        print("Invalid choice!")

# Algorithm
# 1. Start
# 2. Defines five functions (add, subtract, multiply, divide, and exponent).
# 3. Prompts the user to enter two integer operands, n1 and n2.
# 4. Start loop while True :
# 5.   Print Menu 1. Addition, 2. Subtraction, 3. Multiplication
#                 4. Division, 5. Exponent, 6. Exit
# 6.   Recieve the users choice
# 7.   calls the corresponding function based on the choice
#      and print the output
# 8.   if choice is 6. Exit then break the loop
# 9. Stop
