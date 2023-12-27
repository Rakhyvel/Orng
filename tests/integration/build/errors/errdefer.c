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
int64_t _554_main(void);
struct2 _556_f(int64_t* _556_x,uint8_t _556_fail);

/* Function definitions */
int64_t _554_main(void){
    int64_t _555_x;
    int64_t _555_y;
    function0 _554_t2;
    int64_t* _554_t4;
    uint8_t _554_t5;
    struct2 _554_t3;
    function0 _554_t7;
    int64_t* _554_t9;
    uint8_t _554_t10;
    struct2 _554_t8;
    int64_t _554_$retval;
    _555_x = 10;
    _555_y = 10;
    _554_t2 = _556_f;
    _554_t4 = &_555_x;
    _554_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _554_t3 = _554_t2(_554_t4, _554_t5);
    $line_idx--;
    (void)_554_t3;
    _554_t7 = _556_f;
    _554_t9 = &_555_y;
    _554_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _554_t8 = _554_t7(_554_t9, _554_t10);
    $line_idx--;
    (void)_554_t8;
    _554_$retval = $add_int64_t(_555_x, _555_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _554_$retval;
}

struct2 _556_f(int64_t* _556_x,uint8_t _556_fail){
    struct2 _556_$retval;
    *_556_x = 4;
    if (_556_fail) {
        goto BB665;
    } else {
        goto BB668;
    }
BB665:
    _556_$retval = (struct2) {.tag=1};
    *_556_x = 115;
    return _556_$retval;
BB668:
    _556_$retval = (struct2) {.tag=0};
    return _556_$retval;
}

int main(void) {
  printf("%ld",_554_main());
  return 0;
}
