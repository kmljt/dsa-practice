def helper(chars, string, st, length):
    if len(string) == length:
        st.add(string)
        # print(string, len(st))
        return None

    for c in list(chars):
        string = string + c
        chars.remove(c)

        helper(chars, string, st, length)

        string = string[:-1]
        chars.append(c)


def all_substrings(s: str):
    chars = list(s)
    string = ""
    st = set()

    for length in range(1, len(s) + 1):
        helper(chars, string, st, length)

    print(sorted(st))
    return len(st)


def main():
    print(all_substrings("ccd"))

if __name__ == "__main__":
    main()
