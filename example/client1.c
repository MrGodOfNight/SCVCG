/*
* Copyright 2023 Ushakov Igor
*
*   Licensed under the Apache License, Version 2.0 (the "License");
*   you may not use this file except in compliance with the License.
*   You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
*/



// include the SCVCG library
#include "../include/SCVCG.h"



int main()
{
  SCVCG_init();
  // get server socket for record
  TCPsocket client1rec = SCVCG_connect("127.0.0.1", 8000);
  // get server socket for receive
  TCPsocket client1rece = SCVCG_connect("127.0.0.1", 8000);

  /*
  * pressing the microphone button
  * check if the button is pressed
  * if it is pressed, then we call the function of sending audio to the server
  * if it is unpressed, then we call the function of stopping sending audio to the server
  */
  int pressButton = 1;
  if (pressButton == 1)
  {
    SCVCG_2D_start_send(client1rec);
  }
  else
  {
    //be careful, this function closes the socket
    SCVCG_2D_stop_send(client1rec);
  }

  //there should be a code that listens for data from the server

  /*
  * this variable will indicate the receipt of audio data from the server
  * if data is not transmitted, then it changes
  */
  int getData = 1;
  if (getData == 1)
  {
    SCVCG_2D_start_receive(client1rece, 128);
  }
  else
  {
    //be careful, this function closes the socket
    SCVCG_2D_stop_receive(client1rece);
  }

  //releasing resources occupied by the library
  SCVCG_cleanup();
  
  return 0;
}