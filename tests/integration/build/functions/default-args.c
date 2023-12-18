/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct1;

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _1065_main(void);
int64_t _1067_add(int64_t _1067_x,int64_t _1067_y);

/* Function definitions */
int64_t _1065_main(void){
    function0 _1065_t0;
    function0 _1065_t2;
    int64_t _1065_t4;
    int64_t _1065_t5;
    int64_t _1065_t3;
    function0 _1065_t6;
    int64_t _1065_t8;
    int64_t _1065_t9;
    int64_t _1065_t7;
    int64_t _1065_t1;
    int64_t _1065_$retval;
    _1065_t0 = _1067_add;
    _1065_t2 = _1067_add;
    _1065_t4 = 47;
    _1065_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _1065_t3 = _1065_t2(_1065_t4, _1065_t5);
    $line_idx--;
    _1065_t6 = _1067_add;
    _1065_t8 = 1;
    _1065_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _1065_t7 = _1065_t6(_1065_t8, _1065_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _1065_t1 = _1065_t0(_1065_t3, _1065_t7);
    $line_idx--;
    _1065_$retval = _1065_t1;
    return _1065_$retval;
}

int64_t _1067_add(int64_t _1067_x,int64_t _1067_y){
    int64_t _1067_$retval;
    _1067_$retval = $add_int64_t(_1067_x, _1067_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _1067_$retval;
}

int main(void) {
  printf("%ld",_1065_main());
  return 0;
}
