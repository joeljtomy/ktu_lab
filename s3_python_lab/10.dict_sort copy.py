# 11. Find the value of nCr using a function.

def factorial(num):
    if num > 0 :
        return num * factorial(num - 1)
    return 1

n = int(input("Enter the value of n: "))
r = int(input("Enter the value of r: "))

if n >= 0 and r >= 0 and n >= r :
    nCr = factorial(n)/(factorial(r)*factorial(n-r))
    print(f"{n}C{r} = {nCr}")
else :
    print("n and r should be non negative and n >= r")

# Algorithm
# 1. Start
# 2. Define function to calculate factorial.
# 2.1. if num > 0 :
# 2.2.    return num * factorial(num - 1)
# 2.3. return 1
# 3. Recive thw value for n.
# 4. Recive thw value for r.
# 5. If n >= 0 and r >= 0 and n >= r :
#      nCr = factorial(n)/(factorial(r)*factorial(n-r))
#      print(f"{n}C{r} = {nCr}")
# 6. Else:
#      print("n and r should be non negative and n >= r")
# 7. Stop