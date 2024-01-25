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
int64_t _981_main(void);
int64_t _983_add(int64_t _983_x, int64_t _983_y);


/* Function definitions */
int64_t _981_main(void){
    function0 _981_t0;
    function0 _981_t2;
    int64_t _981_t4;
    int64_t _981_t5;
    int64_t _981_t3;
    function0 _981_t6;
    int64_t _981_t8;
    int64_t _981_t9;
    int64_t _981_t7;
    int64_t _981_t1;
    int64_t _981_$retval;
    _981_t0 = _983_add;
    _981_t2 = _983_add;
    _981_t4 = 47;
    _981_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _981_t3 = _981_t2(_981_t4, _981_t5);
    $line_idx--;
    _981_t6 = _983_add;
    _981_t8 = 1;
    _981_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _981_t7 = _981_t6(_981_t8, _981_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _981_t1 = _981_t0(_981_t3, _981_t7);
    $line_idx--;
    _981_$retval = _981_t1;
    return _981_$retval;
}

int64_t _983_add(int64_t _983_x, int64_t _983_y){
    int64_t _983_$retval;
    _983_$retval = $add_int64_t(_983_x, _983_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _983_$retval;
}


int main(void) {
  printf("%ld",_981_main());
  return 0;
}
