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
int64_t _930_main(void);
int64_t _932_add(int64_t _932_x, int64_t _932_y);


/* Function definitions */
int64_t _930_main(void){
    function0 _930_t0;
    int64_t _930_t2;
    int64_t _930_t3;
    int64_t _930_t1;
    int64_t _930_$retval;
    _930_t0 = (function0) _932_add;
    _930_t2 = 40;
    _930_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _930_t1 = _930_t0(_930_t2, _930_t3);
    $line_idx--;
    _930_$retval = _930_t1;
    return _930_$retval;
}

int64_t _932_add(int64_t _932_x, int64_t _932_y){
    int64_t _932_$retval;
    _932_$retval = $add_int64_t(_932_x, _932_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _932_$retval;
}


int main(void) {
  printf("%ld",_930_main());
  return 0;
}
