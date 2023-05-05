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
  /*
  * you should have a loop to listen for incoming actions from clients
  * send client sockets for voice chat and use them
  */

  TCPsocket clientSock1;

  /*
  * here you have to select the person to whom you want to send the sound buffer
  */

  TCPsocket clientSock2;
  SCVCG_2D_server_send(clientSock1, clientSock2);

  //releasing resources occupied by the library
  SCVCG_cleanup();
  
  return 1;
}