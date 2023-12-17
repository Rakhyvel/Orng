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
int64_t _701_main(void);
struct2 _703_f(int64_t* _703_x,uint8_t _703_fail);

/* Function definitions */
int64_t _701_main(void){
    int64_t _702_z;
    int64_t _702_y;
    function0 _701_t2;
    int64_t* _701_t4;
    uint8_t _701_t5;
    struct2 _701_t3;
    function0 _701_t7;
    int64_t* _701_t9;
    uint8_t _701_t10;
    struct2 _701_t8;
    int64_t _701_$retval;
    _702_z = 10;
    _702_y = 10;
    _701_t2 = _703_f;
    _701_t4 = &_702_z;
    _701_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _701_t3 = _701_t2(_701_t4, _701_t5);
    $line_idx--;
    (void)_701_t3;
    _701_t7 = _703_f;
    _701_t9 = &_702_y;
    _701_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _701_t8 = _701_t7(_701_t9, _701_t10);
    $line_idx--;
    (void)_701_t8;
    _701_$retval = $add_int64_t(_702_z, _702_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _701_$retval;
}

struct2 _703_f(int64_t* _703_x,uint8_t _703_fail){
    struct2 _703_$retval;
    int64_t _703_t6;
    int64_t _703_t14;
    *_703_x = 6;
    if (_703_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    _703_t6 = 100;
    *_703_x = $add_int64_t(*_703_x, _703_t6, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _703_t14 = 9;
    *_703_x = $add_int64_t(*_703_x, _703_t14, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _703_$retval;
BB9:
    _703_$retval = (struct2) {.tag=0};
    return _703_$retval;
}

int main(void) {
  printf("%ld",_701_main());
  return 0;
}
