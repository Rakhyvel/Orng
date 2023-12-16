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
int64_t _501_main(void);
struct2 _503_f(int64_t* _503_x,uint8_t _503_fail);

/* Function definitions */
int64_t _501_main(void){
    int64_t _502_x;
    int64_t _502_y;
    function0 _501_t2;
    int64_t* _501_t4;
    uint8_t _501_t5;
    struct2 _501_t3;
    function0 _501_t7;
    int64_t* _501_t9;
    uint8_t _501_t10;
    struct2 _501_t8;
    int64_t _501_$retval;
    _502_x = 10;
    _502_y = 10;
    _501_t2 = _503_f;
    _501_t4 = &_502_x;
    _501_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _501_t3 = _501_t2(_501_t4, _501_t5);
    $line_idx--;
    (void)_501_t3;
    _501_t7 = _503_f;
    _501_t9 = &_502_y;
    _501_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _501_t8 = _501_t7(_501_t9, _501_t10);
    $line_idx--;
    (void)_501_t8;
    _501_$retval = $add_int64_t(_502_x, _502_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _501_$retval;
}

struct2 _503_f(int64_t* _503_x,uint8_t _503_fail){
    struct2 _503_$retval;
    *_503_x = 4;
    if (_503_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _503_$retval = (struct2) {.tag=1};
    *_503_x = 115;
    return _503_$retval;
BB4:
    _503_$retval = (struct2) {.tag=0};
    return _503_$retval;
}

int main(void) {
  printf("%ld",_501_main());
  return 0;
}
