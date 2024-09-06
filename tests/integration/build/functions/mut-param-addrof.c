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
int64_t _962_main(void);
int64_t _964_sum_down(int64_t _964_x);
void _969_inc(int64_t* _969_x, int64_t _969_i);


/* Function definitions */
int64_t _962_main(void){
    function0 _962_t0;
    int64_t _962_t2;
    int64_t _962_t1;
    int64_t _962_t3;
    int64_t _962_$retval;
    _962_t0 = (function0) _964_sum_down;
    _962_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _962_t1 = _962_t0(_962_t2);
    $line_idx--;
    _962_t3 = 2;
    _962_$retval = $add_int64_t(_962_t1, _962_t3, "tests/integration/functions/mut-param-addrof.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _962_$retval;
}

int64_t _964_sum_down(int64_t _964_x){
    int64_t _966_i;
    int64_t _964_t2;
    uint8_t _964_t3;
    function1 _964_t4;
    int64_t* _964_t6;
    int64_t _964_t7;
    int64_t _964_$retval;
    _966_i = _964_x;
    goto BB1135;
BB1135:
    _964_t2 = 0;
    _964_t3 = _966_i>=_964_t2;
    if (_964_t3) {
        goto BB1136;
    } else {
        goto BB1141;
    }
BB1136:
    _964_t4 = (function1) _969_inc;
    _964_t6 = &_964_x;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:6:13:\n        inc(&mut x, i)\n           ^";
    (void) _964_t4(_964_t6, _966_i);
    $line_idx--;
    _964_t7 = 1;
    _966_i = $sub_int64_t(_966_i, _964_t7, "tests/integration/functions/mut-param-addrof.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1135;
BB1141:
    _964_$retval = _964_x;
    return _964_$retval;
}

void _969_inc(int64_t* _969_x, int64_t _969_i){
    *_969_x = $add_int64_t(*_969_x, _969_i, "tests/integration/functions/mut-param-addrof.orng:11:42:\nfn inc(x: &mut Int, i: Int) -> () { x^ += i }\n                                        ^");
    return;
}


int main(void) {
  printf("%ld",_962_main());
  return 0;
}
