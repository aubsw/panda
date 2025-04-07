#pragma once
#include <stdint.h>
#include "config.h"
#include "can_common_panda.h"
#include "drivers/spi.h"
#include "drivers/usb.h"
/*
   CAN transactions to and from the host come in the form of
   a certain number of CANPacket_t. The transaction is split
   into multiple transfers or chunks.
   * comms_can_read outputs this buffer in chunks of a specified length.
     chunks are always the given length, except the last one.
   * comms_can_write reads in this buffer in chunks.
   * both functions maintain an overflow buffer for a partial CANPacket_t that
     spans multiple transfers/chunks.
   * the overflow buffers are reset by a dedicated control transfer handler,
     which is sent by the host on each start of a connection.
*/

// TODO: make this more general!
#ifndef BOOTSTUB
//static void refresh_can_tx_slots_available(void) {
//  if (can_tx_check_min_slots_free(MAX_CAN_MSGS_PER_USB_BULK_TRANSFER)) {
//    can_tx_comms_resume_usb();
//  }
//  if (can_tx_check_min_slots_free(MAX_CAN_MSGS_PER_SPI_BULK_TRANSFER)) {
//    can_tx_comms_resume_spi();
//  }
//}
#endif

int comms_can_read(uint8_t *data, uint32_t max_len);
void comms_can_write(const uint8_t *data, uint32_t len);
void comms_can_reset(void);
void refresh_can_tx_slots_available(void);
