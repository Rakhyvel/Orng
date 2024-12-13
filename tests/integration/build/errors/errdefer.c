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
int64_t _611_main(void);
struct struct2 _613_f(int64_t* _613_x, uint8_t _613_fail);


/* Function definitions */
int64_t _611_main(void){
    int64_t _612_x;
    int64_t _612_y;
    function0 _611_t4;
    int64_t* _611_t6;
    uint8_t _611_t7;
    function0 _611_t9;
    int64_t* _611_t11;
    uint8_t _611_t12;
    int64_t _611_$retval;
    _612_x = 10;
    _612_y = 10;
    _611_t4 = (function0) _613_f;
    _611_t6 = &_612_x;
    _611_t7 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    (void) _611_t4(_611_t6, _611_t7);
    $line_idx--;
    _611_t9 = (function0) _613_f;
    _611_t11 = &_612_y;
    _611_t12 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _611_t9(_611_t11, _611_t12);
    $line_idx--;
    _611_$retval = $add_int64_t(_612_x, _612_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _611_$retval;
}

struct struct2 _613_f(int64_t* _613_x, uint8_t _613_fail){
    struct struct2 _613_$retval;
    *_613_x = 4;
    if (_613_fail) {
        goto BB698;
    } else {
        goto BB701;
    }
BB698:
    _613_$retval = (struct struct2) {.tag=1};
    *_613_x = 115;
    return _613_$retval;
BB701:
    _613_$retval = (struct struct2) {.tag=0};
    return _613_$retval;
}


int main(void) {
  printf("%ld",_611_main());
  return 0;
}
