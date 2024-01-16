# TODO
import re
amex_regex = ^3(4|7)[0-9]{13}$
card_number = "371234567890123"  # Example Amex card number
if re.match(amex_regex, card_number):
    print("Valid American Express card number")
else:
    print("Invalid American Express card number")
