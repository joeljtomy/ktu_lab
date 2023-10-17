#9.  Add two matrices.

def input_matrix(rows, cols):
    matrix = []
    for i in range(rows):
        row = []
        for j in range(cols):
            row.append(int(input(f"Enter element ({i},{j}): ")))
        matrix.append(row)
    return matrix

def display_matrix(matrix):
    for row in matrix:
        print(row)

rows = int(input("Enter the number of rows for the matrices: "))
cols = int(input("Enter the number of columns for the matrices: "))

print("Enter the first matrix:")
matrix1 = input_matrix(rows, cols)

print("Enter the second matrix:")
matrix2 = input_matrix(rows, cols)

result = []
for i in range(rows):
    row = []
    for j in range(cols):
        row.append(matrix1[i][j] + matrix2[i][j])
    result.append(row)

print("Resultant matrix after addition:")
display_matrix(result)

# Algorithm
# 1. Start
# 2. define function input_matrix to recieve a matrix.
# 3. define function to print a matrix.
# 4. recieve rows and coloumns of matrices.
# 5. recieve matrix1 and matrix2 using input_matrix function.
# 6. Declare result = []
# 7. Start loop for i in range(rows):
# 7.1. row = []
# 7.2. Start loop for j in range(cols):
# 7.3.1. row.append(matrix1[i][j] + matrix2[i][j])
# 7.4. result.append(row)
# 7. Stop
