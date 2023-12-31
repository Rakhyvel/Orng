/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;

/* Typedefs */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _951_main(void);
int64_t _953_add(int64_t _953_x, int64_t _953_y);

/* Function definitions */
int64_t _951_main(void){
    function0 _951_t0;
    function0 _951_t2;
    int64_t _951_t4;
    int64_t _951_t5;
    int64_t _951_t3;
    function0 _951_t6;
    int64_t _951_t8;
    int64_t _951_t9;
    int64_t _951_t7;
    int64_t _951_t1;
    int64_t _951_$retval;
    _951_t0 = _953_add;
    _951_t2 = _953_add;
    _951_t4 = 47;
    _951_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _951_t3 = _951_t2(_951_t4, _951_t5);
    $line_idx--;
    _951_t6 = _953_add;
    _951_t8 = 1;
    _951_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _951_t7 = _951_t6(_951_t8, _951_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _951_t1 = _951_t0(_951_t3, _951_t7);
    $line_idx--;
    _951_$retval = _951_t1;
    return _951_$retval;
}

int64_t _953_add(int64_t _953_x, int64_t _953_y){
    int64_t _953_$retval;
    _953_$retval = $add_int64_t(_953_x, _953_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _953_$retval;
}

int main(void) {
  printf("%ld",_951_main());
  return 0;
}
