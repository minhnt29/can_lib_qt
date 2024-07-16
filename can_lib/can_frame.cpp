//
// Created by minh on 7/16/2024.
//

#include "can_frame.h"

uint8_t CANFrame::crc8(const quint8 data[], size_t len) {
    quint8 crc = kMask;
    for (size_t idx = 0; idx < len; idx++) {
        quint8 temp_val = crc ^ data[idx];
        crc = CRC8_J1850_TABLE[temp_val];
    }
    crc = crc ^ kMask;
    return crc;
}
