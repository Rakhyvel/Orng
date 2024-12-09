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
int64_t _341_add(int64_t _341_x, int64_t _341_y);
int64_t _343_sub(int64_t _343_x, int64_t _343_y);
int64_t _345_mul(int64_t _345_x, int64_t _345_y);
int64_t _347_div(int64_t _347_x, int64_t _347_y);
int64_t _324_main(void);


/* Function definitions */
int64_t _341_add(int64_t _341_x, int64_t _341_y){
    int64_t _341_$retval;
    _341_$retval = $add_int64_t(_341_x, _341_y, "tests/integration/comptime/return-function.orng:17:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _341_$retval;
}

int64_t _343_sub(int64_t _343_x, int64_t _343_y){
    int64_t _343_$retval;
    _343_$retval = $sub_int64_t(_343_x, _343_y, "tests/integration/comptime/return-function.orng:18:36:\nfn sub(x: Int, y: Int) -> Int { x - y }\n                                  ^");
    return _343_$retval;
}

int64_t _345_mul(int64_t _345_x, int64_t _345_y){
    int64_t _345_$retval;
    _345_$retval = $mult_int64_t(_345_x, _345_y, "tests/integration/comptime/return-function.orng:19:36:\nfn mul(x: Int, y: Int) -> Int { x * y }\n                                  ^");
    return _345_$retval;
}

int64_t _347_div(int64_t _347_x, int64_t _347_y){
    int64_t _347_$retval;
    _347_$retval = $div_int64_t(_347_x, _347_y, "tests/integration/comptime/return-function.orng:20:36:\nfn div(x: Int, y: Int) -> Int { x / y }\n                                  ^");
    return _347_$retval;
}

int64_t _324_main(void){
    function0 _324_t2;
    int64_t _324_t4;
    int64_t _324_t5;
    int64_t _324_t3;
    int64_t _324_$retval;
    _324_t2 = (function0) _345_mul;
    _324_t4 = 66;
    _324_t5 = 4;
    $lines[$line_idx++] = "tests/integration/comptime/return-function.orng:4:7:\n    f(66, 4)\n     ^";
    _324_t3 = _324_t2(_324_t4, _324_t5);
    $line_idx--;
    _324_$retval = _324_t3;
    return _324_$retval;
}


int main(void) {
  printf("%ld",_324_main());
  return 0;
}
