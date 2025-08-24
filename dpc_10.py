def sort_string(s: str) -> str:
    return ''.join(sorted(s))

strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
groups = {}
for i in strs:
    key = ''.join(sorted(i))
    if key not in groups:
        groups[key] = []
    groups[key].append(i)

output = list(groups.values())
print(output)

    
