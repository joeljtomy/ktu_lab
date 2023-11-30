# 11. Find the value of nCr using a function.

def factorial(num):
    if num > 0:
        return num * factorial(num - 1)
    return 1

def nCr(n, r):
    return factorial(n)/(factorial(r)*factorial(n-r))

n = int(input("Enter the value of n: "))
r = int(input("Enter the value of r: "))

if (n >= 0 and r >= 0 and n >= r):
    print(f"{n}C{r} = {nCr(n, r)}")
else:
    print("n and r should be non negative and n >= r")

# Algorithm
# 1. Start
# 2. Define function to calculate factorial.
# 2.1. if num > 0 :
# 2.2.    return num * factorial(num - 1)
# 2.3. return 1
# 3. Define function to calculate nCr.
# 3.1. return factorial(n)/(factorial(r)*factorial(n-r))
# 4. Recive the value for n.
# 5. Recive the value for r.
# 6. If n >= 0 and r >= 0 and n >= r :
#      nCr = nCr(n, r)
#      print(f"{n}C{r} = {nCr}")
# 7. Else:
#      print("n and r should be non negative and n >= r")
# 8. Stop
