#include <sys/printk.h>
#include <zephyr.h>
#include <zephyr/types.h>

#include "bluetooth.h"
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/conn.h>
#include <bluetooth/uuid.h>
#include <bluetooth/gatt.h>

static struct bt_i2cService_cb i2cService_cb;
int8_t data[14];

static ssize_t read_button(struct bt_conn *conn,
			  const struct bt_gatt_attr *attr,
			  void *buf,
			  uint16_t len,
			  uint16_t offset)
{
	const char *value = attr->user_data;

	LOG_DBG("Attribute read, handle: %u, conn: %p", attr->handle, conn);

	if (i2cService_cb.i2c_cb) {
		data = i2cService_cb.i2c_cb();
		return bt_gatt_attr_read(conn, attr, buf, len, offset, value,
					 sizeof(*value));
	}

	return 0;
}

BT_GATT_SERVICE_DEFINE(i2c_svc,
	BT_GATT_PRIMARY_SERVICE(BT_UUID_ESS),
	BT_GATT_CHARACTERISTIC(BT_UUID_I2C,
			       BT_GATT_CHRC_NOTIFY,
			       BT_GATT_PERM_READ, read_button, NULL,
			       &data),
);

int bt_lbs_init(struct bt_i2cService_cb *callbacks)
{
	if (callbacks) {
		i2cService_cb.i2c_cb = callbacks->i2c_cb;
	}

	return 0;
}