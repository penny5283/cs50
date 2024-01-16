# TODO
import re
from cs50 import get_string
amex_regex = r"^3(4|7)[0-9]{13}$"
mastercard_regex = r"^(5[1-5][0-9]{14}|2[3-6][0-9]{14}|27[0-1][0-9]{14}|2720[0-9]{12})$"
visa_regex = visa_regex = r"^4[0-9]{12}([0-9]{3})?$"
input = get_string("Number:")
def check_luhn(card_number):
    def digits_of(n):
        for i in n:
            return int(i)
    digits = digits_of(card_number)
    odd_digits = digits[-2::-2]
    even_digits = digits[-1::-2]
    for i in odd_digits:
        double = i * 2
        if double >= 10:
            

if re.match(input, amex_regex):
    print("AMEX")
if re.match(input, mastercard_regex):
    print("MASTERCARD")

