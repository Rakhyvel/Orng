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
int64_t _248_main(void);
struct2 _250_f(int64_t* _250_x,uint8_t _250_fail);

/* Function definitions */
int64_t _248_main(void) {
    int64_t _249_x;
    int64_t _249_y;
    function0 _248_t2;
    int64_t* _248_t4;
    uint8_t _248_t5;
    struct2 _248_t3;
    function0 _248_t7;
    int64_t* _248_t9;
    uint8_t _248_t10;
    struct2 _248_t8;
    int64_t _248_$retval;
    _249_x = 10;
    _249_y = 10;
    _248_t2 = _250_f;
    _248_t4 = &_249_x;
    _248_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _248_t3 = _248_t2(_248_t4, _248_t5);
    $line_idx--;
    (void)_248_t3;
    _248_t7 = _250_f;
    _248_t9 = &_249_y;
    _248_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _248_t8 = _248_t7(_248_t9, _248_t10);
    $line_idx--;
    (void)_248_t8;
    _248_$retval = $add_int64_t(_249_x, _249_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _248_$retval;
}

struct2 _250_f(int64_t* _250_x,uint8_t _250_fail) {
    struct2 _250_$retval;
    uint8_t _250_t4;
    uint8_t _250_t7;
    *_250_x = 4;
    if (_250_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _250_$retval = (struct2) {.tag=1};
    _250_t4 = 0;
    if (_250_t4) {
        return _250_$retval;
    } else {
        goto BB3;
    }
BB4:
    _250_$retval = (struct2) {.tag=0};
    _250_t7 = 1;
    if (_250_t7) {
        return _250_$retval;
    } else {
        goto BB3;
    }
BB3:
    *_250_x = 115;
    return _250_$retval;
}

int main(void) {
  printf("%ld",_248_main());
  return 0;
}
