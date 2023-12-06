# 16. Develop a python code to read a text file, copy the contents to another file after
#     removing the blank lines.

file_path = input("Enter the file path: ")

with open(file_path, "r") as file_in:
    content = file_in.read()
    print("file content:")
    print(content)
    print("\nLines with python:")
    for line in content.split("\n"):
        if "python" in line.lower():
            print(line)

# Algorithm
# 1. Start

# 11. Stop

