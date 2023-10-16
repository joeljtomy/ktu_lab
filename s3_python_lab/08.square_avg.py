# 8.  Input a list of n numbers. Calculate and display the average of numbers. Also display
#     the square of each value in the list.

input_list = input(
    "Enter a list of numbers (comma-separated): ").strip(',').split(',')
user_list = [int(item) for item in input_list]

print("Average =", sum(user_list) / len(user_list))

sqr_list = [item * item for item in user_list]

print("Square of elements:", sqr_list)


# Algorithm
# 1. Start
# 2. Prompt the user to enter a list and store it in a variable.
# 3. Convert the list items into integers
# 4. Print("Average =", sum(user_list) / len(user_list))
# 5. sqr_list = [item * item for item in user_list]
# 6. Print("Square of elements:", sqr_list)
# 7. Stop
