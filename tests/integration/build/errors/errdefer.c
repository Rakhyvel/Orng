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
int64_t _609_main(void);
struct struct2 _611_f(int64_t* _611_x, uint8_t _611_fail);


/* Function definitions */
int64_t _609_main(void){
    int64_t _610_x;
    int64_t _610_y;
    function0 _609_t4;
    int64_t* _609_t6;
    uint8_t _609_t7;
    function0 _609_t9;
    int64_t* _609_t11;
    uint8_t _609_t12;
    int64_t _609_$retval;
    _610_x = 10;
    _610_y = 10;
    _609_t4 = (function0) _611_f;
    _609_t6 = &_610_x;
    _609_t7 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    (void) _609_t4(_609_t6, _609_t7);
    $line_idx--;
    _609_t9 = (function0) _611_f;
    _609_t11 = &_610_y;
    _609_t12 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _609_t9(_609_t11, _609_t12);
    $line_idx--;
    _609_$retval = $add_int64_t(_610_x, _610_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _609_$retval;
}

struct struct2 _611_f(int64_t* _611_x, uint8_t _611_fail){
    struct struct2 _611_$retval;
    *_611_x = 4;
    if (_611_fail) {
        goto BB696;
    } else {
        goto BB699;
    }
BB696:
    _611_$retval = (struct struct2) {.tag=1};
    *_611_x = 115;
    return _611_$retval;
BB699:
    _611_$retval = (struct struct2) {.tag=0};
    return _611_$retval;
}


int main(void) {
  printf("%ld",_609_main());
  return 0;
}
