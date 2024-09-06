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
int64_t _254_add(int64_t _254_x, int64_t _254_y);
int64_t _256_sub(int64_t _256_x, int64_t _256_y);
int64_t _258_mul(int64_t _258_x, int64_t _258_y);
int64_t _260_div(int64_t _260_x, int64_t _260_y);
int64_t _237_main(void);


/* Function definitions */
int64_t _254_add(int64_t _254_x, int64_t _254_y){
    int64_t _254_$retval;
    _254_$retval = $add_int64_t(_254_x, _254_y, "tests/integration/comptime/return-function.orng:17:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _254_$retval;
}

int64_t _256_sub(int64_t _256_x, int64_t _256_y){
    int64_t _256_$retval;
    _256_$retval = $sub_int64_t(_256_x, _256_y, "tests/integration/comptime/return-function.orng:18:36:\nfn sub(x: Int, y: Int) -> Int { x - y }\n                                  ^");
    return _256_$retval;
}

int64_t _258_mul(int64_t _258_x, int64_t _258_y){
    int64_t _258_$retval;
    _258_$retval = $mult_int64_t(_258_x, _258_y, "tests/integration/comptime/return-function.orng:19:36:\nfn mul(x: Int, y: Int) -> Int { x * y }\n                                  ^");
    return _258_$retval;
}

int64_t _260_div(int64_t _260_x, int64_t _260_y){
    int64_t _260_$retval;
    _260_$retval = $div_int64_t(_260_x, _260_y, "tests/integration/comptime/return-function.orng:20:36:\nfn div(x: Int, y: Int) -> Int { x / y }\n                                  ^");
    return _260_$retval;
}

int64_t _237_main(void){
    function0 _237_t2;
    int64_t _237_t4;
    int64_t _237_t5;
    int64_t _237_t3;
    int64_t _237_$retval;
    _237_t2 = (function0) _258_mul;
    _237_t4 = 66;
    _237_t5 = 4;
    $lines[$line_idx++] = "tests/integration/comptime/return-function.orng:4:7:\n    f(66, 4)\n     ^";
    _237_t3 = _237_t2(_237_t4, _237_t5);
    $line_idx--;
    _237_$retval = _237_t3;
    return _237_$retval;
}


int main(void) {
  printf("%ld",_237_main());
  return 0;
}
