# 8.  Input a list of n numbers. Calculate and display the average of numbers. Also display
#     the square of each value in the list.

listText = input("Enter a list of numbers (comma-separated): ")
list = listText.strip(',').split(',')
list = [int(item) for item in list]

print("Average =", sum(list) / len(list))

sqr_list = [item * item for item in list]

print("Square of elements:", sqr_list)

# Algorithm
# 1. Start
# 2. Prompt the user to enter a list and store it in a variable.
# 3. Convert the list items into integers
# 4. Print("Average =", sum(list) / len(list))
# 5. sqr_list = [item * item for item in list]
# 6. Print("Square of elements:", sqr_list)
# 7. Stop
