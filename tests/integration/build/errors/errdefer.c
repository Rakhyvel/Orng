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
int64_t _462_main(void);
struct2 _464_f(int64_t* _464_x,uint8_t _464_fail);

/* Function definitions */
int64_t _462_main(void) {
    int64_t _463_x;
    int64_t _463_y;
    function0 _462_t2;
    int64_t* _462_t4;
    uint8_t _462_t5;
    struct2 _462_t3;
    function0 _462_t7;
    int64_t* _462_t9;
    uint8_t _462_t10;
    struct2 _462_t8;
    int64_t _462_$retval;
    _463_x = 10;
    _463_y = 10;
    _462_t2 = _464_f;
    _462_t4 = &_463_x;
    _462_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _462_t3 = _462_t2(_462_t4, _462_t5);
    $line_idx--;
    (void)_462_t3;
    _462_t7 = _464_f;
    _462_t9 = &_463_y;
    _462_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _462_t8 = _462_t7(_462_t9, _462_t10);
    $line_idx--;
    (void)_462_t8;
    _462_$retval = $add_int64_t(_463_x, _463_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _462_$retval;
}

struct2 _464_f(int64_t* _464_x,uint8_t _464_fail) {
    struct2 _464_$retval;
    *_464_x = 4;
    if (_464_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _464_$retval = (struct2) {.tag=1};
    *_464_x = 115;
    return _464_$retval;
BB4:
    _464_$retval = (struct2) {.tag=0};
    return _464_$retval;
}

int main(void) {
  printf("%ld",_462_main());
  return 0;
}
