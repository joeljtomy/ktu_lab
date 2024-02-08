# 7.  Search an element in a list.

listText = input("Enter list elements (comma-separated): ")
list = listText.strip(',').split(',')
key = input("Enter a search key: ")
count = 0

for i in range(len(list)):
    if key == list[i]:
        print(key, "found in the list at index", i)
        count += 1

if count != 0:
    print("Total", count, "appearences of", key)
else:
    print(key, "not found in the list.")

# Algorithm
# 1. Start
# 2. Prompt the user to enter a list and store it in a variable.
# 3. Prompt the user to enter a search key and store it in a variable.
# 4. Declare a variable count.
# 5. Start loop for i in range(len(list)):
# 5.1.   if key == list[i]:
#        -  print(key, "found in the list at index", i)
#        -  count += 1
# 6. If count != 0:
#        print("Total", count, "appearences of", key)
# 7. Else:
#        print(key, "not found in the list.")
