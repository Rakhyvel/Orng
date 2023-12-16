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
int64_t _616_main(void);
struct2 _618_f(int64_t* _618_x,uint8_t _618_fail);

/* Function definitions */
int64_t _616_main(void){
    int64_t _617_z;
    int64_t _617_y;
    function0 _616_t2;
    int64_t* _616_t4;
    uint8_t _616_t5;
    struct2 _616_t3;
    function0 _616_t7;
    int64_t* _616_t9;
    uint8_t _616_t10;
    struct2 _616_t8;
    int64_t _616_$retval;
    _617_z = 10;
    _617_y = 10;
    _616_t2 = _618_f;
    _616_t4 = &_617_z;
    _616_t5 = 1;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:11:\n    _ = f(&mut z, true)\n         ^";
    _616_t3 = _616_t2(_616_t4, _616_t5);
    $line_idx--;
    (void)_616_t3;
    _616_t7 = _618_f;
    _616_t9 = &_617_y;
    _616_t10 = 0;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    _616_t8 = _616_t7(_616_t9, _616_t10);
    $line_idx--;
    (void)_616_t8;
    _616_$retval = $add_int64_t(_617_z, _617_y, "tests/integration/errors/passive-errdefer.orng:7:8:\n    z + y\n      ^");
    return _616_$retval;
}

struct2 _618_f(int64_t* _618_x,uint8_t _618_fail){
    struct2 _618_$retval;
    int64_t _618_t6;
    int64_t _618_t14;
    *_618_x = 6;
    if (_618_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    _618_t6 = 100;
    *_618_x = $add_int64_t(*_618_x, _618_t6, "tests/integration/errors/passive-errdefer.orng:14:23:\n        errdefer x^ += 100\n                     ^");
    _618_t14 = 9;
    *_618_x = $add_int64_t(*_618_x, _618_t14, "tests/integration/errors/passive-errdefer.orng:11:19:\n    errdefer x^ += 9\n                 ^");
    return _618_$retval;
BB9:
    _618_$retval = (struct2) {.tag=0};
    return _618_$retval;
}

int main(void) {
  printf("%ld",_616_main());
  return 0;
}
