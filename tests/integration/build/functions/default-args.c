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
int64_t _947_main(void);
int64_t _949_add(int64_t _949_x, int64_t _949_y);


/* Function definitions */
int64_t _947_main(void){
    function0 _947_t0;
    function0 _947_t2;
    int64_t _947_t4;
    int64_t _947_t5;
    int64_t _947_t3;
    function0 _947_t6;
    int64_t _947_t8;
    int64_t _947_t9;
    int64_t _947_t7;
    int64_t _947_t1;
    int64_t _947_$retval;
    _947_t0 = (function0) _949_add;
    _947_t2 = (function0) _949_add;
    _947_t4 = 47;
    _947_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _947_t3 = _947_t2(_947_t4, _947_t5);
    $line_idx--;
    _947_t6 = (function0) _949_add;
    _947_t8 = 1;
    _947_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _947_t7 = _947_t6(_947_t8, _947_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _947_t1 = _947_t0(_947_t3, _947_t7);
    $line_idx--;
    _947_$retval = _947_t1;
    return _947_$retval;
}

int64_t _949_add(int64_t _949_x, int64_t _949_y){
    int64_t _949_$retval;
    _949_$retval = $add_int64_t(_949_x, _949_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _949_$retval;
}


int main(void) {
  printf("%ld",_947_main());
  return 0;
}
