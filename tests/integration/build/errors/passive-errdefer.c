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
int64_t _607_main(void);
struct struct2 _609_f(int64_t* _609_x, uint8_t _609_fail);


/* Function definitions */
int64_t _607_main(void){
    int64_t _608_z;
    int64_t _608_y;
    function0 _607_t2;
    int64_t* _607_t4;
    uint8_t _607_t5;
    function0 _607_t7;
    int64_t* _607_t9;
    uint8_t _607_t10;
    int64_t _607_$retval;
    _608_z = 10;
    _608_y = 10;
    _607_t2 = _609_f;
    _607_t4 = &_608_z;
    _607_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    (void) _607_t2(_607_t4, _607_t5);
    $line_idx--;
    _607_t7 = _609_f;
    _607_t9 = &_608_y;
    _607_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _607_t7(_607_t9, _607_t10);
    $line_idx--;
    _607_$retval = $add_int64_t(_608_z, _608_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _607_$retval;
}

struct struct2 _609_f(int64_t* _609_x, uint8_t _609_fail){
    struct struct2 _609_$retval;
    int64_t _609_t5;
    int64_t _609_t12;
    *_609_x = 6;
    if (_609_fail) {
        goto BB732;
    } else {
        goto BB733;
    }
BB732:
    _609_t5 = 100;
    *_609_x = $add_int64_t(*_609_x, _609_t5, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _609_t12 = 9;
    *_609_x = $add_int64_t(*_609_x, _609_t12, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _609_$retval;
BB733:
    _609_$retval = (struct struct2) {.tag=0};
    return _609_$retval;
}


int main(void) {
  printf("%ld",_607_main());
  return 0;
}
