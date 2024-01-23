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
int64_t _969_main(void);
int64_t _971_sum_down(int64_t _971_x);
void _976_inc(int64_t* _976_x, int64_t _976_i);


/* Function definitions */
int64_t _969_main(void){
    function0 _969_t0;
    int64_t _969_t2;
    int64_t _969_t1;
    int64_t _969_t3;
    int64_t _969_$retval;
    _969_t0 = _971_sum_down;
    _969_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _969_t1 = _969_t0(_969_t2);
    $line_idx--;
    _969_t3 = 2;
    _969_$retval = $add_int64_t(_969_t1, _969_t3, "tests/integration/functions/mut-param-addrof.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _969_$retval;
}

int64_t _971_sum_down(int64_t _971_x){
    int64_t _973_i;
    int64_t _971_t1;
    uint8_t _971_t2;
    function1 _971_t3;
    int64_t* _971_t5;
    int64_t _971_t6;
    int64_t _971_$retval;
    _973_i = _971_x;
    goto BB1173;
BB1173:
    _971_t1 = 0;
    _971_t2 = _973_i>=_971_t1;
    if (_971_t2) {
        goto BB1174;
    } else {
        goto BB1179;
    }
BB1174:
    _971_t3 = _976_inc;
    _971_t5 = &_971_x;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:6:13:\n        inc(&mut x, i)\n           ^";
    (void) _971_t3(_971_t5, _973_i);
    $line_idx--;
    _971_t6 = 1;
    _973_i = $sub_int64_t(_973_i, _971_t6, "tests/integration/functions/mut-param-addrof.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1173;
BB1179:
    _971_$retval = _971_x;
    return _971_$retval;
}

void _976_inc(int64_t* _976_x, int64_t _976_i){
    *_976_x = $add_int64_t(*_976_x, _976_i, "tests/integration/functions/mut-param-addrof.orng:11:42:\nfn inc(x: &mut Int, i: Int) -> () { x^ += i }\n                                        ^");
    return;
}


int main(void) {
  printf("%ld",_969_main());
  return 0;
}
