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
int64_t _563_main(void);
struct struct2 _565_f(int64_t* _565_x, uint8_t _565_fail);


/* Function definitions */
int64_t _563_main(void){
    int64_t _564_x;
    int64_t _564_y;
    function0 _563_t2;
    int64_t* _563_t4;
    uint8_t _563_t5;
    function0 _563_t7;
    int64_t* _563_t9;
    uint8_t _563_t10;
    int64_t _563_$retval;
    _564_x = 10;
    _564_y = 10;
    _563_t2 = _565_f;
    _563_t4 = &_564_x;
    _563_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    (void) _563_t2(_563_t4, _563_t5);
    $line_idx--;
    _563_t7 = _565_f;
    _563_t9 = &_564_y;
    _563_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    (void) _563_t7(_563_t9, _563_t10);
    $line_idx--;
    _563_$retval = $add_int64_t(_564_x, _564_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _563_$retval;
}

struct struct2 _565_f(int64_t* _565_x, uint8_t _565_fail){
    struct struct2 _565_$retval;
    *_565_x = 4;
    if (_565_fail) {
        goto BB665;
    } else {
        goto BB668;
    }
BB665:
    _565_$retval = (struct struct2) {.tag=1};
    *_565_x = 115;
    return _565_$retval;
BB668:
    _565_$retval = (struct struct2) {.tag=0};
    return _565_$retval;
}


int main(void) {
  printf("%ld",_563_main());
  return 0;
}
