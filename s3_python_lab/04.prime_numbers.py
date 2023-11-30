# 4.  Print all prime numbers with in an interval.

low = int(input("Enter the low of the range: "))
high = int(input("Enter the high of the range: "))

if low < 2:
    low = 2

for num in range(low, high + 1):
    for x in range(2, num // 2 + 1):
        if num % x == 0:
            break
    else : print(x, end = " ")

# Algorithm
# 1. Start
# 2. Prompt the user to enter the low & high of a range and store them in two variables.
# 3. Convert both of them to integers.
# 4. If low < 2 set low = 2
# 5. Start loop for num in range(low, high + 1):
# 5.1. Start loop for x in range(2, num // 2 + 1):
# 5.1.1. If num % x == 0
#        - break loop
# 5.2. Else : print(x, end = ", ")
# 6. Stop
