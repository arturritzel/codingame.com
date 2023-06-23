def count_replaced_characters(line1, line2):
    replaced_count = 0
    for c1, c2 in zip(line1, reversed(line2)):
        if c1 != c2:
            replaced_count += 1
    return replaced_count

line_1 = input()
line_2 = input()

print(count_replaced_characters(line_1, line_2))
