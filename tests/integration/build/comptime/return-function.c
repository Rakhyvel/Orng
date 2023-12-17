/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct1;

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
function0 _387_g(int64_t _387_x);
int64_t _394_add(int64_t _394_x,int64_t _394_y);
int64_t _396_sub(int64_t _396_x,int64_t _396_y);
int64_t _398_mul(int64_t _398_x,int64_t _398_y);
int64_t _400_div(int64_t _400_x,int64_t _400_y);
int64_t _381_main(void);

/* Function definitions */
function0 _387_g(int64_t _387_x){
    int64_t _387_t1;
    uint8_t _387_t2;
    function0 _387_t0;
    int64_t _387_t7;
    uint8_t _387_t8;
    function0 _387_$retval;
    int64_t _387_t3;
    uint8_t _387_t4;
    int64_t _387_t5;
    uint8_t _387_t6;
    _387_t1 = 0;
    _387_t2 = _387_x == _387_t1;
    if (_387_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _387_t0 = _394_add;
    goto BB5;
BB6:
    _387_t3 = 1;
    _387_t4 = _387_x == _387_t3;
    if (_387_t4) {
        goto BB8;
    } else {
        goto BB9;
    }
BB5:
    _387_$retval = _387_t0;
    return _387_$retval;
BB8:
    _387_t0 = _396_sub;
    goto BB5;
BB9:
    _387_t5 = 2;
    _387_t6 = _387_x == _387_t5;
    if (_387_t6) {
        goto BB11;
    } else {
        goto BB12;
    }
BB11:
    _387_t0 = _398_mul;
    goto BB5;
BB12:
    _387_t7 = 3;
    _387_t8 = _387_x == _387_t7;
    if (_387_t8) {
        goto BB14;
    } else {
        goto BB16;
    }
BB14:
    _387_t0 = _400_div;
    goto BB5;
BB16:
    $lines[$line_idx++] = "tests/integration/comptime/return-function.orng:13:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

int64_t _394_add(int64_t _394_x,int64_t _394_y){
    int64_t _394_$retval;
    _394_$retval = $add_int64_t(_394_x, _394_y, "tests/integration/comptime/return-function.orng:17:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _394_$retval;
}

int64_t _396_sub(int64_t _396_x,int64_t _396_y){
    int64_t _396_$retval;
    _396_$retval = $sub_int64_t(_396_x, _396_y, "tests/integration/comptime/return-function.orng:18:36:\nfn sub(x: Int, y: Int) -> Int { x - y }\n                                  ^");
    return _396_$retval;
}

int64_t _398_mul(int64_t _398_x,int64_t _398_y){
    int64_t _398_$retval;
    _398_$retval = $mult_int64_t(_398_x, _398_y, "tests/integration/comptime/return-function.orng:19:36:\nfn mul(x: Int, y: Int) -> Int { x * y }\n                                  ^");
    return _398_$retval;
}

int64_t _400_div(int64_t _400_x,int64_t _400_y){
    int64_t _400_$retval;
    _400_$retval = $div_int64_t(_400_x, _400_y, "tests/integration/comptime/return-function.orng:20:36:\nfn div(x: Int, y: Int) -> Int { x / y }\n                                  ^");
    return _400_$retval;
}

int64_t _381_main(void){
    function0 _381_t1;
    int64_t _381_t3;
    int64_t _381_t4;
    int64_t _381_t2;
    int64_t _381_$retval;
    _381_t1 = _398_mul;
    _381_t3 = 66;
    _381_t4 = 4;
    $lines[$line_idx++] = "tests/integration/comptime/return-function.orng:4:7:\n    f(66, 4)\n     ^";
    _381_t2 = _381_t1(_381_t3, _381_t4);
    $line_idx--;
    _381_$retval = _381_t2;
    return _381_$retval;
}

int main(void) {
  printf("%ld",_381_main());
  return 0;
}
