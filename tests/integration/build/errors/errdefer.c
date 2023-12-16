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
int64_t _512_main(void);
struct2 _514_f(int64_t* _514_x,uint8_t _514_fail);

/* Function definitions */
int64_t _512_main(void){
    int64_t _513_x;
    int64_t _513_y;
    function0 _512_t2;
    int64_t* _512_t4;
    uint8_t _512_t5;
    struct2 _512_t3;
    function0 _512_t7;
    int64_t* _512_t9;
    uint8_t _512_t10;
    struct2 _512_t8;
    int64_t _512_$retval;
    _513_x = 10;
    _513_y = 10;
    _512_t2 = _514_f;
    _512_t4 = &_513_x;
    _512_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    _512_t3 = _512_t2(_512_t4, _512_t5);
    $line_idx--;
    (void)_512_t3;
    _512_t7 = _514_f;
    _512_t9 = &_513_y;
    _512_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _512_t8 = _512_t7(_512_t9, _512_t10);
    $line_idx--;
    (void)_512_t8;
    _512_$retval = $add_int64_t(_513_x, _513_y, "tests/integration/errors/errdefer.orng:7:8:\n    x + y\n      ^");
    return _512_$retval;
}

struct2 _514_f(int64_t* _514_x,uint8_t _514_fail){
    struct2 _514_$retval;
    *_514_x = 4;
    if (_514_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _514_$retval = (struct2) {.tag=1};
    *_514_x = 115;
    return _514_$retval;
BB4:
    _514_$retval = (struct2) {.tag=0};
    return _514_$retval;
}

int main(void) {
  printf("%ld",_512_main());
  return 0;
}
