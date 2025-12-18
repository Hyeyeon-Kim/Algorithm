import re 

n = int(input())

for i in range(n):
	s = input()

	if re.fullmatch('^[A-F]?A+F+C+[A-F]*$',s):
		print("Infected!")
	else:
		print("Good")