// SPDX-FileCopyrightText: 2022 BlueMicro_Engine_Arduino_Library contributors (https://github.com/jpconstantineau/BlueMicro_Engine_Arduino_Library/graphs/contributors)
//
// SPDX-License-Identifier: BSD-3-Clause

#include "bluemicro_engine.h"

commandlist_t commandList; 
commandqueue_t setupQueue;
commandqueue_t commandQueue;
commandqueue_t loopQueue;

// command_less is used for sorting
bool command_less (command_t i,command_t j) { return (i.first<j.first); }

void processing_loop(uint32_t interval) {  
  static uint32_t last_timestamp = 0;
  RUNCOMMANDS(loopQueue, commandList);   
  uint32_t end_timestamp = millis();
  uint32_t diff = (last_timestamp + interval > end_timestamp) ? last_timestamp + HIDREPORTINGINTERVAL - end_timestamp:1;
  last_timestamp = end_timestamp;
  delay(diff); 
}

void run_setup_commands(void)
{
    SORTCOMMANDS(commandList);
    RUNCOMMANDS(setupQueue, commandList);
}