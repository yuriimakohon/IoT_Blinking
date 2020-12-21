/* For usleep() */
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <stdlib.h>
#include <ti/drivers/TRNG.h>
#include <ti/drivers/cryptoutils/cryptokey/CryptoKeyPlaintext.h>

/* Driver configuration */
#include "ti_drivers_config.h"

#define KEY_LENGTH_BYTES 16

TRNG_Handle handle;
int_fast16_t result;

CryptoKey entropyKey;
uint8_t entropyBuffer[KEY_LENGTH_BYTES];

/*
 *  ======== mainThread ========
 */

void errorBlink(useconds_t t)
{
    while(1) {
        usleep(t);
        GPIO_toggle(CONFIG_GPIO_LED_0);
    }
}

void *mainThread(void *arg0)
{
    GPIO_init();

    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);

    /* Generating seed for srand() */
    TRNG_init();
    handle = TRNG_open(0, NULL);

    if (!handle)
        errorBlink(50000);

    CryptoKeyPlaintext_initBlankKey(&entropyKey, entropyBuffer, KEY_LENGTH_BYTES);
    result = TRNG_generateEntropy(handle, &entropyKey);

    if (result != TRNG_STATUS_SUCCESS)
        errorBlink(100000);

    TRNG_close(handle);

    unsigned int seed = 0;
    int i;
    for (i = 0; i < KEY_LENGTH_BYTES; i++)
        seed += entropyBuffer[i];

    srand(seed);
    while (1) {
        sleep(1 + (rand() % 10));
        GPIO_toggle(CONFIG_GPIO_LED_0);
    }
}
