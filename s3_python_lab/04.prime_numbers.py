# 4.  Print all prime numbers with in an interval.

low = int(input("Enter the low of the range: "))
high = int(input("Enter the high of the range: "))

if low < 2:
    low = 2
for num in range(low, high + 1):
    for x in range(2, num // 2 + 1):
        if num % x == 0:
            break
    else : print(x, end = ", ")

# Algorithm
# 1. Start
# 2. Prompt the user to enter the low & high of a range and store them in two variables.
# 3. Convert both of them to integers.
# 4. create empty array prime_numbers to store prime numbers
# 5. If low < 0 Display Low range should not be negative.
# 6. Else continue to next steps
# 7. Set i = low
# 8. Repeat steps 7.1 to 7.4 for num in range(low, high + 1):
# 8.1. Declare variables isPrime = True,
# 8.2. Repeat steps 7.2.1 to 7.2.2 for x in range(2, int(math.sqrt(num)) + 1):
# 8.2.1. If num % x == 0
#        - set isPrime = False
#        - break loop
# 8.3. If isPrime append num to array prime_numbers
# 9. If len(prime_numbers) Display Prime numbers
# 10. Else Display No prime numbers in the range
# 11. Stop
