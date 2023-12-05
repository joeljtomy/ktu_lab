# 17. Develop a python program to implement the following scenario. Given a file “data.txt”
#     with three columns of data separated by spaces. Read it into 3 separate simple sequences.

file_path = input("Enter the file path: ")
seq1 = []
seq2 = []
seq3 = []
with open(file_path, "r") as file_in:
    print("file content:")
    for line in file_in:
        print(line)
        if line.strip() != "":
            row = line.split()
            seq1.append(row[0])
            seq2.append(row[1])
            seq3.append(row[2])

print("coloumn 1 sequence:", seq1)
print("coloumn 2 sequence:", seq2)
print("coloumn 3 sequence:", seq3)

# Algorithm
# 1. Start

# 11. Stop
