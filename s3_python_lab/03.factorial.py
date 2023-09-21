# 3.  Find the factorial of number.

def factorial(num):
    if (num <= 1):
        return 1
    else:
        return num * factorial(num - 1)


num = int(input("Enter a number: "))
if (num < 0):
    print("Negative number is not allowed")
else:
    fact = factorial(num)
    print("Factorial of {num} is {fact}".format(num=num, fact=fact))

# Algorithm
# 1. Define a recursive function named factorial(num)
# 1.1. If num <= 1 : return 1
# 1.2. Else : return num * factorial(num - 1)
# 2. Prompt the user to enter a number and store it in a variable.
# 3. Convert the numer into integer.
# 4. Call the function factorial with the number and store the return value
#    in a variable named fact.
# 5. Display the factorial stored in fact.
