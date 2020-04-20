import csv
import sys

total_time = 0
with open(sys.argv[1]) as csvfile:
	reader = csv.reader(csvfile, delimiter=',')
	for row in reader:
		total_time += int(row[0]);

print('Total time: {}'.format(total_time))
