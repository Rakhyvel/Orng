/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t* _0;
    uint8_t _1;
};

struct struct2 {
    uint64_t tag;
};

typedef struct struct2(*function0)(int64_t*, uint8_t);

/* Function forward definitions */
int64_t _5_main(void);
struct struct2 _7_f(int64_t* _7_x, uint8_t _7_fail);


/* Function definitions */
int64_t _5_main(void){
    int64_t _6_x;
    int64_t _6_y;
    function0 _5_t4;
    int64_t* _5_t6;
    uint8_t _5_t7;
    function0 _5_t9;
    int64_t* _5_t11;
    uint8_t _5_t12;
    int64_t _5_$retval;
    _6_x = 10;
    _6_y = 10;
    _5_t4 = (function0) _7_f;
    _5_t6 = &_6_x;
    _5_t7 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    (void) _5_t4(_5_t6, _5_t7);
    $line_idx--;
    _5_t9 = (function0) _7_f;
    _5_t11 = &_6_y;
    _5_t12 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _5_t9(_5_t11, _5_t12);
    $line_idx--;
    _5_$retval = $add_int64_t(_6_x, _6_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _5_$retval;
}

struct struct2 _7_f(int64_t* _7_x, uint8_t _7_fail){
    struct struct2 _7_$retval;
    *_7_x = 4;
    if (_7_fail) {
        goto BB6;
    } else {
        goto BB9;
    }
BB6:
    _7_$retval = (struct struct2) {.tag=1};
    *_7_x = 115;
    return _7_$retval;
BB9:
    _7_$retval = (struct struct2) {.tag=0};
    return _7_$retval;
}


int main(void) {
  printf("%ld",_5_main());
  return 0;
}
