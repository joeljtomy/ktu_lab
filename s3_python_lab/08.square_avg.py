# 8.  Input a list of n numbers. Calculate and display the average of numbers. Also display
#     the square of each value in the list.

user_list = input("Enter a list of numbers (comma-separated): ").strip(',').split(',')
list = [int(item) for item in user_list]

for i in list:
    print("Square of "+ str(i) +" = " + str(i * i))

print("Average = " + str(sum(list) / len(list)))


# Algorithm
# 1. Start
# 2. Prompt the user to enter a list and store it in a variable.
# 3. for i in list:
#        print("Square of "+ str(i) +" = " + str(i * i))
# 4. print("Average = " + str(sum(list) / len(list)))
# 5. Stop
