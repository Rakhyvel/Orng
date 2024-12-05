/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    uint8_t* _0;
    int64_t _1;
};

typedef int64_t(*function1)(struct struct0);

/* Interned Strings */
char* string_0 = "\x48\x65\x6C\x6C\x6F";

/* Function forward definitions */
int64_t _1476_main(void);
int64_t _1478_get_length(struct struct0 _1478_s);


/* Function definitions */
int64_t _1476_main(void){
    struct struct0 _1477_x;
    struct struct0 _1477_y;
    function1 _1476_t4;
    int64_t _1476_t5;
    function1 _1476_t6;
    int64_t _1476_t7;
    int64_t _1476_t8;
    int64_t _1476_t9;
    int64_t _1476_$retval;
    _1477_x = (struct struct0) {(uint8_t*)string_0, 5};
    _1477_y = (struct struct0) {(uint8_t*)string_0, 5};
    _1476_t4 = (function1) _1478_get_length;
    $lines[$line_idx++] = "tests/integration/strings/interning.orng:5:16:\n    get_length(x) + get_length(y) + 296\n              ^";
    _1476_t5 = _1476_t4(_1477_x);
    $line_idx--;
    _1476_t6 = (function1) _1478_get_length;
    $lines[$line_idx++] = "tests/integration/strings/interning.orng:5:32:\n    get_length(x) + get_length(y) + 296\n                              ^";
    _1476_t7 = _1476_t6(_1477_y);
    $line_idx--;
    _1476_t8 = $add_int64_t(_1476_t5, _1476_t7, "tests/integration/strings/interning.orng:5:20:\n    get_length(x) + get_length(y) + 296\n                  ^");
    _1476_t9 = 296;
    _1476_$retval = $add_int64_t(_1476_t8, _1476_t9, "tests/integration/strings/interning.orng:5:36:\n    get_length(x) + get_length(y) + 296\n                                  ^");
    return _1476_$retval;
}

int64_t _1478_get_length(struct struct0 _1478_s){
    int64_t _1478_$retval;
    goto BB1715;
BB1715:
    _1478_$retval = _1478_s._1;
    return _1478_$retval;
}


int main(void) {
  printf("%ld",_1476_main());
  return 0;
}
