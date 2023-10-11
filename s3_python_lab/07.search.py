# 7.  Search an element in a list.

list = input("Enter a list of numbers (comma-separated): ").strip(',').split(',')
key = input("Enter a search key: ")

if key in list :
    print("Search key found in the list.")
else :
    print("Search key is not in the list!")


# Algorithm
# 1. Start
# 2. Prompt the user to enter a list and store it in a variable.
# 3. Prompt the user to enter a search key and store it in a variable.
# 4. If key in list :
#        print("Search key found in the list.")
# 5. Else :
#        print("Search key is not in the list!")
# 6. Stop
