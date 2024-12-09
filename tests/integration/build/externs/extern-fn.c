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
int64_t _934_main(void);
void _936_print(struct struct1 _936_str);


/* Function definitions */
int64_t _934_main(void){
    function0 _934_t0;
    struct struct1 _934_t2;
    int64_t _934_$retval;
    _934_t0 = (function0) _936_print;
    _934_t2 = (struct struct1) {(uint8_t*)string_0, 2};
    $lines[$line_idx++] = "tests/integration/externs/extern-fn.orng:3:11:\n    print(\"32\")\n         ^";
    (void) _934_t0(_934_t2);
    $line_idx--;
    _934_$retval = 8;
    return _934_$retval;
}

void _936_print(struct struct1 _936_str){
    int64_t _938_i;
    uint8_t _936_t4;
    int64_t _936_t7;
    _938_i = 0;
    goto BB1113;
BB1113:
    _936_t4 = _938_i<_936_str._1;
    if (_936_t4) {
        goto BB1114;
    } else {
        return;
    }
BB1114:
    $lines[$line_idx++] = "tests/integration/externs/extern-fn.orng:11:21:\n        _ = putchar(str[i])    \n                   ^";
    $bounds_check(_938_i, _936_str._1, "tests/integration/externs/extern-fn.orng:11:21:\n        _ = putchar(str[i])    \n                   ^");
    (void) putchar(*((uint8_t*)_936_str._0 + _938_i));
    $line_idx--;
    _936_t7 = 1;
    _938_i = $add_int64_t(_938_i, _936_t7, "tests/integration/externs/extern-fn.orng:10:46:\n    while let mut i = 0; i < str.length; i += 1 {\n                                            ^");
    goto BB1113;
}


int main(void) {
  printf("%ld",_934_main());
  return 0;
}
