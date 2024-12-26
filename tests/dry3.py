import argparse

def build_suffix_array(arr):
    """Build suffix array for a list of any comparable elements."""
    n = len(arr)
    # Initial ordering based on first element
    suffixes = list(range(n))
    # Use elements directly instead of ord()
    rank = list(arr)
    tmp = [0] * n
    k = 1

    # Create a sentinel value that's "smaller" than any real element
    # We'll use a custom class for this purpose
    class Sentinel:
        def __lt__(self, other): return True
        def __gt__(self, other): return False
        def __eq__(self, other): return isinstance(other, Sentinel)
        def __le__(self, other): return True
        def __ge__(self, other): return isinstance(other, Sentinel)

    SENTINEL = Sentinel()
    
    while k < n:
        # Use tuple comparison for stable sorting
        def suffix_key(x):
            # Handle boundary case for second element
            second = rank[x + k] if x + k < n else SENTINEL
            return (rank[x], second)

        # Sort based on current and next k elements
        suffixes.sort(key=suffix_key)
        
        # Update ranks
        tmp[suffixes[0]] = 0
        for i in range(1, n):
            prev = suffixes[i - 1]
            curr = suffixes[i]
            # Compare tuples for ranking
            if suffix_key(prev) == suffix_key(curr):
                tmp[curr] = tmp[prev]
            else:
                tmp[curr] = tmp[prev] + 1
        
        rank = tmp[:]
        k *= 2
    
    return suffixes

def build_lcp_array(arr, suffix_array):
    """Build LCP array for a list of any comparable elements."""
    n = len(arr)
    lcp = [0] * (n - 1)
    rank = [0] * n
    
    for i in range(n):
        rank[suffix_array[i]] = i
    
    k = 0
    for i in range(n):
        if rank[i] == n - 1:
            k = 0
            continue
        
        j = suffix_array[rank[i] + 1]
        # Compare elements directly
        while (i + k < n and j + k < n and 
               arr[i + k] == arr[j + k]):
            k += 1
        
        lcp[rank[i]] = k
        k = max(0, k - 1)
    
    return lcp

def find_longest_repeated_subsequence(arr, min_occurrences=3):
    """Find the longest subsequence that appears at least min_occurrences times."""
    if not arr:
        return []
    
    n = len(arr)
    suffix_array = build_suffix_array(arr)
    lcp_array = build_lcp_array(arr, suffix_array)
    
    def check_length(length):
        count = 1
        max_count = 1
        start_pos = None
        
        for i in range(n - 1):
            if lcp_array[i] >= length:
                count += 1
                if count > max_count:
                    max_count = count
                    start_pos = suffix_array[i]
            else:
                count = 1
        
        return max_count >= min_occurrences, start_pos
    
    # Binary search on the length of the subsequence
    left, right = 0, min(max(lcp_array) if lcp_array else 0, n)
    result = []
    result_start = None
    
    while left <= right:
        mid = (left + right) // 2
        is_valid, start_pos = check_length(mid)
        
        if is_valid:
            result = arr[start_pos:start_pos + mid]
            result_start = start_pos
            left = mid + 1
        else:
            right = mid - 1
    
    return result


def main():
    args = parse_args()

    with open(args.file) as f:
        text = f.read()
        scanner = Scanner(text)
        tokens = scanner.tokenize()
        result = find_longest_repeated_subsequence(tokens)
        print(result)



def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--file", help="file to DRY out")

    return parser.parse_args()


def alnumus(c):
    return c == "_" or c.isalnum()


keywords = [ # TODO: Add these to a text file, and read it in
    "fn",
    "if",
    "while",
    "for",
    "switch",
    "else",
    "break",
    "continue",
    "and",
    "or",
    "unreachable",
    "return",
    "pub",
    "const",
    "struct",
    "union",
    "true",
    "false",
    "try",
    "null",
    "catch",
    "orelse",
    "inline",
    "usingnamespace",
    "defer",
    "var",
    "comptime",
    "extern",
    "enum",
    "undefined",
]


class Scanner:
    def __init__(self, text):
        self.cursor = 0
        self.text = text

    def eof(self):
        return self.cursor >= len(self.text)

    def curr(self):
        return self.text[self.cursor]
    
    def curr_or_empty(self):
        return self.curr() if not self.eof() else ""

    def skip_while(self, filter):
        while not self.eof() and filter(self.curr()):
            self.cursor += 1

    def tokenize(self):
        open_close = "(){}[]"
        tokens = []
        prev_char = self.text[0]
        token = prev_char
        self.cursor += 1
        prev_token_was_dot = False
        while not self.eof():
            char = self.curr()
            
            if token[0] in {'"', "'"}:
                token += char
                if char == token[0]:
                    tokens.append(token)
                    self.skip_while(lambda x: x.isspace() or x == token[0])
                    token = self.curr_or_empty()
            elif (
                alnumus(char) != alnumus(prev_char)
                or char.isspace()
                or prev_char in open_close
                or char in open_close
                or char == '"'
            ):
                if token.startswith("//") :
                    self.skip_while(lambda x: self.curr() != "\n")
                elif all([alnumus(x) for x in token]) and token not in keywords and not prev_token_was_dot:
                    tokens.append('X')
                else:
                    prev_token_was_dot = '.' in token or token == 'fn'
                    tokens.append(token)
                self.skip_while(lambda x: x.isspace())
                token = self.curr_or_empty()
            else:
                token += char
            
            prev_char = self.curr_or_empty()
            self.cursor += 1
        # print(tokens)
        return tokens


if __name__ == "__main__":
    main()