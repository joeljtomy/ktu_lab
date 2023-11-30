# 9.  Add two matrices.

def get_matrix(rows, cols):
    matrix = []
    for i in range(rows):
        row = []
        for j in range(cols):
            row.append(int(input(f"Enter element ({i},{j}): ")))
        matrix.append(row)
    return matrix

def display_matrix(matrix):
    for row in matrix:
        for elm in row:
            print(elm, end='  ')
        print()

rows = int(input("Enter the number of rows for the matrices: "))
cols = int(input("Enter the number of columns for the matrices: "))

print("Enter the first matrix:")
matrix1 = get_matrix(rows, cols)

print("Enter the second matrix:")
matrix2 = get_matrix(rows, cols)

print("First matrix:")
display_matrix(matrix1)
print("Second matrix:")
display_matrix(matrix2)

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
# 2. define function get_matrix to recieve a matrix.
# 3. define function to print a matrix.
# 4. recieve rows and coloumns of matrices.
# 5. recieve matrix1 and matrix2 using get_matrix function.
# 6. Display matrix1 and matrix2 using display_matrix function.
# 7. Declare result = []
# 8. Start loop for i in range(rows):
# 8.1. row = []
# 8.2. Start loop for j in range(cols):
# 8.3.1. row.append(matrix1[i][j] + matrix2[i][j])
# 8.4. result.append(row)
# 9. Display result.
# 10. Stop
