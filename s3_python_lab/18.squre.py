# 18. Create a class Square with attributes number, output and methods calculate and display.
#     Create instance of the class and call method calculate to compute square of the number
#     and call method display to print output.

class Square:
    def __init__(self, number):
        self.number = number
        self.output = 0
    def calculate(self):
        self.output = self.number * self.number
    def display(self):
        print("Square of", self.number, "is", self.output)

square = Square(4)
square.calculate()
square.display()


# Algorithm
# 1. Start

# 11. Stop
