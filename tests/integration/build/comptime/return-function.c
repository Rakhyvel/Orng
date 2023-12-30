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
function0 _303_g(int64_t _303_x);
int64_t _311_add(int64_t _311_x, int64_t _311_y);
int64_t _313_sub(int64_t _313_x, int64_t _313_y);
int64_t _315_mul(int64_t _315_x, int64_t _315_y);
int64_t _317_div(int64_t _317_x, int64_t _317_y);
int64_t _297_main(void);

/* Function definitions */
function0 _303_g(int64_t _303_x){
    int64_t _303_t1;
    uint8_t _303_t2;
    function0 _303_t0;
    int64_t _303_t7;
    uint8_t _303_t8;
    function0 _303_$retval;
    int64_t _303_t3;
    uint8_t _303_t4;
    int64_t _303_t5;
    uint8_t _303_t6;
    _303_t1 = 0;
    _303_t2 = _303_x==_303_t1;
    if (_303_t2) {
        goto BB359;
    } else {
        goto BB362;
    }
BB359:
    _303_t0 = _311_add;
    goto BB361;
BB362:
    _303_t3 = 1;
    _303_t4 = _303_x==_303_t3;
    if (_303_t4) {
        goto BB364;
    } else {
        goto BB365;
    }
BB361:
    _303_$retval = _303_t0;
    return _303_$retval;
BB364:
    _303_t0 = _313_sub;
    goto BB361;
BB365:
    _303_t5 = 2;
    _303_t6 = _303_x==_303_t5;
    if (_303_t6) {
        goto BB367;
    } else {
        goto BB368;
    }
BB367:
    _303_t0 = _315_mul;
    goto BB361;
BB368:
    _303_t7 = 3;
    _303_t8 = _303_x==_303_t7;
    if (_303_t8) {
        goto BB370;
    } else {
        goto BB372;
    }
BB370:
    _303_t0 = _317_div;
    goto BB361;
BB372:
    $lines[$line_idx++] = "tests/integration/comptime/return-function.orng:13:25:\n        _ => unreachable\n                       ^";
    $panic("reached unreachable code\n");
}

int64_t _311_add(int64_t _311_x, int64_t _311_y){
    int64_t _311_$retval;
    _311_$retval = $add_int64_t(_311_x, _311_y, "tests/integration/comptime/return-function.orng:17:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _311_$retval;
}

int64_t _313_sub(int64_t _313_x, int64_t _313_y){
    int64_t _313_$retval;
    _313_$retval = $sub_int64_t(_313_x, _313_y, "tests/integration/comptime/return-function.orng:18:36:\nfn sub(x: Int, y: Int) -> Int { x - y }\n                                  ^");
    return _313_$retval;
}

int64_t _315_mul(int64_t _315_x, int64_t _315_y){
    int64_t _315_$retval;
    _315_$retval = $mult_int64_t(_315_x, _315_y, "tests/integration/comptime/return-function.orng:19:36:\nfn mul(x: Int, y: Int) -> Int { x * y }\n                                  ^");
    return _315_$retval;
}

int64_t _317_div(int64_t _317_x, int64_t _317_y){
    int64_t _317_$retval;
    _317_$retval = $div_int64_t(_317_x, _317_y, "tests/integration/comptime/return-function.orng:20:36:\nfn div(x: Int, y: Int) -> Int { x / y }\n                                  ^");
    return _317_$retval;
}

int64_t _297_main(void){
    function0 _297_t1;
    int64_t _297_t3;
    int64_t _297_t4;
    int64_t _297_t2;
    int64_t _297_$retval;
    _297_t1 = _315_mul;
    _297_t3 = 66;
    _297_t4 = 4;
    $lines[$line_idx++] = "tests/integration/comptime/return-function.orng:4:7:\n    f(66, 4)\n     ^";
    _297_t2 = _297_t1(_297_t3, _297_t4);
    $line_idx--;
    _297_$retval = _297_t2;
    return _297_$retval;
}

int main(void) {
  printf("%ld",_297_main());
  return 0;
}
