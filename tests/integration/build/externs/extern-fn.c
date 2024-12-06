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
int64_t _8_main(void);
void _10_print(struct struct1 _10_str);


/* Function definitions */
int64_t _8_main(void){
    function0 _8_t0;
    struct struct1 _8_t2;
    int64_t _8_$retval;
    _8_t0 = (function0) _10_print;
    _8_t2 = (struct struct1) {(uint8_t*)string_0, 2};
    $lines[$line_idx++] = "tests/integration/externs/extern-fn.orng:3:11:\n    print(\"32\")\n         ^";
    (void) _8_t0(_8_t2);
    $line_idx--;
    _8_$retval = 8;
    return _8_$retval;
}

void _10_print(struct struct1 _10_str){
    int64_t _12_i;
    uint8_t _10_t4;
    int64_t _10_t7;
    _12_i = 0;
    goto BB10;
BB10:
    _10_t4 = _12_i<_10_str._1;
    if (_10_t4) {
        goto BB11;
    } else {
        return;
    }
BB11:
    $lines[$line_idx++] = "tests/integration/externs/extern-fn.orng:11:21:\n        _ = putchar(str[i])    \n                   ^";
    $bounds_check(_12_i, _10_str._1, "tests/integration/externs/extern-fn.orng:11:21:\n        _ = putchar(str[i])    \n                   ^");
    (void) putchar(*((uint8_t*)_10_str._0 + _12_i));
    $line_idx--;
    _10_t7 = 1;
    _12_i = $add_int64_t(_12_i, _10_t7, "tests/integration/externs/extern-fn.orng:10:46:\n    while let mut i = 0; i < str.length; i += 1 {\n                                            ^");
    goto BB10;
}


int main(void) {
  printf("%ld",_8_main());
  return 0;
}
