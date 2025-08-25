def get_string_permutations(string, step=0):
    if step == len(string):
        return {"".join(string)}
    
    permutations = set()
    for i in range(step, len(string)):
        str_copy = [c for c in string]
        str_copy[step], str_copy[i] = str_copy[i], str_copy[step]
        permutations |= get_string_permutations(str_copy, step + 1)
    
    return permutations

input_str = input("Enter string: ")
result = list(get_string_permutations(input_str))
print(result)
