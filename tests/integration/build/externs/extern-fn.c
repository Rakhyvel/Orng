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
int64_t _929_main(void);
void _931_print(struct struct1 _931_str);


/* Function definitions */
int64_t _929_main(void){
    function0 _929_t0;
    struct struct1 _929_t2;
    int64_t _929_$retval;
    _929_t0 = (function0) _931_print;
    _929_t2 = (struct struct1) {(uint8_t*)string_0, 2};
    $lines[$line_idx++] = "tests/integration/externs/extern-fn.orng:3:11:\n    print(\"32\")\n         ^";
    (void) _929_t0(_929_t2);
    $line_idx--;
    _929_$retval = 8;
    return _929_$retval;
}

void _931_print(struct struct1 _931_str){
    int64_t _933_i;
    uint8_t _931_t4;
    int64_t _931_t7;
    _933_i = 0;
    goto BB1110;
BB1110:
    _931_t4 = _933_i<_931_str._1;
    if (_931_t4) {
        goto BB1111;
    } else {
        return;
    }
BB1111:
    $lines[$line_idx++] = "tests/integration/externs/extern-fn.orng:11:21:\n        _ = putchar(str[i])    \n                   ^";
    $bounds_check(_933_i, _931_str._1, "tests/integration/externs/extern-fn.orng:11:21:\n        _ = putchar(str[i])    \n                   ^");
    (void) putchar(*((uint8_t*)_931_str._0 + _933_i));
    $line_idx--;
    _931_t7 = 1;
    _933_i = $add_int64_t(_933_i, _931_t7, "tests/integration/externs/extern-fn.orng:10:46:\n    while let mut i = 0; i < str.length; i += 1 {\n                                            ^");
    goto BB1110;
}


int main(void) {
  printf("%ld",_929_main());
  return 0;
}
