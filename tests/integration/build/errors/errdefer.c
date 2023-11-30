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
int64_t _464_main(void);
struct2 _466_f(int64_t* _466_x,uint8_t _466_fail);

/* Function definitions */
int64_t _464_main(void) {
    int64_t _465_x;
    int64_t _465_y;
    function0 _464_t2;
    int64_t* _464_t4;
    uint8_t _464_t5;
    struct2 _464_t3;
    function0 _464_t7;
    int64_t* _464_t9;
    uint8_t _464_t10;
    struct2 _464_t8;
    int64_t _464_$retval;
    _465_x = 10;
    _465_y = 10;
    _464_t2 = _466_f;
    _464_t4 = &_465_x;
    _464_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _464_t3 = _464_t2(_464_t4, _464_t5);
    $line_idx--;
    (void)_464_t3;
    _464_t7 = _466_f;
    _464_t9 = &_465_y;
    _464_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _464_t8 = _464_t7(_464_t9, _464_t10);
    $line_idx--;
    (void)_464_t8;
    _464_$retval = $add_int64_t(_465_x, _465_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _464_$retval;
}

struct2 _466_f(int64_t* _466_x,uint8_t _466_fail) {
    struct2 _466_$retval;
    *_466_x = 4;
    if (_466_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _466_$retval = (struct2) {.tag=1};
    *_466_x = 115;
    return _466_$retval;
BB4:
    _466_$retval = (struct2) {.tag=0};
    return _466_$retval;
}

int main(void) {
  printf("%ld",_464_main());
  return 0;
}
