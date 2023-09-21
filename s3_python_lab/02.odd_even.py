# 2. Check whether an entered number is odd or even.

num = int(input("Enter a integer: "))

if (num % 2 == 0):
    print("The number is even")
else:
    print("The number is odd")

# Algorithm
# 1. Prompt the user to enter a number and store them in a variable.
# 2. Convert the number to an integer.
# 3. Calculate the remainder of the number divided by 2 (num % 2).
#    3.1. If remainder is 0, then print number is even.
#    3.2. If remainder is not 0, then print number is odd.
