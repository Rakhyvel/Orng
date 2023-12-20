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
int64_t _939_main(void);
int64_t _941_add(int64_t _941_x,int64_t _941_y);

/* Function definitions */
int64_t _939_main(void){
    function0 _939_t0;
    function0 _939_t2;
    int64_t _939_t4;
    int64_t _939_t5;
    int64_t _939_t3;
    function0 _939_t6;
    int64_t _939_t8;
    int64_t _939_t9;
    int64_t _939_t7;
    int64_t _939_t1;
    int64_t _939_$retval;
    _939_t0 = _941_add;
    _939_t2 = _941_add;
    _939_t4 = 47;
    _939_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _939_t3 = _939_t2(_939_t4, _939_t5);
    $line_idx--;
    _939_t6 = _941_add;
    _939_t8 = 1;
    _939_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _939_t7 = _939_t6(_939_t8, _939_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _939_t1 = _939_t0(_939_t3, _939_t7);
    $line_idx--;
    _939_$retval = _939_t1;
    return _939_$retval;
}

int64_t _941_add(int64_t _941_x,int64_t _941_y){
    int64_t _941_$retval;
    _941_$retval = $add_int64_t(_941_x, _941_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _941_$retval;
}

int main(void) {
  printf("%ld",_939_main());
  return 0;
}
