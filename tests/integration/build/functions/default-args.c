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
int64_t _1058_main(void);
int64_t _1060_add(int64_t _1060_x,int64_t _1060_y);

/* Function definitions */
int64_t _1058_main(void){
    function0 _1058_t0;
    function0 _1058_t2;
    int64_t _1058_t4;
    int64_t _1058_t5;
    int64_t _1058_t3;
    function0 _1058_t6;
    int64_t _1058_t8;
    int64_t _1058_t9;
    int64_t _1058_t7;
    int64_t _1058_t1;
    int64_t _1058_$retval;
    _1058_t0 = _1060_add;
    _1058_t2 = _1060_add;
    _1058_t4 = 47;
    _1058_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _1058_t3 = _1058_t2(_1058_t4, _1058_t5);
    $line_idx--;
    _1058_t6 = _1060_add;
    _1058_t8 = 1;
    _1058_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _1058_t7 = _1058_t6(_1058_t8, _1058_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _1058_t1 = _1058_t0(_1058_t3, _1058_t7);
    $line_idx--;
    _1058_$retval = _1058_t1;
    return _1058_$retval;
}

int64_t _1060_add(int64_t _1060_x,int64_t _1060_y){
    int64_t _1060_$retval;
    _1060_$retval = $add_int64_t(_1060_x, _1060_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _1060_$retval;
}

int main(void) {
  printf("%ld",_1058_main());
  return 0;
}
