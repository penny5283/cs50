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
def main(item,pric):
    total_price = 0
    try:
        item = (input("Item:/n")).title()
        for key in menu:
            if key == item:
                total_price += int(menu[key])
            else:
                print("Not in the menu")
        print(f"Total: ${total_price:.2f}")
    except EOFerror:

main()
