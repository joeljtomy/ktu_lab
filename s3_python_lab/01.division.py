# 1. Find the quotient and remainder of two integers entered by user.

dividend = int(input("Enter the dividend (integer): "))
divisor = int(input("Enter the divisor (integer): "))

print("The quotient is: ", dividend // divisor)
print("And the remainder is: ", dividend % divisor)

#Algorithm
# 1. Prompt the user to enter the dividend and divisor and store them in a variable.
# 2. Convert the dividend and divisor into integers.
# 3. Calculate Quotient and Remainder:
#    3.1. Quotient = dividend // divisor
#    3.2. Remainder = dividend % divisor
# 4. Display the quotient and remainder to the user.
