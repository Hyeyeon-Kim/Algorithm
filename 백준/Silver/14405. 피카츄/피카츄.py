import re

s = input()
s = re.sub('pi|ka|chu','',s)

# print(s)
if not s:
	print("YES")
else:
	print("NO")