/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

/*
 * GPIO API
 */

#ifndef CS_FW_SRC_MIOT_GPIO_H_
#define CS_FW_SRC_MIOT_GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* GPIO mode */
enum gpio_mode {
  GPIO_MODE_INOUT = 0,
  GPIO_MODE_INPUT = 1,
  GPIO_MODE_OUTPUT = 2
};

/* GPIO pull type */
enum gpio_pull_type {
  GPIO_PULL_FLOAT = 0,
  GPIO_PULL_PULLUP = 1,
  GPIO_PULL_PULLDOWN = 2
};

/* GPIO interrupt mode */
enum gpio_int_mode {
  GPIO_INTR_OFF = 0,
  GPIO_INTR_POSEDGE = 1,
  GPIO_INTR_NEGEDGE = 2,
  GPIO_INTR_ANYEDGE = 3,
  GPIO_INTR_LOLEVEL = 4,
  GPIO_INTR_HILEVEL = 5
};

/* GPIO voltage level */
enum gpio_level {
  GPIO_LEVEL_ERR = -1,
  GPIO_LEVEL_LOW = 0,
  GPIO_LEVEL_HIGH = 1
};

/* GPIO interrupt handler */
typedef void (*f_gpio_intr_handler_t)(int pin, enum gpio_level level,
                                      void *param);

/* Set GPIO interrup mode */
int miot_gpio_intr_set(int pin, enum gpio_int_mode type);

/* Set GPIO mode */
int miot_gpio_set_mode(int pin, enum gpio_mode mode, enum gpio_pull_type pull);

/* Set GPIO voltage level */
int miot_gpio_write(int pin, enum gpio_level level);

/* Get GPIO voltage level */
enum gpio_level miot_gpio_read(int pin);

/* Set GPIO interrupt handler */
void miot_gpio_intr_init(f_gpio_intr_handler_t cb, void *arg);

/* Re-enable GPIO interrupts */
void miot_reenable_intr(int pin);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CS_FW_SRC_MIOT_GPIO_H_ */
