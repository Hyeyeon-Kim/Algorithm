import re

s = input()

if re.fullmatch('(pi|ka|chu)+', s):
	print("YES")
else:
	print("NO")