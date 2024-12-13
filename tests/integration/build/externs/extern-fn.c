/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    uint8_t* _0;
    int64_t _1;
};

typedef void(*function0)(struct struct1);

/* Interned Strings */
char* string_0 = "\x33\x32";

/* Function forward definitions */
int64_t _951_main(void);
void _953_print(struct struct1 _953_str);


/* Function definitions */
int64_t _951_main(void){
    function0 _951_t0;
    struct struct1 _951_t2;
    int64_t _951_$retval;
    _951_t0 = (function0) _953_print;
    _951_t2 = (struct struct1) {(uint8_t*)string_0, 2};
    $lines[$line_idx++] = "tests/integration/externs/extern-fn.orng:3:11:\n    print(\"32\")\n         ^";
    (void) _951_t0(_951_t2);
    $line_idx--;
    _951_$retval = 8;
    return _951_$retval;
}

void _953_print(struct struct1 _953_str){
    int64_t _955_i;
    uint8_t _953_t4;
    int64_t _953_t7;
    _955_i = 0;
    goto BB1131;
BB1131:
    _953_t4 = _955_i<_953_str._1;
    if (_953_t4) {
        goto BB1132;
    } else {
        return;
    }
BB1132:
    $lines[$line_idx++] = "tests/integration/externs/extern-fn.orng:11:21:\n        _ = putchar(str[i])    \n                   ^";
    $bounds_check(_955_i, _953_str._1, "tests/integration/externs/extern-fn.orng:11:21:\n        _ = putchar(str[i])    \n                   ^");
    (void) putchar(*((uint8_t*)_953_str._0 + _955_i));
    $line_idx--;
    _953_t7 = 1;
    _955_i = $add_int64_t(_955_i, _953_t7, "tests/integration/externs/extern-fn.orng:10:46:\n    while let mut i = 0; i < str.length; i += 1 {\n                                            ^");
    goto BB1131;
}


int main(void) {
  printf("%ld",_951_main());
  return 0;
}
