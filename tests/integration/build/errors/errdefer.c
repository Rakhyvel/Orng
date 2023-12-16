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
int64_t _493_main(void);
struct2 _495_f(int64_t* _495_x,uint8_t _495_fail);

/* Function definitions */
int64_t _493_main(void) {
    int64_t _494_x;
    int64_t _494_y;
    function0 _493_t2;
    int64_t* _493_t4;
    uint8_t _493_t5;
    struct2 _493_t3;
    function0 _493_t7;
    int64_t* _493_t9;
    uint8_t _493_t10;
    struct2 _493_t8;
    int64_t _493_$retval;
    _494_x = 10;
    _494_y = 10;
    _493_t2 = _495_f;
    _493_t4 = &_494_x;
    _493_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _493_t3 = _493_t2(_493_t4, _493_t5);
    $line_idx--;
    (void)_493_t3;
    _493_t7 = _495_f;
    _493_t9 = &_494_y;
    _493_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _493_t8 = _493_t7(_493_t9, _493_t10);
    $line_idx--;
    (void)_493_t8;
    _493_$retval = $add_int64_t(_494_x, _494_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _493_$retval;
}

struct2 _495_f(int64_t* _495_x,uint8_t _495_fail) {
    struct2 _495_$retval;
    *_495_x = 4;
    if (_495_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _495_$retval = (struct2) {.tag=1};
    *_495_x = 115;
    return _495_$retval;
BB4:
    _495_$retval = (struct2) {.tag=0};
    return _495_$retval;
}

int main(void) {
  printf("%ld",_493_main());
  return 0;
}
