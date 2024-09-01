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
int64_t _7_main(void);
int64_t _9_$anon1(int64_t _9_x, int64_t _9_y);


/* Function definitions */
int64_t _7_main(void){
    function0 _7_t0;
    int64_t _7_t2;
    int64_t _7_t3;
    int64_t _7_t1;
    int64_t _7_$retval;
    _7_t0 = (function0) _9_$anon1;
    _7_t2 = 300;
    _7_t3 = 11;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn.orng:10:9:\n    add(Int, 300, 11)\n       ^";
    _7_t1 = _7_t0(_7_t2, _7_t3);
    $line_idx--;
    _7_$retval = _7_t1;
    return _7_$retval;
}

int64_t _9_$anon1(int64_t _9_x, int64_t _9_y){
    int64_t _9_$retval;
    _9_$retval = $add_int64_t(_9_x, _9_y, "tests/integration/generics/comptime-fn.orng:5:45:\nfn add(const T: Type, x: T, y: T) -> T { x + y }\n                                           ^");
    return _9_$retval;
}


int main(void) {
  printf("%ld",_7_main());
  return 0;
}
