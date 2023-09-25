# 2. Check whether an entered number is odd or even.

num = int(input("Enter a integer: "))

if (num % 2 == 0):
    print("The number is even")
else:
    print("The number is odd")

# Algorithm
# 1. Start
# 2. Prompt the user to enter a number and store it in a variable.
# 3. Convert the number to an integer.
# 4. Calculate the remainder of the number divided by 2 (num % 2).
#    4.1. If remainder is 0, then print number is even.
#    4.2. If remainder is not 0, then print number is odd.
# 5. Stop

