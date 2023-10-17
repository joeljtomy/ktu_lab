# 10. Develop a python program to create a dictionary of phone numbers and names of n persons.
#    Display the contents of the dictionary in alphabetical order of their names.

phonebook = {}

n = int(input("Enter the number of persons: "))

i = 1
while (i <= n):
    name = input(f"Enter the name for person {i}: ")
    if name in phonebook.keys():
        print("name already exists!")
    else:
        phone = input(f"Enter the phone number for {name}: ")
        phonebook[name] = phone
        i = i+1

print("Phonebook entries in alphabetical order:")
for name in sorted(phonebook.keys()):
    print(f"{name}: {phonebook[name]}")

# Algorithm
# 1. Start
# 2. Declare phonebook = {}.
# 3. Recive the number of entries as 'n'.
# 4. Start loop for i in range(n):
# 4.1. name = input(f"Enter the name for person {i+1}: ")
# 4.2. phone = input(f"Enter the phone number for {name}: ")
# 4.3. phonebook[name] = phone
# 5. for name in sorted(phonebook.keys()):
# 5.1. print(f"{name}: {phonebook[name]}")
# 6. Stop
