# 14. Find nth Fibonacci number using recursion.

def fibonacci(n):
    if n <= 1: return 0
    elif n == 2: return 1
    else: return fibonacci(n - 1) + fibonacci(n - 2)

n = int(input("Enter the value of n: "))
print(f"{n}th Fibonacci number = {fibonacci(n)}")

# Algorithm
# 1. Start
# 2. Defines funtion to find nth Fibonacci number recursively.
# 2.1. if n <= 1:
#        return 0
# 2.2. elif n == 2:
#        return 1
# 2.3. else:
#        return fibonacci(n - 1) + fibonacci(n - 2)
# 3. Recieve value of n.
# 4. call Fibonacci function by passing n store the output as nth.
# 5. print the nth Fibonacci number, nth
# 6. Stop
