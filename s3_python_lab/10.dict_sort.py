# 10. Develop a python program to create a dictionary of phone numbers and names of n persons.
#    Display the contents of the dictionary in alphabetical order of their names.

phonebook = {}
n = int(input("Enter the number of persons: "))

for i in range(1, n + 1):
    name = input(f"Enter the name for person {i}: ")
    phone = input(f"Enter the phone number for {name}: ")
    phonebook[name] = phone

print("Phonebook entries in alphabetical order:")
for name in sorted(phonebook.keys()):
    print(f"{name}: {phonebook[name]}")

# Algorithm
# 1. Start
# 2. Declare phonebook = {}, i = 1.
# 3. Recive the number of entries as 'n'.
# 4. Start loop while (i <= n):
# 5. Recieve name.
# 6. If name in phonebook.keys():
#      print("name already exists!")
# 7  Else:
#      phone = input(f"Enter the phone number for {name}: ")
#      phonebook[name] = phone
#      i = i + 1
# 8. Start loop for name in sorted(phonebook.keys()):
#      print(f"{name}: {phonebook[name]}")
# 9. Stop
