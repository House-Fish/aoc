#Inspiration https://github.com/fuglede/adventofcode/blob/master/2023/day01/solutions.py

file = open("input", "r")

solution = 0

replacements = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']

for line in file:
    val = ""
    
    for num, letter in enumerate(replacements, start=1):
        line = line.replace(letter, letter + str(num) + letter)

    for char in line:
        if char.isdigit():
            val += char
            break
    for char in line[::-1]:
        if char.isdigit():
            val += char
            break
    
    solution += int(val)

print(solution)