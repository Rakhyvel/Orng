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
int64_t _590_main(void);
struct struct2 _592_f(int64_t* _592_x, uint8_t _592_fail);


/* Function definitions */
int64_t _590_main(void){
    int64_t _591_x;
    int64_t _591_y;
    function0 _590_t2;
    int64_t* _590_t4;
    uint8_t _590_t5;
    function0 _590_t7;
    int64_t* _590_t9;
    uint8_t _590_t10;
    int64_t _590_$retval;
    _591_x = 10;
    _591_y = 10;
    _590_t2 = _592_f;
    _590_t4 = &_591_x;
    _590_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    (void) _590_t2(_590_t4, _590_t5);
    $line_idx--;
    _590_t7 = _592_f;
    _590_t9 = &_591_y;
    _590_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _590_t7(_590_t9, _590_t10);
    $line_idx--;
    _590_$retval = $add_int64_t(_591_x, _591_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _590_$retval;
}

struct struct2 _592_f(int64_t* _592_x, uint8_t _592_fail){
    struct struct2 _592_$retval;
    *_592_x = 4;
    if (_592_fail) {
        goto BB687;
    } else {
        goto BB690;
    }
BB687:
    _592_$retval = (struct struct2) {.tag=1};
    *_592_x = 115;
    return _592_$retval;
BB690:
    _592_$retval = (struct struct2) {.tag=0};
    return _592_$retval;
}


int main(void) {
  printf("%ld",_590_main());
  return 0;
}
