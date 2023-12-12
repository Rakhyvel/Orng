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

typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
} struct2;

typedef struct2(*function0)(int64_t, int64_t);

typedef struct {
    int64_t _0;
    int64_t* _1;
} struct3;

/* Function forward definitions */
int64_t _1155_main(void);
struct2 _1157_get_array(int64_t _1157_a,int64_t _1157_b);

/* Function definitions */
int64_t _1155_main(void) {
    function0 _1155_t0;
    int64_t _1155_t2;
    int64_t _1155_t3;
    struct2 _1155_t1;
    int64_t _1156_z;
    int64_t* _1155_t7;
    struct3 _1156_y;
    int64_t _1155_$retval;
    _1155_t0 = _1157_get_array;
    _1155_t2 = 15;
    _1155_t3 = 16;
    $lines[$line_idx++] = "tests/integration/tuples/mix.orng:3:31:\n    let x: [4]Int = get_array(15, 16)\n                             ^";
    _1155_t1 = _1155_t0(_1155_t2, _1155_t3);
    $line_idx--;
    (void)_1155_t1;
    _1156_z = 64;
    _1155_t7 = &_1156_z;
    _1156_y = (struct3) {_1156_z, _1155_t7};
    _1155_$retval = _1156_y._0;
    return _1155_$retval;
}

struct2 _1157_get_array(int64_t _1157_a,int64_t _1157_b) {
    struct2 _1157_$retval;
    _1157_$retval = (struct2) {_1157_a, _1157_b, _1157_a, _1157_b};
    return _1157_$retval;
}

int main(void) {
  printf("%ld",_1155_main());
  return 0;
}
