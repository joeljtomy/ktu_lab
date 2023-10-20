# 14. Find nth Fibonacci number using recursion.

def fibonacci_nth(n, series=[0,1]):
    if len(series) >= n:
        return series[n-1], series
    else:
        series.append(series[len(series) - 1] + series[len(series) - 2])
        return fibonacci_nth(n, series)

n = int(input("Enter the value of n: "))
nth, series = fibonacci_nth(n)
print("Fibonacci series:", series)
print(f"{n}th Fibonacci number = {nth}")


# Algorithm
# 1. Start
# 2. Defines funtion to find nth Fibonacci number recursively.
# 2.1. if len(series) >= n:
#        return series[n-1]
# 2.2. else:
#        series.append(series[len(series) - 1] + series[len(series) - 2])
#        return fibonacci_nth(n, series)
# 3. Recieve value of n.
# 4. call Fibonacci function by passing n store the output as nth.
# 5. print the nth Fibonacci number, nth
# 6. Stop
