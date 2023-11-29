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
int64_t _351_main(void);
struct2 _353_f(int64_t* _353_x,uint8_t _353_fail);

/* Function definitions */
int64_t _351_main(void) {
    int64_t _352_x;
    int64_t _352_y;
    function0 _351_t2;
    int64_t* _351_t4;
    uint8_t _351_t5;
    struct2 _351_t3;
    function0 _351_t7;
    int64_t* _351_t9;
    uint8_t _351_t10;
    struct2 _351_t8;
    int64_t _351_$retval;
    _352_x = 10;
    _352_y = 10;
    _351_t2 = _353_f;
    _351_t4 = &_352_x;
    _351_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _351_t3 = _351_t2(_351_t4, _351_t5);
    $line_idx--;
    (void)_351_t3;
    _351_t7 = _353_f;
    _351_t9 = &_352_y;
    _351_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _351_t8 = _351_t7(_351_t9, _351_t10);
    $line_idx--;
    (void)_351_t8;
    _351_$retval = $add_int64_t(_352_x, _352_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _351_$retval;
}

struct2 _353_f(int64_t* _353_x,uint8_t _353_fail) {
    struct2 _353_$retval;
    *_353_x = 4;
    if (_353_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _353_$retval = (struct2) {.tag=1};
    *_353_x = 115;
    return _353_$retval;
BB4:
    _353_$retval = (struct2) {.tag=0};
    return _353_$retval;
}

int main(void) {
  printf("%ld",_351_main());
  return 0;
}
