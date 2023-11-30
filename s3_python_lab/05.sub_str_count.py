# 5.  Find the number of occurrences of a given substring in a string.

string = input("Enter a string: ").strip()
sub_str = input("Enter the substring to count: ")

count = string.count(sub_str)

print("Total", count, "occurrences of:", sub_str)


# Algorithm
# 1. Start
# 2. Prompt the user to enter a string and store it in a variable.
# 3. Prompt the user to enter a sub_string and store it in another variable.
# 4. Declare count = 0.
# 5. count = string.count(sub_str)
# 6. Print Total occurrences {count}
# 7. Stop
