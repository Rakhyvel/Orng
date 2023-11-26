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
int64_t _289_main(void);
struct2 _291_f(int64_t* _291_x,uint8_t _291_fail);

/* Function definitions */
int64_t _289_main(void) {
    int64_t _290_z;
    int64_t _290_y;
    function0 _289_t2;
    int64_t* _289_t4;
    uint8_t _289_t5;
    struct2 _289_t3;
    function0 _289_t7;
    int64_t* _289_t9;
    uint8_t _289_t10;
    struct2 _289_t8;
    int64_t _289_$retval;
    _290_z = 10;
    _290_y = 10;
    _289_t2 = _291_f;
    _289_t4 = &_290_z;
    _289_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _289_t3 = _289_t2(_289_t4, _289_t5);
    $line_idx--;
    (void)_289_t3;
    _289_t7 = _291_f;
    _289_t9 = &_290_y;
    _289_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _289_t8 = _289_t7(_289_t9, _289_t10);
    $line_idx--;
    (void)_289_t8;
    _289_$retval = $add_int64_t(_290_z, _290_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _289_$retval;
}

struct2 _291_f(int64_t* _291_x,uint8_t _291_fail) {
    struct2 _291_t2;
    uint8_t _291_t4;
    struct2 _291_t1;
    uint64_t _291_t10;
    uint8_t _291_t11;
    struct2 _291_t7;
    uint8_t _291_t9;
    struct2 _291_$retval;
    int64_t _291_t12;
    int64_t _291_t5;
    *_291_x = 6;
    if (_291_fail) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _291_t2 = (struct2) {.tag=1};
    _291_t4 = 0;
    if (_291_t4) {
        goto BB3;
    } else {
        goto BB8;
    }
BB9:
    _291_t7 = (struct2) {.tag=0};
    _291_t9 = 1;
    if (_291_t9) {
        goto BB11;
    } else {
        goto BB7;
    }
BB3:
    _291_t1 = _291_t2;
    goto BB4;
BB8:
    _291_t5 = 100;
    *_291_x = $add_int64_t(*_291_x, _291_t5, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    goto BB7;
BB11:
    _291_t1 = _291_t7;
    goto BB4;
BB7:
    _291_t12 = 9;
    *_291_x = $add_int64_t(*_291_x, _291_t12, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _291_$retval;
BB4:
    _291_t10 = _291_t1.tag;
    _291_t11 = !_291_t10;
    if (_291_t11) {
        goto BB6;
    } else {
        goto BB7;
    }
BB6:
    _291_$retval = _291_t1;
    return _291_$retval;
}

int main(void) {
  printf("%ld",_289_main());
  return 0;
}
