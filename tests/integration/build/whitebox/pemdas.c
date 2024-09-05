/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _74_main(void);


/* Function definitions */
int64_t _74_main(void){
    int64_t _75_x;
    int64_t* _75_y;
    int64_t _74_t5;
    uint8_t _74_t7;
    int64_t _74_t4;
    int64_t _74_$retval;
    int64_t _77_z;
    int64_t* _74_t10;
    int64_t _74_t13;
    int64_t _74_t14;
    int64_t _74_t16;
    int64_t _74_t17;
    int64_t _74_t20;
    _75_x = 0;
    _75_y = &_75_x;
    _74_t5 = 0;
    _74_t7 = *_75_y==_74_t5;
    if (_74_t7) {
        goto BB117;
    } else {
        goto BB121;
    }
BB117:
    _77_z = *_75_y;
    _74_t10 = &_77_z;
    *_74_t10 = $add_int64_t(_77_z, _77_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _77_z = $sub_int64_t(_77_z, _77_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _77_z = $mult_int64_t(_77_z, _77_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _74_t13 = 1;
    _74_t14 = $add_int64_t(_77_z, _74_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _77_z = $div_int64_t(_77_z, _74_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _74_t16 = 1;
    _74_t17 = $add_int64_t(_77_z, _74_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _77_z = $mod_int64_t(_77_z, _74_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _74_t20 = -1;
    _77_z = $mult_int64_t(_77_z, _74_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _74_t4 = $mult_int64_t(_77_z, _74_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB120;
BB121:
    _74_t4 = 1000;
    goto BB120;
BB120:
    _74_$retval = _74_t4;
    return _74_$retval;
}


int main(void) {
  printf("%ld",_74_main());
  return 0;
}
