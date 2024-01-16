import re
from cs50 import get_string

amex_regex = r"^3(4|7)[0-9]{13}$"
mastercard_regex = r"^(5[1-5][0-9]{14}|2[3-6][0-9]{14}|27[0-1][0-9]{14}|2720[0-9]{12})$"
visa_regex = r"^4[0-9]{12}([0-9]{3})?$"
input_number = get_string("Number:")

def check_luhn(card_number):
    def digits_of(n):
        return [int(i) for i in str(n)]  # Convert each digit to int
    digits = digits_of(card_number)
    total_sum = 0
    # Process odd and even digits
    odd_digits = digits[-2::-2]
    even_digits = digits[-1::-2]

    for digit in odd_digits:
        doubled = digit * 2
        if doubled >= 10:
            total_sum += sum(digits_of(doubled))
        else:
            total_sum += doubled

    for digit in even_digits:
        total_sum += digit

    return total_sum % 10 == 0

# Matching card type and validating with Luhn's algorithm
if re.match(amex_regex, input_number):
    print("AMEX")
elif re.match(mastercard_regex, input_number):
    print("MASTERCARD")
elif re.match(visa_regex, input_number):
    if check_luhn(input_number):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")


