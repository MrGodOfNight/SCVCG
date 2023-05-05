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



TCPsocket SCVCG_connect(char* ip, int port)
{
  IPaddress address; // defining an address object of type IPaddress
  TCPsocket socket; // defining a socket object of type TCPsocket
  
  if (SDLNet_ResolveHost(&address, ip, port) == -1) // trying to resolve hostname to ip address
  { 
    printf("Error: %s", SDLNet_GetError()); // display an error message if the hostname resolution fails
    return NULL; // return NULL on error
  }

  socket = SDLNet_TCP_Open(&address); // opening a TCP connection to the server at the specified address and storing the results in a socket object
  
  if (!socket) // checking for errors when opening a TCP connection
  { 
    printf("Error: %s", SDLNet_GetError()); // displaying an error message in case of unsuccessful opening of a TCP connection
    return NULL; // return NULL on error
  }
  
  printf("Server connection established"); // displaying a message about successful connection to the server
  
  return socket; // return socket object on success
}