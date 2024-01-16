from cs50 import get_string

# Get user input
txt = get_string("Text: ")

def count_letters(text):
    return sum(1 for char in text if char.isalpha())

def count_words(text):
    return len(text.split())

def count_sentences(text):
    return sum(1 for char in text if char in ['.', '?', '!'])

count_l = count_letters(txt)
count_w = count_words(txt)
count_s = count_sentences(txt)

# Handle potential division by zero
if count_w == 0:
    index = 0
else:
    L = (count_l / count_w) * 100
    S = (count_s / count_w) * 100
    index = 0.0588 * L - 0.296 * S - 15.8

# Format the result to one decimal place
formatted_index = round(index, 1)

if formatted_index < 1:
    print("Before Grade 1")
elif formatted_index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {formatted_index}")



