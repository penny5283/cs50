# TODO
import re
from cs50 import get_int
amex_regex = r"^3(4|7)[0-9]{13}$"
mastercard_regex = r"^(5[1-5][0-9]{14}|2[3-6][0-9]{14}|27[0-1][0-9]{14}|2720[0-9]{12})$"
visa_regex = visa_regex = r"^4[0-9]{12}([0-9]{3})?$"
input = get_int("Number:")
if re.match(input, amex_regex):
    print("AMEX")
if re.match(input, mastercard_regex):
    print("MASTERCARD")

