/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct2;

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

struct struct2 {
    int64_t* _0;
    int64_t _1;
};

typedef void(*function1)(int64_t*, int64_t);

/* Function forward definitions */
int64_t _976_main(void);
int64_t _978_sum_down(int64_t _978_x);
void _983_inc(int64_t* _983_x, int64_t _983_i);


/* Function definitions */
int64_t _976_main(void){
    function0 _976_t0;
    int64_t _976_t2;
    int64_t _976_t1;
    int64_t _976_t3;
    int64_t _976_$retval;
    _976_t0 = (function0) _978_sum_down;
    _976_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _976_t1 = _976_t0(_976_t2);
    $line_idx--;
    _976_t3 = 2;
    _976_$retval = $add_int64_t(_976_t1, _976_t3, "tests/integration/functions/mut-param-addrof.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _976_$retval;
}

int64_t _978_sum_down(int64_t _978_x){
    int64_t _980_i;
    int64_t _978_t2;
    uint8_t _978_t3;
    function1 _978_t4;
    int64_t* _978_t6;
    int64_t _978_t7;
    int64_t _978_$retval;
    _980_i = _978_x;
    goto BB1154;
BB1154:
    _978_t2 = 0;
    _978_t3 = _980_i>=_978_t2;
    if (_978_t3) {
        goto BB1155;
    } else {
        goto BB1160;
    }
BB1155:
    _978_t4 = (function1) _983_inc;
    _978_t6 = &_978_x;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:6:13:\n        inc(&mut x, i)\n           ^";
    (void) _978_t4(_978_t6, _980_i);
    $line_idx--;
    _978_t7 = 1;
    _980_i = $sub_int64_t(_980_i, _978_t7, "tests/integration/functions/mut-param-addrof.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1154;
BB1160:
    _978_$retval = _978_x;
    return _978_$retval;
}

void _983_inc(int64_t* _983_x, int64_t _983_i){
    *_983_x = $add_int64_t(*_983_x, _983_i, "tests/integration/functions/mut-param-addrof.orng:11:42:\nfn inc(x: &mut Int, i: Int) -> () { x^ += i }\n                                        ^");
    return;
}


int main(void) {
  printf("%ld",_976_main());
  return 0;
}
