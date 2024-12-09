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
int64_t _1044_main(void);
int64_t _1046_$anon97(int64_t _1046_x, int64_t _1046_y);


/* Function definitions */
int64_t _1044_main(void){
    function0 _1044_t0;
    int64_t _1044_t2;
    int64_t _1044_t3;
    int64_t _1044_t1;
    function0 _1044_t4;
    int64_t _1044_t6;
    int64_t _1044_t7;
    int64_t _1044_t5;
    int64_t _1044_$retval;
    _1044_t0 = (function0) _1046_$anon97;
    _1044_t2 = 200;
    _1044_t3 = 100;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-memoized.orng:6:9:\n    add(Int, 200, 100) + add(Int, 8, 4)\n       ^";
    _1044_t1 = _1044_t0(_1044_t2, _1044_t3);
    $line_idx--;
    _1044_t4 = (function0) _1046_$anon97;
    _1044_t6 = 8;
    _1044_t7 = 4;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-memoized.orng:6:30:\n    add(Int, 200, 100) + add(Int, 8, 4)\n                            ^";
    _1044_t5 = _1044_t4(_1044_t6, _1044_t7);
    $line_idx--;
    _1044_$retval = $add_int64_t(_1044_t1, _1044_t5, "tests/integration/generics/comptime-fn-memoized.orng:6:25:\n    add(Int, 200, 100) + add(Int, 8, 4)\n                       ^");
    return _1044_$retval;
}

int64_t _1046_$anon97(int64_t _1046_x, int64_t _1046_y){
    int64_t _1046_$retval;
    _1046_$retval = $add_int64_t(_1046_x, _1046_y, "tests/integration/generics/comptime-fn-memoized.orng:3:45:\nfn add(const T: Type, x: T, y: T) -> T { x + y }\n                                           ^");
    return _1046_$retval;
}


int main(void) {
  printf("%ld",_1044_main());
  return 0;
}
