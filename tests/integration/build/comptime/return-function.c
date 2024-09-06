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
int64_t _336_add(int64_t _336_x, int64_t _336_y);
int64_t _338_sub(int64_t _338_x, int64_t _338_y);
int64_t _340_mul(int64_t _340_x, int64_t _340_y);
int64_t _342_div(int64_t _342_x, int64_t _342_y);
int64_t _319_main(void);


/* Function definitions */
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
    function0 _319_t2;
    int64_t _319_t4;
    int64_t _319_t5;
    int64_t _319_t3;
    int64_t _319_$retval;
    _319_t2 = (function0) _340_mul;
    _319_t4 = 66;
    _319_t5 = 4;
    $lines[$line_idx++] = "tests/integration/comptime/return-function.orng:4:7:\n    f(66, 4)\n     ^";
    _319_t3 = _319_t2(_319_t4, _319_t5);
    $line_idx--;
    _319_$retval = _319_t3;
    return _319_$retval;
}


int main(void) {
  printf("%ld",_319_main());
  return 0;
}
