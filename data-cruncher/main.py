import csv

filename = input("Enter CSV: ")

file = open(filename)

csvreader = csv.reader(file)

header = next(csvreader)
print(header)

rows = []
for row in csvreader:
    rows.append(row)
print(rows)

