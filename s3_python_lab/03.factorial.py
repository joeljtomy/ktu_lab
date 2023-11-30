# 3.  Find the factorial of number.

num = int(input("Enter a number: "))

if num < 0:
    print("Negative number is not allowed")
else:
    fact = 1
    for i in range(1, num + 1):
        fact *= i

    print("Factorial of", num, "is", fact)

# Algorithm
# 1. Start
# 2. Prompt the user to enter a number and store it in a variable.
# 3. Convert the number to an integer.
# 4. If num < 0 : Display Negative number is not allowed
# 5. Else : Calculate factorial
# 5.1. define fact = 1
# 5.2. Start loop for i in range(1, num + 1) :
# 5.2.1. fact = fact * i
# 5.3. Display the factorial stored in fact.
# 6. Stop

