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
int64_t _594_main(void);
struct struct2 _596_f(int64_t* _596_x, uint8_t _596_fail);


/* Function definitions */
int64_t _594_main(void){
    int64_t _595_x;
    int64_t _595_y;
    function0 _594_t4;
    int64_t* _594_t6;
    uint8_t _594_t7;
    function0 _594_t9;
    int64_t* _594_t11;
    uint8_t _594_t12;
    int64_t _594_$retval;
    _595_x = 10;
    _595_y = 10;
    _594_t4 = (function0) _596_f;
    _594_t6 = &_595_x;
    _594_t7 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    (void) _594_t4(_594_t6, _594_t7);
    $line_idx--;
    _594_t9 = (function0) _596_f;
    _594_t11 = &_595_y;
    _594_t12 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _594_t9(_594_t11, _594_t12);
    $line_idx--;
    _594_$retval = $add_int64_t(_595_x, _595_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _594_$retval;
}

struct struct2 _596_f(int64_t* _596_x, uint8_t _596_fail){
    struct struct2 _596_$retval;
    *_596_x = 4;
    if (_596_fail) {
        goto BB680;
    } else {
        goto BB683;
    }
BB680:
    _596_$retval = (struct struct2) {.tag=1};
    *_596_x = 115;
    return _596_$retval;
BB683:
    _596_$retval = (struct struct2) {.tag=0};
    return _596_$retval;
}


int main(void) {
  printf("%ld",_594_main());
  return 0;
}
