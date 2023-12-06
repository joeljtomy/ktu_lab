# 16. Develop a python code to read a text file, copy the contents to another file after
#     removing the blank lines.

file_path = input("Enter the file path: ")

with open(file_path, "r") as file_in:
    content = file_in.read()
    print("file content:")
    print(content)
    with open("file_out.txt", "w") as file_out:
        for line in content.split("\n"):
            if line.strip() != "":
                file_out.write(line+"\n")

with open("file_out.txt", "r") as file_out:
    print("file content after removing blank lines:")
    print(file_out.read())

# Algorithm
# 1. Start

# 11. Stop

