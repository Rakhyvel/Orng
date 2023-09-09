# This script gets the source-to-output ratio, which helps determine where to optimize

import sys
import os
import random

file_extensions = {
    "python" : {".py"},
    "javascript" : {".js"},
    "typescript" : {".js", ".ts"},
    "go" : {".go"},
    "c++" : {".cpp", ".hpp", ".c", ".h"},
    "rust" : {".rs"},
    "java" : {".java"},
    "c#" : {".cs"},
    "kotlin" : {".kt"},
    "c": {".c", ".h"},
    "php" : {"php"},
    "typescript" : {".ts"},
    "swift" : {".swift"},
    "zig" : {".zig"},
    "julia" : {".jl"},
    "scala" : {".scala"},
    "elixir" : {".ex"},
    "ruby" : {".rb"},
    "blade" : {".b"},
    "pascal" : {".pas"},
    "prolog" : {".pl"},
    "nim" : {".nim"},
    "groovy" : {".groovy"},
    "visual_basic" : {".vb"},
    "ocaml" : {".ml"},
    "haskell" : {".hs"},
    "fortran" : {".F"},
    "f#" : {".fs"},
    "clojure" : {".cj"},
    "perl" : {".pl"},
    "odin" : {".odin"},
    "crystal" : {".cr"},
    "tcl" : {".tcl"},
    "smalltalk" : {".st"},
    "lisp" : {".lisp"},
    "objective-c" : {".m", ".h"},
    "ada" : {".ads", ".adb"},
    "haxe" : {".hx"},
    "racket" : {".rkt"},
    "erlang" : {".erl"},
    "sml" : {".ml"},
    "d" : {".d"},
    "scheme" : {".scm"},
    "orng" : {".orng"},
}

line_comment = {
    "python" : "#",
    "go" : "//",
    "c++" : "//",
    "rust" : "//",
    "java" : "//",
    "c" : "//",
    "zig" : "//",
    "orng" : "//",
}

block_comment_begin = {
    "python" : '"""',
    "go" : "/*",
    "c++" : "/*",
    "rust" : "/*",
    "java" : "/*",
    "c" : "/*"
}

block_comment_end = {
    "python" : '"""',
    "go" : "*/",
    "c++" : "*/",
    "rust" : "*/",
    "java" : "*/",
    "c" : "*/"
}

string_delimiter = {
    "python" : "'",
    "go" : '"',
    "c++" : '"',
    "rust" : '"',
    "java" : '"',
    "c" : '"',
    "zig" : '"',
    "orng" : '"',
}

class File:
    def __init__(self, file_name, sloc, tokens):
        self.file_name = file_name
        self.sloc = sloc
        self.tokens = tokens

 
# Get the list of all files and directories
def read_files(dir, lang)->list[File]:
    files = []
    try:
        dir_list = os.listdir(dir)
    except:
        return files
    for file_name in dir_list:
        if os.path.isdir(dir + "/" + file_name):
            # Directory
            files += read_files(dir + "/" + file_name, lang)
        else:
            # File
            ext_set = file_extensions[lang]
            for ext in ext_set:
                if file_name.endswith(ext):
                    files.append(read_file(dir + "/" + file_name, lang))
    return files

def get_char_class(c:str):
    if c.isalnum() or c == "_":
        return 0
    elif c in {"\n", "(", ")", "[", "]", "{", "}", "\"", "'", "`"}:
        return random.randint(3, 100000000000)
    elif c.isspace():
        return 1
    else:
        return 2


def read_file(file_name, lang)->File:
    sloc = 1
    tokens = 0
    try:
        with open(file_name) as f:
            line = f.read()
    except:
        print(f"Could not find {lang} file {file_name}")
        return

    token_list:list[str] = []
    data = line[0]
    past_c = line[0]
    count = 1
    for c in line[1:]:
        if get_char_class(c) != get_char_class(past_c) or c == "\n":
            if c == "\n":
                count += 1
            token_list.append(data)
            data = ""
        if (not c.isspace()) or c == "\n":
            data += c
        past_c = c
    token_list.append(data)

    in_line_comment = False
    in_block_comment = False
    in_string = False
    prev_wasnt_newline = False
    for t in token_list:
        if in_line_comment:
            if t == "\n":
                in_line_comment = False
        elif in_block_comment:
            if block_comment_end[lang] in t:
                in_block_comment = False
        elif in_string:
            if string_delimiter[lang] in t:
                in_string = False
        elif t.startswith(line_comment[lang]) or t.endswith(line_comment[lang]):
            in_line_comment = True
        elif lang in block_comment_begin and t.startswith(block_comment_begin[lang]):
            in_block_comment = True
        elif t.startswith(string_delimiter[lang]):
            in_string = True
            tokens += 1
        else:
            if not t.isspace() and len(t) > 0:
                tokens += 1
            if prev_wasnt_newline and t == "\n":
                sloc += 1
        prev_wasnt_newline = t != "\n"

    return File(file_name, sloc, tokens)
    

def main():
    integration_dir = "tests/integration/"
    build_dir = integration_dir + "build"
    lang = "c"

    # Get list of C files in tests/integration/build
    files = read_files(build_dir, lang)

    file_list = []
    for file in files:
        corresponding_orng_filename = integration_dir + file.file_name[24:-2] + ".orng"
        corresponding_orng = read_file(corresponding_orng_filename, "orng")
        if corresponding_orng:
            file_list.append((corresponding_orng.file_name, file.sloc / corresponding_orng.sloc, file.file_name))
    file_list.sort(key = lambda x: x[1])
    for file in file_list:
        print(file[2][24:-2], file[1])

if __name__ == "__main__":
    main()