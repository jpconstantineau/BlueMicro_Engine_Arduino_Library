#include <Arduino.h>
#include <Adafruit_TinyUSB.h> // for Serial
#include <bluemicro_engine.h>

/* These should be part of the library and included as extern in the header file.
commandlist_t commandList; 
commandqueue_t setupQueue;
commandqueue_t commandQueue;
commandqueue_t loopQueue;*/

void setup() {
    // map of all possible commands
    // Put all the commands you want to define here
    SETUPCOMMAND(commandList, 0 , pinMode(LED_BUILTIN, OUTPUT));
    SETUPCOMMAND(commandList, 10, digitalWrite(LED_BUILTIN, HIGH));
    SETUPCOMMAND(commandList, 20, delay(250));
    SETUPCOMMAND(commandList, 30, digitalWrite(LED_BUILTIN, LOW));
    SETUPCOMMAND(commandList, 40, delay(250));


    // these are the commands that are run once - during the setup call
    // Put all the commands you want to run at the end of setup here
    ADDCOMMAND(setupQueue, 0 );

    
    // these are the command that are run for every scan - during the loop call
    // Put all the commands you want to run in the loop here
    ADDCOMMAND(loopQueue, 10 );
    ADDCOMMAND(loopQueue, 20 );
    ADDCOMMAND(loopQueue, 30 );
    
    // This command makes sure that all commands prepared for the setup are run
    run_setup_commands(); 
}

void loop() {
  // these are the commands that are additionnal to every scan
  // Put all the commands you want to run in the loop here

  ADDCOMMAND(commandQueue, 40 );

  // ideally, this is the only command you need to run all the commands you have setup previously.
  // interval is 1000 ms (1 second) 
  processing_loop(1000);
}
