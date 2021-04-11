#include <zephyr/types.h>
#define MPU_addr 0x68 //I2C address of the MPU-6050


//I2C structure
typedef struct  i2cData {
  float AcX;
  float AcY;
  float AcZ;
  float GyX;
  float GyY;
  float GyZ;
  float Temp;
  }i2cData;

  int8_t input_read(i2cData *sensorData, const struct device *mpu6050);
  void init_mpu(const struct device *mpu6050);