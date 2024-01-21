menu = {
    "Baja Taco": 4.25,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

def main():
    total_price = 0.0
    while True:
        try:
            item = input("Item: ").title()
            if item in menu:
                total_price += menu[item]
                print(f"Total: ${total_price:.2f}")
            # No need to notify the user if the item is not in the menu
        except EOFError:
            print("\n")  # Move the cursor to a new line
            break

    print(f"Final Total: ${total_price:.2f}")

main()
