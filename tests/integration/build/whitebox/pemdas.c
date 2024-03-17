/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1838_main(void);


/* Function definitions */
int64_t _1838_main(void){
    int64_t _1839_x;
    int64_t* _1839_y;
    int64_t _1838_t5;
    uint8_t _1838_t7;
    int64_t _1838_t4;
    int64_t _1838_$retval;
    int64_t _1841_z;
    int64_t* _1838_t10;
    int64_t _1838_t13;
    int64_t _1838_t14;
    int64_t _1838_t16;
    int64_t _1838_t17;
    int64_t _1838_t20;
    _1839_x = 0;
    _1839_y = &_1839_x;
    _1838_t5 = 0;
    _1838_t7 = *_1839_y==_1838_t5;
    if (_1838_t7) {
        goto BB2074;
    } else {
        goto BB2078;
    }
BB2074:
    _1841_z = *_1839_y;
    _1838_t10 = &_1841_z;
    *_1838_t10 = $add_int64_t(_1841_z, _1841_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1841_z = $sub_int64_t(_1841_z, _1841_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1841_z = $mult_int64_t(_1841_z, _1841_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1838_t13 = 1;
    _1838_t14 = $add_int64_t(_1841_z, _1838_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1841_z = $div_int64_t(_1841_z, _1838_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1838_t16 = 1;
    _1838_t17 = $add_int64_t(_1841_z, _1838_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1841_z = $mod_int64_t(_1841_z, _1838_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1838_t20 = -1;
    _1841_z = $mult_int64_t(_1841_z, _1838_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1838_t4 = $mult_int64_t(_1841_z, _1838_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2077;
BB2078:
    _1838_t4 = 1000;
    goto BB2077;
BB2077:
    _1838_$retval = _1838_t4;
    return _1838_$retval;
}


int main(void) {
  printf("%ld",_1838_main());
  return 0;
}
