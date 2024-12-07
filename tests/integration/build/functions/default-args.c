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
int64_t _961_main(void);
int64_t _963_add(int64_t _963_x, int64_t _963_y);


/* Function definitions */
int64_t _961_main(void){
    function0 _961_t0;
    function0 _961_t2;
    int64_t _961_t4;
    int64_t _961_t5;
    int64_t _961_t3;
    function0 _961_t6;
    int64_t _961_t8;
    int64_t _961_t9;
    int64_t _961_t7;
    int64_t _961_t1;
    int64_t _961_$retval;
    _961_t0 = (function0) _963_add;
    _961_t2 = (function0) _963_add;
    _961_t4 = 47;
    _961_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _961_t3 = _961_t2(_961_t4, _961_t5);
    $line_idx--;
    _961_t6 = (function0) _963_add;
    _961_t8 = 1;
    _961_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _961_t7 = _961_t6(_961_t8, _961_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _961_t1 = _961_t0(_961_t3, _961_t7);
    $line_idx--;
    _961_$retval = _961_t1;
    return _961_$retval;
}

int64_t _963_add(int64_t _963_x, int64_t _963_y){
    int64_t _963_$retval;
    _963_$retval = $add_int64_t(_963_x, _963_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _963_$retval;
}


int main(void) {
  printf("%ld",_961_main());
  return 0;
}
