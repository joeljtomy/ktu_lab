# 6.  Count the number of vowels, consonants, words and question marks in a given string.

string = input("Enter a string: ").lower().strip()
vowels_list = ['a', 'e', 'i', 'o', 'u']
vowels, consonants, words, qn_marks = 0, 0, 0, 0
inword = False

for i in range(0, len(string)):
    if (string[i] in vowels_list):
        vowels += 1
    elif ((string[i] > 'a') and (string[i] < 'z')):
        consonants += 1
    elif (string[i] == '?'):
        qn_marks += 1
    if string[i] != ' ' and not (inword):
        inword = True
        words += 1
    elif (string[i] == ' '):
        inword = False

print("Vowels: {vowels}, Consonants: {consonants}, Words: {words}, Question marks: {qn_marks}".format(
    vowels=vowels, consonants=consonants, words=words, qn_marks=qn_marks))


# Algorithm
# 1. Start
# 2. Prompt the user to enter a string and store it in a variable.
# 3. Declare a list of all vowels.
# 4. Declare vowels = 0, consonants = 0, words = 0, qn_marks = 0, inword = False.
# 5. Start loop for i in range(0, len(string)):
# 5.1. If string[i] in vowels_list :
#        vowels = vowels + 1
# 5.2  Elif (string[i] > 'a') and (string[i] < 'z') :
#        consonants = consonants + 1
# 5.3  Elif (string[i] == '?') :
#        qn_marks = qn_marks + 1
# 5.4  If string[i] != ' ' and not(inword) :
#        inword = True
#        words = words + 1
# 5.5  Elif string[i] == ' ':
#        inword = False
# 6. Print vowels, consonants, words, qn_marks
# 7. Stop
