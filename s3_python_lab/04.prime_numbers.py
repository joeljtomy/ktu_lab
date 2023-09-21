# 4.  Print all prime numbers with in an interval.

import math

low = int(input("Enter the low of the range: "))
high = int(input("Enter the high of the range: "))
primes = []

if low < 0:
    print("Low range should not be negative.")
else:
    i = low
    while i < high:
        isPrime = True
        j = 2
        while j <= math.sqrt(i):
            if i % j == 0:
                isPrime = False
                break
            j += 1
        if isPrime and i > 1:
            primes.append(i)
        i += 1
    if len(primes):
        print("Prime numbers are: {primes}".format(primes=primes))
    else:
        print("No prime numbers in the range")


# Algorithm
# 1. Prompt the user to enter the low & high of a range and store them in two variables.
# 2. Convert both of them to integers.
# 3. create empty array primes to store prime numbers
# 4. If low < 0 Display Low range should not be negative.
# 5. Else continue to next steps
# 6. Set i = low
# 7. Repeat steps 7.1 to 7.4 until i < high
# 7.1. Declare variables isPrime = True, j = 0.
# 7.2. Repeat steps 7.2.1 to 7.2.2 until j <= math.sqrt(i)
# 7.2.1. If i % j == 0
#        - set isPrime = False
#        - break loop
# 7.2.2. j += 1
# 7.3. If isPrime and i > 1
#      - append i to array primes
# 7.4. i += 1
# 8. If len(primes) Display Prime numbers
# 9. Else Display No prime numbers in the range
