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
int64_t _1069_main(void);
int64_t _1071_$anon102(int64_t _1071_x, int64_t _1071_y);


/* Function definitions */
int64_t _1069_main(void){
    function0 _1069_t0;
    int64_t _1069_t2;
    int64_t _1069_t3;
    int64_t _1069_t1;
    int64_t _1069_$retval;
    _1069_t0 = (function0) _1071_$anon102;
    _1069_t2 = 300;
    _1069_t3 = 11;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn.orng:10:9:\n    add(Int, 300, 11)\n       ^";
    _1069_t1 = _1069_t0(_1069_t2, _1069_t3);
    $line_idx--;
    _1069_$retval = _1069_t1;
    return _1069_$retval;
}

int64_t _1071_$anon102(int64_t _1071_x, int64_t _1071_y){
    int64_t _1071_$retval;
    _1071_$retval = $add_int64_t(_1071_x, _1071_y, "tests/integration/generics/comptime-fn.orng:5:45:\nfn add(const T: Type, x: T, y: T) -> T { x + y }\n                                           ^");
    return _1071_$retval;
}


int main(void) {
  printf("%ld",_1069_main());
  return 0;
}
