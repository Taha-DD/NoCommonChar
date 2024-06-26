string1 = set(input("enter first string: "))
string2 = set(input("enter second string: "))

str1 = ''.join(sorted(string1 - string2))
str2 = ''.join(sorted(string2 - string1))

print(f"the strings without commen characters: {str1, str2}")