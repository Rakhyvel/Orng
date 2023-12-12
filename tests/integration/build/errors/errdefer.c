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
int64_t _339_main(void);
struct2 _341_f(int64_t* _341_x,uint8_t _341_fail);

/* Function definitions */
int64_t _339_main(void) {
    int64_t _340_x;
    int64_t _340_y;
    function0 _339_t2;
    int64_t* _339_t4;
    uint8_t _339_t5;
    struct2 _339_t3;
    function0 _339_t7;
    int64_t* _339_t9;
    uint8_t _339_t10;
    struct2 _339_t8;
    int64_t _339_$retval;
    _340_x = 10;
    _340_y = 10;
    _339_t2 = _341_f;
    _339_t4 = &_340_x;
    _339_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _339_t3 = _339_t2(_339_t4, _339_t5);
    $line_idx--;
    (void)_339_t3;
    _339_t7 = _341_f;
    _339_t9 = &_340_y;
    _339_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _339_t8 = _339_t7(_339_t9, _339_t10);
    $line_idx--;
    (void)_339_t8;
    _339_$retval = $add_int64_t(_340_x, _340_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _339_$retval;
}

struct2 _341_f(int64_t* _341_x,uint8_t _341_fail) {
    struct2 _341_$retval;
    *_341_x = 4;
    if (_341_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _341_$retval = (struct2) {.tag=1};
    *_341_x = 115;
    return _341_$retval;
BB4:
    _341_$retval = (struct2) {.tag=0};
    return _341_$retval;
}

int main(void) {
  printf("%ld",_339_main());
  return 0;
}
