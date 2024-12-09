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
int64_t _981_main(void);
int64_t _983_sum_down(int64_t _983_x);
void _988_inc(int64_t* _988_x, int64_t _988_i);


/* Function definitions */
int64_t _981_main(void){
    function0 _981_t0;
    int64_t _981_t2;
    int64_t _981_t1;
    int64_t _981_t3;
    int64_t _981_$retval;
    _981_t0 = (function0) _983_sum_down;
    _981_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _981_t1 = _981_t0(_981_t2);
    $line_idx--;
    _981_t3 = 2;
    _981_$retval = $add_int64_t(_981_t1, _981_t3, "tests/integration/functions/mut-param-addrof.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _981_$retval;
}

int64_t _983_sum_down(int64_t _983_x){
    int64_t _985_i;
    int64_t _983_t2;
    uint8_t _983_t3;
    function1 _983_t4;
    int64_t* _983_t6;
    int64_t _983_t7;
    int64_t _983_$retval;
    _985_i = _983_x;
    goto BB1157;
BB1157:
    _983_t2 = 0;
    _983_t3 = _985_i>=_983_t2;
    if (_983_t3) {
        goto BB1158;
    } else {
        goto BB1163;
    }
BB1158:
    _983_t4 = (function1) _988_inc;
    _983_t6 = &_983_x;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:6:13:\n        inc(&mut x, i)\n           ^";
    (void) _983_t4(_983_t6, _985_i);
    $line_idx--;
    _983_t7 = 1;
    _985_i = $sub_int64_t(_985_i, _983_t7, "tests/integration/functions/mut-param-addrof.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1157;
BB1163:
    _983_$retval = _983_x;
    return _983_$retval;
}

void _988_inc(int64_t* _988_x, int64_t _988_i){
    *_988_x = $add_int64_t(*_988_x, _988_i, "tests/integration/functions/mut-param-addrof.orng:11:42:\nfn inc(x: &mut Int, i: Int) -> () { x^ += i }\n                                        ^");
    return;
}


int main(void) {
  printf("%ld",_981_main());
  return 0;
}
