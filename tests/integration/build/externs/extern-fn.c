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
int64_t _949_main(void);
void _951_print(struct struct1 _951_str);


/* Function definitions */
int64_t _949_main(void){
    function0 _949_t0;
    struct struct1 _949_t2;
    int64_t _949_$retval;
    _949_t0 = (function0) _951_print;
    _949_t2 = (struct struct1) {(uint8_t*)string_0, 2};
    $lines[$line_idx++] = "tests/integration/externs/extern-fn.orng:3:11:\n    print(\"32\")\n         ^";
    (void) _949_t0(_949_t2);
    $line_idx--;
    _949_$retval = 8;
    return _949_$retval;
}

void _951_print(struct struct1 _951_str){
    int64_t _953_i;
    uint8_t _951_t4;
    int64_t _951_t7;
    _953_i = 0;
    goto BB1129;
BB1129:
    _951_t4 = _953_i<_951_str._1;
    if (_951_t4) {
        goto BB1130;
    } else {
        return;
    }
BB1130:
    $lines[$line_idx++] = "tests/integration/externs/extern-fn.orng:11:21:\n        _ = putchar(str[i])    \n                   ^";
    $bounds_check(_953_i, _951_str._1, "tests/integration/externs/extern-fn.orng:11:21:\n        _ = putchar(str[i])    \n                   ^");
    (void) putchar(*((uint8_t*)_951_str._0 + _953_i));
    $line_idx--;
    _951_t7 = 1;
    _953_i = $add_int64_t(_953_i, _951_t7, "tests/integration/externs/extern-fn.orng:10:46:\n    while let mut i = 0; i < str.length; i += 1 {\n                                            ^");
    goto BB1129;
}


int main(void) {
  printf("%ld",_949_main());
  return 0;
}
