/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

inline static void $panic(const char *restrict msg) {
    fprintf(stderr, "panic: %s\n", msg);
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
}

inline static void $bounds_check(const int64_t idx, const int64_t length, const char *restrict line) {
    if (0 > idx || idx >= length) {
        $lines[$line_idx++] = line;
        $panic("bounds check failed");
    }
}

inline static void $tag_check(const int64_t tag, const int64_t sel, const char *restrict line) {
    if (tag != sel) {
        $lines[$line_idx++] = line;
        $panic("inactive field");
    }
}
/* Typedefs */
typedef struct {
    uint64_t tag;
} struct0;

/* Function forward definitions */
int64_t _1_main();
struct0 _3_f(int64_t* _3_x,uint8_t _3_fail);

/* Function definitions */
int64_t _1_main() {
    int64_t _2_z;
    int64_t _2_y;
    int64_t* _1_t3;
    struct0 _1_t2;
    int64_t* _1_t6;
    struct0 _1_t5;
    int64_t _1_$retval;
    _2_z = 10;
    _2_y = 10;
    _1_t3 = &_2_z;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:5:7:\n    f(&mut z, true)\n     ^";
    _1_t2 = _3_f(_1_t3, 1);
    $line_idx--;
    _1_t6 = &_2_y;
    $lines[$line_idx++] = "tests/integration/errors/passive-errdefer.orng:6:7:\n    f(&mut y, false)\n     ^";
    _1_t5 = _3_f(_1_t6, 0);
    $line_idx--;
    _1_$retval = _2_z + _2_y;
    return _1_$retval;
}

struct0 _3_f(int64_t* _3_x,uint8_t _3_fail) {
    struct0 _3_$retval;
    **&_3_x = 6;
    if (_3_fail) {
        goto BB8;
    } else {
        goto BB9;
    }
BB8:
    **&_3_x = *_3_x + 100;
    **&_3_x = *_3_x + 9;
    return _3_$retval;
BB9:
    _3_$retval = (struct0) {.tag=1};
    return _3_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
