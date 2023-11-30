# 13. Find the factorial of a given number using recursion.

def factorial(num):
    if num > 0:
        return num * factorial(num - 1)
    return 1

num = int(input("Enter the number: "))
if num < 0 :
    print("number should be non-negative.")
else :
    print(f"factorial of {num} = {factorial(num)}")


# Algorithm
# 1. Start
# 2. Defines funtion to find factorial recursively.
# 2.1. if num > 0 :
# 2.2.    return num * factorial(num - 1)
# 2.3. return 1
# 4. Recieve a number
# 5. print the factorial of the number, factorial(num)
# 6. Stop
