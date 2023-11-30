/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    uint8_t _1;
} struct1;

typedef struct {
    uint64_t tag;
} struct2;

typedef struct2(*function0)(int64_t*, uint8_t);

/* Function forward definitions */
int64_t _487_main(void);
struct2 _489_f(int64_t* _489_x,uint8_t _489_fail);

/* Function definitions */
int64_t _487_main(void) {
    int64_t _488_z;
    int64_t _488_y;
    function0 _487_t2;
    int64_t* _487_t4;
    uint8_t _487_t5;
    struct2 _487_t3;
    function0 _487_t7;
    int64_t* _487_t9;
    uint8_t _487_t10;
    struct2 _487_t8;
    int64_t _487_$retval;
    _488_z = 10;
    _488_y = 10;
    _487_t2 = _489_f;
    _487_t4 = &_488_z;
    _487_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _487_t3 = _487_t2(_487_t4, _487_t5);
    $line_idx--;
    (void)_487_t3;
    _487_t7 = _489_f;
    _487_t9 = &_488_y;
    _487_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _487_t8 = _487_t7(_487_t9, _487_t10);
    $line_idx--;
    (void)_487_t8;
    _487_$retval = $add_int64_t(_488_z, _488_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _487_$retval;
}

struct2 _489_f(int64_t* _489_x,uint8_t _489_fail) {
    struct2 _489_$retval;
    int64_t _489_t5;
    int64_t _489_t12;
    *_489_x = 6;
    if (_489_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    _489_t5 = 100;
    *_489_x = $add_int64_t(*_489_x, _489_t5, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _489_t12 = 9;
    *_489_x = $add_int64_t(*_489_x, _489_t12, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _489_$retval;
BB9:
    _489_$retval = (struct2) {.tag=0};
    return _489_$retval;
}

int main(void) {
  printf("%ld",_487_main());
  return 0;
}
