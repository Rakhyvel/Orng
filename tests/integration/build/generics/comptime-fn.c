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
int64_t _12_main(void);
int64_t _14_$anon2(int64_t _14_x, int64_t _14_y);


/* Function definitions */
int64_t _12_main(void){
    function0 _12_t0;
    int64_t _12_t2;
    int64_t _12_t3;
    int64_t _12_t1;
    int64_t _12_$retval;
    _12_t0 = (function0) _14_$anon2;
    _12_t2 = 300;
    _12_t3 = 11;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn.orng:10:9:\n    add(Int, 300, 11)\n       ^";
    _12_t1 = _12_t0(_12_t2, _12_t3);
    $line_idx--;
    _12_$retval = _12_t1;
    return _12_$retval;
}

int64_t _14_$anon2(int64_t _14_x, int64_t _14_y){
    int64_t _14_$retval;
    _14_$retval = $add_int64_t(_14_x, _14_y, "tests/integration/generics/comptime-fn.orng:5:45:\nfn add(const T: Type, x: T, y: T) -> T { x + y }\n                                           ^");
    return _14_$retval;
}


int main(void) {
  printf("%ld",_12_main());
  return 0;
}
