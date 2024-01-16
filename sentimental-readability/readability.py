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
        if i == " ":
            count_w += 1
            pre = i
    #check if the last word is not a space to include the last word
    if pre != " ":
        count_w += 1
    return count_w

def check_sentences(text):
    count_s = 0
    for i in text:
        if i == "." or i == "?" or i == "!":
            count_s += 1
    return count_s

count_l = check_letters(txt)
count_w = check_words(txt)
count_s = check_sentences(txt)


index = 0
L = count_l / count_w * 100
S = count_s / count_w * 100
index = 0.0588 * L - 0.296 * S - 15.8

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade {}".format(index))



