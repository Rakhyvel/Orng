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
int64_t _441_main(void);
struct2 _443_f(int64_t* _443_x,uint8_t _443_fail);

/* Function definitions */
int64_t _441_main(void) {
    int64_t _442_x;
    int64_t _442_y;
    function0 _441_t2;
    int64_t* _441_t4;
    uint8_t _441_t5;
    struct2 _441_t3;
    function0 _441_t7;
    int64_t* _441_t9;
    uint8_t _441_t10;
    struct2 _441_t8;
    int64_t _441_$retval;
    _442_x = 10;
    _442_y = 10;
    _441_t2 = _443_f;
    _441_t4 = &_442_x;
    _441_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _441_t3 = _441_t2(_441_t4, _441_t5);
    $line_idx--;
    (void)_441_t3;
    _441_t7 = _443_f;
    _441_t9 = &_442_y;
    _441_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _441_t8 = _441_t7(_441_t9, _441_t10);
    $line_idx--;
    (void)_441_t8;
    _441_$retval = $add_int64_t(_442_x, _442_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _441_$retval;
}

struct2 _443_f(int64_t* _443_x,uint8_t _443_fail) {
    struct2 _443_$retval;
    *_443_x = 4;
    if (_443_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _443_$retval = (struct2) {.tag=1};
    *_443_x = 115;
    return _443_$retval;
BB4:
    _443_$retval = (struct2) {.tag=0};
    return _443_$retval;
}

int main(void) {
  printf("%ld",_441_main());
  return 0;
}
