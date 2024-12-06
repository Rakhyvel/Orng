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
int64_t _1041_main(void);
int64_t _1043_$anon97(int64_t _1043_x, int64_t _1043_y);


/* Function definitions */
int64_t _1041_main(void){
    function0 _1041_t0;
    int64_t _1041_t2;
    int64_t _1041_t3;
    int64_t _1041_t1;
    int64_t _1041_$retval;
    _1041_t0 = (function0) _1043_$anon97;
    _1041_t2 = 300;
    _1041_t3 = 11;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn.orng:10:9:\n    add(Int, 300, 11)\n       ^";
    _1041_t1 = _1041_t0(_1041_t2, _1041_t3);
    $line_idx--;
    _1041_$retval = _1041_t1;
    return _1041_$retval;
}

int64_t _1043_$anon97(int64_t _1043_x, int64_t _1043_y){
    int64_t _1043_$retval;
    _1043_$retval = $add_int64_t(_1043_x, _1043_y, "tests/integration/generics/comptime-fn.orng:5:45:\nfn add(const T: Type, x: T, y: T) -> T { x + y }\n                                           ^");
    return _1043_$retval;
}


int main(void) {
  printf("%ld",_1041_main());
  return 0;
}
