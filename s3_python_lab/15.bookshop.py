# 15. Develop a Python program to implement the following scenario. A bookshop’s details
#     contain the title of the book and Number of copies of each title. As books are added
#     to shop the number of copies in each should increase and as books are sold the number
#     of copies in each should decrease.

bookshop = []

def add_book(title, copies):
    for book in bookshop:
        if book['title'] == title:
            book['copies'] += copies
            break
    else:
        bookshop.append({'title': title, 'copies': copies})

def sell_book(title, copies):
    for book in bookshop:
        if book['title'] == title:
            if book['copies'] >= copies:
                book['copies'] -= copies
                print(f'Sold {copies} copies of "{title}"')
                if book['copies'] == 0:
                    bookshop.remove(book)
                break
            else:
                print(f'Not enough copies of "{title}" in stock.')
            break
    else:
        print(f'Book "{title}" not found.')

def display_bookshop():
    if len(bookshop) :
        print("Currently available books:")
        for book in bookshop:
            print(f'"{book["title"]}": {book["copies"]} copies')
    else :
        print("No books in shop:")

while True:
    print("\nBookshop Management Menu:")
    print("1. Add Book")
    print("2. Sell Book")
    print("3. Display all books")
    print("4. Quit")

    choice = input("Enter your choice: ")

    if choice == '1':
        title = input("Enter the title of the book: ")
        copies = int(input("Enter the number of copies to add: "))
        add_book(title, copies)
    elif choice == '2':
        title = input("Enter the title of the book: ")
        copies = int(input("Enter the number of copies to sell: "))
        sell_book(title, copies)
    elif choice == '3':
        display_bookshop()
    elif choice == '4':
        print("Exiting the program.")
        break
    else:
        print("Invalid choice!")


# Algorithm
# 1. Start
# 2. Initialize an empty list called "bookshop" to store book titles and copies.
# 3. Display a menu with options: "Add Book," "Sell Book," "Display all books," "Quit."
# 4. Accept the user's choice.
# 5. If the choice is "Add Book":
#    5.1. Prompt for a book title and the number of copies to add.
#    5.2. If the book exists in the "bookshop," update the copy count; otherwise, add the book.
# 6. If the choice is "Sell Book":
#    6.1. Prompt for a book title and the number of copies to sell.
#    6.2. If the book exists and has enough copies, update the stock; remove it if sold out.
#    6.3. If the book doesn't exist, print a "book not found" message.
#    6.4. If there are not enough copies, print an "out of stock" message.
# 7. If the choice is "Display all books," show the list of available books.
# 8. If the choice is "Quit," end the program.
# 9. If the choice is invalid, display an "Invalid choice" message.
# 10. Repeat from step 3 until the user chooses to quit.
# 11. Stop

