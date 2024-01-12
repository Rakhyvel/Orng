/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct2;

/* Typedefs */
typedef int64_t(*function0)(int64_t);

struct struct2 {
    int64_t* _0;
    int64_t _1;
};

typedef void(*function1)(int64_t*, int64_t);

/* Function forward definitions */
int64_t _964_main(void);
int64_t _966_sum_down(int64_t _966_x);
void _971_inc(int64_t* _971_x, int64_t _971_i);

/* Function definitions */
int64_t _964_main(void){
    function0 _964_t0;
    int64_t _964_t2;
    int64_t _964_t1;
    int64_t _964_t3;
    int64_t _964_$retval;
    _964_t0 = _966_sum_down;
    _964_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _964_t1 = _964_t0(_964_t2);
    $line_idx--;
    _964_t3 = 2;
    _964_$retval = $add_int64_t(_964_t1, _964_t3, "tests/integration/functions/mut-param-addrof.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _964_$retval;
}

int64_t _966_sum_down(int64_t _966_x){
    int64_t _968_i;
    int64_t _966_t1;
    uint8_t _966_t2;
    function1 _966_t3;
    int64_t* _966_t5;
    int64_t _966_t6;
    int64_t _966_$retval;
    _968_i = _966_x;
    goto BB1169;
BB1169:
    _966_t1 = 0;
    _966_t2 = _968_i>=_966_t1;
    if (_966_t2) {
        goto BB1170;
    } else {
        goto BB1175;
    }
BB1170:
    _966_t3 = _971_inc;
    _966_t5 = &_966_x;
    $lines[$line_idx++] = "tests/integration/functions/mut-param-addrof.orng:6:13:\n        inc(&mut x, i)\n           ^";
    (void) _966_t3(_966_t5, _968_i);
    $line_idx--;
    _966_t6 = 1;
    _968_i = $sub_int64_t(_968_i, _966_t6, "tests/integration/functions/mut-param-addrof.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1169;
BB1175:
    _966_$retval = _966_x;
    return _966_$retval;
}

void _971_inc(int64_t* _971_x, int64_t _971_i){
    *_971_x = $add_int64_t(*_971_x, _971_i, "tests/integration/functions/mut-param-addrof.orng:11:42:\nfn inc(x: &mut Int, i: Int) -> () { x^ += i }\n                                        ^");
    return;
}

int main(void) {
  printf("%ld",_964_main());
  return 0;
}
