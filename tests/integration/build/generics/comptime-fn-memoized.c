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
int64_t _1031_main(void);
int64_t _1033_$anon95(int64_t _1033_x, int64_t _1033_y);


/* Function definitions */
int64_t _1031_main(void){
    function0 _1031_t0;
    int64_t _1031_t2;
    int64_t _1031_t3;
    int64_t _1031_t1;
    function0 _1031_t4;
    int64_t _1031_t6;
    int64_t _1031_t7;
    int64_t _1031_t5;
    int64_t _1031_$retval;
    _1031_t0 = (function0) _1033_$anon95;
    _1031_t2 = 200;
    _1031_t3 = 100;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-memoized.orng:6:9:\n    add(Int, 200, 100) + add(Int, 8, 4)\n       ^";
    _1031_t1 = _1031_t0(_1031_t2, _1031_t3);
    $line_idx--;
    _1031_t4 = (function0) _1033_$anon95;
    _1031_t6 = 8;
    _1031_t7 = 4;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-memoized.orng:6:30:\n    add(Int, 200, 100) + add(Int, 8, 4)\n                            ^";
    _1031_t5 = _1031_t4(_1031_t6, _1031_t7);
    $line_idx--;
    _1031_$retval = $add_int64_t(_1031_t1, _1031_t5, "tests/integration/generics/comptime-fn-memoized.orng:6:25:\n    add(Int, 200, 100) + add(Int, 8, 4)\n                       ^");
    return _1031_$retval;
}

int64_t _1033_$anon95(int64_t _1033_x, int64_t _1033_y){
    int64_t _1033_$retval;
    _1033_$retval = $add_int64_t(_1033_x, _1033_y, "tests/integration/generics/comptime-fn-memoized.orng:3:45:\nfn add(const T: Type, x: T, y: T) -> T { x + y }\n                                           ^");
    return _1033_$retval;
}


int main(void) {
  printf("%ld",_1031_main());
  return 0;
}
