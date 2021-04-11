#include <zephyr/types.h>

//UUID service declaration
#define BT_UUID_SERVICE_VAL BT_UUID_128_ENCODE(0x00001526, 0x1212, 0xefde, 0x1523, 0x785feabcd123)
#define BT_UUID_SERVICE BT_UUID_DECLARE_128 (BT_UUID_SERVICE_VAL)

//UUID Led characteristic declaration
#define BT_UUID_I2C_VAL BT_UUID_128_ENCODE(0x00001527, 0x1212, 0xefde, 0x1523, 0x785feabcd123)
#define BT_UUID_I2C BT_UUID_DECLARE_128 (BT_UUID_I2C_VAL)

//Callback declaration
typedef int8_t(*i2c_cb_t) (void);
struct bt_i2cService_cb{i2c_cb_t i2c_cb;};

int bt_i2cService_init (struct bt_i2cService_cb *callbacks);