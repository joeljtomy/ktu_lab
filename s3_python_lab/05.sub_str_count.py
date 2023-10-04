# 5.  Find the number of occurrences of a given substring in a string.

string = input("Enter a string: ")
sub_str = input("Enter the substring to count: ")
word = ''
count = 0

for i in range(0, len(string)):
    if string[i] != ' ':
        word = word + string[i]
    elif word != '':
        if word == sub_str:
            count = count + 1
        word = ''
if word == sub_str:
    count = count + 1


print("Total {count} occurrences of '{sub_str}'".format(
    count=count, sub_str=sub_str))


# Algorithm
# 1. Start
# 2. Prompt the user to enter a string and store it in a variable.
# 3. Prompt the user to enter a sub_string and store it in another variable.
# 4. Declare word = '', count = 0.
# 5. Start loop for i in range(0, len(string)):
# 5.1. If string[i] != ' ' :
#        word = word + string[i]
# 5.2  Elif word != '' :
#        if word == sub_str:
#          count = count + 1
#        word = ''
# 6. If word == sub_str :
# 6.1. count = count + 1
# 7. Stop
