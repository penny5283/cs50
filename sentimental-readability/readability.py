# TODO
from cs50 import get_string
txt = get_string("Text: ")
def check_letters(text):
    count_l = 0
    for i in text:
        if i.isalpha():
            count_l += 1
    return count_l
def check_words(text):
    count_w = 0
    pre = None
    for i in text:
        if 


