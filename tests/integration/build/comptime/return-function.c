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
function0 _146_g(int64_t _146_x);
int64_t _153_add(int64_t _153_x,int64_t _153_y);
int64_t _155_sub(int64_t _155_x,int64_t _155_y);
int64_t _157_mul(int64_t _157_x,int64_t _157_y);
int64_t _159_div(int64_t _159_x,int64_t _159_y);
int64_t _140_main(void);

/* Function definitions */
function0 _146_g(int64_t _146_x){
    int64_t _146_t1;
    uint8_t _146_t2;
    function0 _146_t0;
    int64_t _146_t7;
    uint8_t _146_t8;
    function0 _146_$retval;
    int64_t _146_t3;
    uint8_t _146_t4;
    int64_t _146_t5;
    uint8_t _146_t6;
    _146_t1 = 0;
    _146_t2 = _146_x == _146_t1;
    if (_146_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _146_t0 = _153_add;
    goto BB5;
BB6:
    _146_t3 = 1;
    _146_t4 = _146_x == _146_t3;
    if (_146_t4) {
        goto BB8;
    } else {
        goto BB9;
    }
BB5:
    _146_$retval = _146_t0;
    return _146_$retval;
BB8:
    _146_t0 = _155_sub;
    goto BB5;
BB9:
    _146_t5 = 2;
    _146_t6 = _146_x == _146_t5;
    if (_146_t6) {
        goto BB11;
    } else {
        goto BB12;
    }
BB11:
    _146_t0 = _157_mul;
    goto BB5;
BB12:
    _146_t7 = 3;
    _146_t8 = _146_x == _146_t7;
    if (_146_t8) {
        goto BB14;
    } else {
        goto BB16;
    }
BB14:
    _146_t0 = _159_div;
    goto BB5;
BB16:
    $lines[$line_idx++] = "tests/integration/comptime/return-function.orng:13:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

int64_t _153_add(int64_t _153_x,int64_t _153_y){
    int64_t _153_$retval;
    _153_$retval = $add_int64_t(_153_x, _153_y, "tests/integration/comptime/return-function.orng:17:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _153_$retval;
}

int64_t _155_sub(int64_t _155_x,int64_t _155_y){
    int64_t _155_$retval;
    _155_$retval = $sub_int64_t(_155_x, _155_y, "tests/integration/comptime/return-function.orng:18:36:\nfn sub(x: Int, y: Int) -> Int { x - y }\n                                  ^");
    return _155_$retval;
}

int64_t _157_mul(int64_t _157_x,int64_t _157_y){
    int64_t _157_$retval;
    _157_$retval = $mult_int64_t(_157_x, _157_y, "tests/integration/comptime/return-function.orng:19:36:\nfn mul(x: Int, y: Int) -> Int { x * y }\n                                  ^");
    return _157_$retval;
}

int64_t _159_div(int64_t _159_x,int64_t _159_y){
    int64_t _159_$retval;
    _159_$retval = $div_int64_t(_159_x, _159_y, "tests/integration/comptime/return-function.orng:20:36:\nfn div(x: Int, y: Int) -> Int { x / y }\n                                  ^");
    return _159_$retval;
}

int64_t _140_main(void){
    function0 _140_t1;
    int64_t _140_t3;
    int64_t _140_t4;
    int64_t _140_t2;
    int64_t _140_$retval;
    _140_t1 = _157_mul;
    _140_t3 = 66;
    _140_t4 = 4;
    $lines[$line_idx++] = "tests/integration/comptime/return-function.orng:4:7:\n    f(66, 4)\n     ^";
    _140_t2 = _140_t1(_140_t3, _140_t4);
    $line_idx--;
    _140_$retval = _140_t2;
    return _140_$retval;
}

int main(void) {
  printf("%ld",_140_main());
  return 0;
}
