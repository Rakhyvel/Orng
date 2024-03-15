/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    uint32_t _0;
    int64_t _1;
    double _2;
};

/* Function forward definitions */
int64_t _249_add(int64_t _249_a, int64_t _249_b);
int64_t _245_main(void);


/* Function definitions */
int64_t _249_add(int64_t _249_a, int64_t _249_b){
    int64_t _249_$retval;
    _249_$retval = $add_int64_t(_249_a, _249_b, "tests/integration/comptime/index-heterotypical.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _249_$retval;
}

int64_t _245_main(void){
    uint32_t _245_t1;
    int64_t _245_t2;
    double _245_t3;
    struct struct0 _246_x;
    int64_t _245_$retval;
    _245_t1 = 960;
    _245_t2 = 248;
    _245_t3 = 3.14e0;
    _246_x = (struct struct0) {_245_t1, _245_t2, _245_t3};
    _245_$retval = _246_x._1;
    return _245_$retval;
}


int main(void) {
  printf("%ld",_245_main());
  return 0;
}
