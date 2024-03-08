/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
function0 _328_g(int64_t _328_x);
int64_t _336_add(int64_t _336_x, int64_t _336_y);
int64_t _338_sub(int64_t _338_x, int64_t _338_y);
int64_t _340_mul(int64_t _340_x, int64_t _340_y);
int64_t _342_div(int64_t _342_x, int64_t _342_y);
int64_t _319_main(void);


/* Function definitions */
function0 _328_g(int64_t _328_x){
    int64_t _328_t1;
    uint8_t _328_t2;
    function0 _328_t0;
    int64_t _328_t7;
    uint8_t _328_t8;
    function0 _328_$retval;
    int64_t _328_t3;
    uint8_t _328_t4;
    int64_t _328_t5;
    uint8_t _328_t6;
    _328_t1 = 0;
    _328_t2 = _328_x==_328_t1;
    if (_328_t2) {
        goto BB369;
    } else {
        goto BB372;
    }
BB369:
    _328_t0 = (function0) _336_add;
    goto BB371;
BB372:
    _328_t3 = 1;
    _328_t4 = _328_x==_328_t3;
    if (_328_t4) {
        goto BB374;
    } else {
        goto BB375;
    }
BB371:
    _328_$retval = _328_t0;
    return _328_$retval;
BB374:
    _328_t0 = (function0) _338_sub;
    goto BB371;
BB375:
    _328_t5 = 2;
    _328_t6 = _328_x==_328_t5;
    if (_328_t6) {
        goto BB377;
    } else {
        goto BB378;
    }
BB377:
    _328_t0 = (function0) _340_mul;
    goto BB371;
BB378:
    _328_t7 = 3;
    _328_t8 = _328_x==_328_t7;
    if (_328_t8) {
        goto BB380;
    } else {
        goto BB382;
    }
BB380:
    _328_t0 = (function0) _342_div;
    goto BB371;
BB382:
    $lines[$line_idx++] = "tests/integration/comptime/return-function.orng:13:25:\n        _ => unreachable\n                       ^";
    $panic("reached unreachable code\n");
}

int64_t _336_add(int64_t _336_x, int64_t _336_y){
    int64_t _336_$retval;
    _336_$retval = $add_int64_t(_336_x, _336_y, "tests/integration/comptime/return-function.orng:17:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _336_$retval;
}

int64_t _338_sub(int64_t _338_x, int64_t _338_y){
    int64_t _338_$retval;
    _338_$retval = $sub_int64_t(_338_x, _338_y, "tests/integration/comptime/return-function.orng:18:36:\nfn sub(x: Int, y: Int) -> Int { x - y }\n                                  ^");
    return _338_$retval;
}

int64_t _340_mul(int64_t _340_x, int64_t _340_y){
    int64_t _340_$retval;
    _340_$retval = $mult_int64_t(_340_x, _340_y, "tests/integration/comptime/return-function.orng:19:36:\nfn mul(x: Int, y: Int) -> Int { x * y }\n                                  ^");
    return _340_$retval;
}

int64_t _342_div(int64_t _342_x, int64_t _342_y){
    int64_t _342_$retval;
    _342_$retval = $div_int64_t(_342_x, _342_y, "tests/integration/comptime/return-function.orng:20:36:\nfn div(x: Int, y: Int) -> Int { x / y }\n                                  ^");
    return _342_$retval;
}

int64_t _319_main(void){
    function0 _319_t1;
    int64_t _319_t3;
    int64_t _319_t4;
    int64_t _319_t2;
    int64_t _319_$retval;
    _319_t1 = (function0) _340_mul;
    _319_t3 = 66;
    _319_t4 = 4;
    $lines[$line_idx++] = "tests/integration/comptime/return-function.orng:4:7:\n    f(66, 4)\n     ^";
    _319_t2 = _319_t1(_319_t3, _319_t4);
    $line_idx--;
    _319_$retval = _319_t2;
    return _319_$retval;
}


int main(void) {
  printf("%ld",_319_main());
  return 0;
}
