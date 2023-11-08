# 16. Develop a python code to read a text file, copy the contents to another file after
#     removing the blank lines.

file1 = open("file1.txt","w")
content = input("file 1 created write to file: ")
file1.write(content)
file1.close()

file2 = open("file2.txt","a")
file1 = open("file1.txt","r")
content = file1.read()
for line in content :
    if line != "\n" :
       file2.write(line)

file2 = open("file2.txt","r")
print("content copied to 2nd file:", file2.read())

# Algorithm
# 1. Start

# 11. Stop

