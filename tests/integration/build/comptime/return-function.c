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
function0 _302_g(int64_t _302_x);
int64_t _309_add(int64_t _309_x,int64_t _309_y);
int64_t _311_sub(int64_t _311_x,int64_t _311_y);
int64_t _313_mul(int64_t _313_x,int64_t _313_y);
int64_t _315_div(int64_t _315_x,int64_t _315_y);
int64_t _296_main(void);

/* Function definitions */
function0 _302_g(int64_t _302_x){
    int64_t _302_t1;
    uint8_t _302_t2;
    function0 _302_t0;
    int64_t _302_t7;
    uint8_t _302_t8;
    function0 _302_$retval;
    int64_t _302_t3;
    uint8_t _302_t4;
    int64_t _302_t5;
    uint8_t _302_t6;
    _302_t1 = 0;
    _302_t2 = _302_x==_302_t1;
    if (_302_t2) {
        goto BB359;
    } else {
        goto BB362;
    }
BB359:
    _302_t0 = _309_add;
    goto BB361;
BB362:
    _302_t3 = 1;
    _302_t4 = _302_x==_302_t3;
    if (_302_t4) {
        goto BB364;
    } else {
        goto BB365;
    }
BB361:
    _302_$retval = _302_t0;
    return _302_$retval;
BB364:
    _302_t0 = _311_sub;
    goto BB361;
BB365:
    _302_t5 = 2;
    _302_t6 = _302_x==_302_t5;
    if (_302_t6) {
        goto BB367;
    } else {
        goto BB368;
    }
BB367:
    _302_t0 = _313_mul;
    goto BB361;
BB368:
    _302_t7 = 3;
    _302_t8 = _302_x==_302_t7;
    if (_302_t8) {
        goto BB370;
    } else {
        goto BB372;
    }
BB370:
    _302_t0 = _315_div;
    goto BB361;
BB372:
    $lines[$line_idx++] = "tests/integration/comptime/return-function.orng:13:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

int64_t _309_add(int64_t _309_x,int64_t _309_y){
    int64_t _309_$retval;
    _309_$retval = $add_int64_t(_309_x, _309_y, "tests/integration/comptime/return-function.orng:17:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _309_$retval;
}

int64_t _311_sub(int64_t _311_x,int64_t _311_y){
    int64_t _311_$retval;
    _311_$retval = $sub_int64_t(_311_x, _311_y, "tests/integration/comptime/return-function.orng:18:36:\nfn sub(x: Int, y: Int) -> Int { x - y }\n                                  ^");
    return _311_$retval;
}

int64_t _313_mul(int64_t _313_x,int64_t _313_y){
    int64_t _313_$retval;
    _313_$retval = $mult_int64_t(_313_x, _313_y, "tests/integration/comptime/return-function.orng:19:36:\nfn mul(x: Int, y: Int) -> Int { x * y }\n                                  ^");
    return _313_$retval;
}

int64_t _315_div(int64_t _315_x,int64_t _315_y){
    int64_t _315_$retval;
    _315_$retval = $div_int64_t(_315_x, _315_y, "tests/integration/comptime/return-function.orng:20:36:\nfn div(x: Int, y: Int) -> Int { x / y }\n                                  ^");
    return _315_$retval;
}

int64_t _296_main(void){
    function0 _296_t1;
    int64_t _296_t3;
    int64_t _296_t4;
    int64_t _296_t2;
    int64_t _296_$retval;
    _296_t1 = _313_mul;
    _296_t3 = 66;
    _296_t4 = 4;
    $lines[$line_idx++] = "tests/integration/comptime/return-function.orng:4:7:\n    f(66, 4)\n     ^";
    _296_t2 = _296_t1(_296_t3, _296_t4);
    $line_idx--;
    _296_$retval = _296_t2;
    return _296_$retval;
}

int main(void) {
  printf("%ld",_296_main());
  return 0;
}
