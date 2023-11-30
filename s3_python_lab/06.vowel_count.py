# 6.  Count the number of vowels, consonants, words and question marks in a given string.

string = input("Enter a string: ").lower().strip()
vowels, consonants, words, qn_marks = 0, 0, 0, 0

for i in range(len(string)):
    if (string[i] in ['a', 'e', 'i', 'o', 'u']):
        vowels += 1
    elif ((string[i] > 'a') and (string[i] < 'z')):
        consonants += 1
    elif (string[i] == '?'):
        qn_marks += 1

words = len([word for word in string.split(" ") if word != ""])

print("Vowels:", vowels, ", Consonants:", consonants)
print("Words:", words, ", Question marks:", qn_marks)


# Algorithm
# 1. Start
# 2. Prompt the user to enter a string and store it in a variable.
# 3. Declare vowels = 0, consonants = 0, words = 0, qn_marks = 0.
# 4. Start loop for i in range(len(string)):
# 4.1. If string[i] in vowels_list :
#        vowels = vowels + 1
# 4.2  Elif (string[i] > 'a') and (string[i] < 'z') :
#        consonants = consonants + 1
# 4.3  Elif (string[i] == '?') :
#        qn_marks = qn_marks + 1
# 5. words = len([word for word in string.split(" ") if word != ""])
# 6. Print vowels, consonants, words, qn_marks
# 7. Stop
