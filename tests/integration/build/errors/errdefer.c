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
int64_t _279_main(void);
struct2 _281_f(int64_t* _281_x,uint8_t _281_fail);

/* Function definitions */
int64_t _279_main(void) {
    int64_t _280_x;
    int64_t _280_y;
    function0 _279_t2;
    int64_t* _279_t4;
    uint8_t _279_t5;
    struct2 _279_t3;
    function0 _279_t7;
    int64_t* _279_t9;
    uint8_t _279_t10;
    struct2 _279_t8;
    int64_t _279_$retval;
    _280_x = 10;
    _280_y = 10;
    _279_t2 = _281_f;
    _279_t4 = &_280_x;
    _279_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _279_t3 = _279_t2(_279_t4, _279_t5);
    $line_idx--;
    (void)_279_t3;
    _279_t7 = _281_f;
    _279_t9 = &_280_y;
    _279_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _279_t8 = _279_t7(_279_t9, _279_t10);
    $line_idx--;
    (void)_279_t8;
    _279_$retval = $add_int64_t(_280_x, _280_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _279_$retval;
}

struct2 _281_f(int64_t* _281_x,uint8_t _281_fail) {
    struct2 _281_$retval;
    *_281_x = 4;
    if (_281_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _281_$retval = (struct2) {.tag=1};
    *_281_x = 115;
    return _281_$retval;
BB4:
    _281_$retval = (struct2) {.tag=0};
    return _281_$retval;
}

int main(void) {
  printf("%ld",_279_main());
  return 0;
}
