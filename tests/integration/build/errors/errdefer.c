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

typedef struct2(*function0)(    int64_t*,     uint8_t);

/* Function forward definitions */
int64_t _5_main(void);
struct2 _7_f(int64_t* _7_x,uint8_t _7_fail);

/* Function definitions */
int64_t _5_main(void) {
    int64_t _6_x;
    int64_t _6_y;
    function0 _5_t2;
    int64_t* _5_t4;
    uint8_t _5_t5;
    struct2 _5_t3;
    function0 _5_t7;
    int64_t* _5_t9;
    uint8_t _5_t10;
    struct2 _5_t8;
    int64_t _5_$retval;
    _6_x = 10;
    _6_y = 10;
    _5_t2 = _7_f;
    _5_t4 = &_6_x;
    _5_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _5_t3 = _5_t2(_5_t4, _5_t5);
    $line_idx--;
    (void)_5_t3;
    _5_t7 = _7_f;
    _5_t9 = &_6_y;
    _5_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _5_t8 = _5_t7(_5_t9, _5_t10);
    $line_idx--;
    (void)_5_t8;
    _5_$retval = $add_int64_t(_6_x, _6_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _5_$retval;
}

struct2 _7_f(int64_t* _7_x,uint8_t _7_fail) {
    struct2 _7_$retval;
    uint8_t _7_t4;
    uint8_t _7_t7;
    *_7_x = 4;
    if (_7_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _7_$retval = (struct2) {.tag=1};
    _7_t4 = 0;
    if (_7_t4) {
        return _7_$retval;
    } else {
        goto BB3;
    }
BB4:
    _7_$retval = (struct2) {.tag=0};
    _7_t7 = 1;
    if (_7_t7) {
        return _7_$retval;
    } else {
        goto BB3;
    }
BB3:
    *_7_x = 115;
    return _7_$retval;
}

int main(void) {
  printf("%ld",_5_main());
  return 0;
}
