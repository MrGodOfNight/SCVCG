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



/*
* including headers of the library itself
*/
#include "../include/SCVCG.h"
#include "headers/server.h"
#include "headers/record.h"
#include "headers/reproduction.h"
#include "headers/client.h"

/*
* connecting various headers and libs
*/
#include <al.h>
#include <alc.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_net.h>



#define MAX_PACKET_SIZE 1024 // maximum packet size

void SCVCG_2D_server_send(TCPsocket sender, TCPsocket recipient) 
{
  char buffer[MAX_PACKET_SIZE];
  int received = SDLNet_TCP_Recv(sender, buffer, MAX_PACKET_SIZE);   // getting data from sender
  if (received <= 0) 
  {
    return;
  }
  if (SDLNet_TCP_Send(recipient, buffer, received) < received) // send data to recipient
  {     
    printf("Error sending data: %s", SDLNet_GetError());
  }
  SDL_Delay(10);
}