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
int64_t _966_main(void);
int64_t _968_add(int64_t _968_x, int64_t _968_y);


/* Function definitions */
int64_t _966_main(void){
    function0 _966_t0;
    int64_t _966_t2;
    int64_t _966_t3;
    int64_t _966_t1;
    int64_t _966_$retval;
    _966_t0 = (function0) _968_add;
    _966_t2 = 40;
    _966_t3 = 3;
    $lines[$line_idx++] = "tests/integration/functions/call.orng:2:23:\nfn main() -> Int {add(40, 3)}\n                     ^";
    _966_t1 = _966_t0(_966_t2, _966_t3);
    $line_idx--;
    _966_$retval = _966_t1;
    return _966_$retval;
}

int64_t _968_add(int64_t _968_x, int64_t _968_y){
    int64_t _968_$retval;
    _968_$retval = $add_int64_t(_968_x, _968_y, "tests/integration/functions/call.orng:4:35:\nfn add(x: Int, y: Int) -> Int {x + y}\n                                 ^");
    return _968_$retval;
}


int main(void) {
  printf("%ld",_966_main());
  return 0;
}
