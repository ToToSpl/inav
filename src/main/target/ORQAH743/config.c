/*
 * This file is part of INAV.
 *
 * INAV is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * INAV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with INAV.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdint.h>
#include <platform.h>

#include "fc/config.h"
#include "drivers/sound_beeper.h"

#include "fc/fc_msp_box.h"
#include "io/piniobox.h"
#include "io/serial.h"


void targetConfiguration(void)
{
    beeperConfigMutable()->pwmMode = true;
    pinioBoxConfigMutable()->permanentId[0] = BOX_PERMANENT_ID_USER4;


    /*
     * UART6 is SerialRX
     */
    serialConfigMutable()->portConfigs[findSerialPortIndexByIdentifier(SERIAL_PORT_USART6)].functionMask = FUNCTION_RX_SERIAL;
    serialConfigMutable()->portConfigs[findSerialPortIndexByIdentifier(SERIAL_PORT_USART7)].functionMask = FUNCTION_GPS;


}
