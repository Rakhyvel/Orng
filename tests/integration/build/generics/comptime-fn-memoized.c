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
int64_t _1061_main(void);
int64_t _1063_$anon100(int64_t _1063_x, int64_t _1063_y);


/* Function definitions */
int64_t _1061_main(void){
    function0 _1061_t0;
    int64_t _1061_t2;
    int64_t _1061_t3;
    int64_t _1061_t1;
    function0 _1061_t4;
    int64_t _1061_t6;
    int64_t _1061_t7;
    int64_t _1061_t5;
    int64_t _1061_$retval;
    _1061_t0 = (function0) _1063_$anon100;
    _1061_t2 = 200;
    _1061_t3 = 100;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-memoized.orng:6:9:\n    add(Int, 200, 100) + add(Int, 8, 4)\n       ^";
    _1061_t1 = _1061_t0(_1061_t2, _1061_t3);
    $line_idx--;
    _1061_t4 = (function0) _1063_$anon100;
    _1061_t6 = 8;
    _1061_t7 = 4;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-memoized.orng:6:30:\n    add(Int, 200, 100) + add(Int, 8, 4)\n                            ^";
    _1061_t5 = _1061_t4(_1061_t6, _1061_t7);
    $line_idx--;
    _1061_$retval = $add_int64_t(_1061_t1, _1061_t5, "tests/integration/generics/comptime-fn-memoized.orng:6:25:\n    add(Int, 200, 100) + add(Int, 8, 4)\n                       ^");
    return _1061_$retval;
}

int64_t _1063_$anon100(int64_t _1063_x, int64_t _1063_y){
    int64_t _1063_$retval;
    _1063_$retval = $add_int64_t(_1063_x, _1063_y, "tests/integration/generics/comptime-fn-memoized.orng:3:45:\nfn add(const T: Type, x: T, y: T) -> T { x + y }\n                                           ^");
    return _1063_$retval;
}


int main(void) {
  printf("%ld",_1061_main());
  return 0;
}
