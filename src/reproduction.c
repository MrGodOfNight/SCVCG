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
#include "headers/record.h"
#include "headers/webWork.h"
#include "headers/reproduction.h"

/*
* connecting various headers and libs
*/
#include <al.h>
#include <alc.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_net.h>



void SCVCG_2D_start_receive(TCPsocket sender, TCPsocket recipient, int volume)
{
  // creating a variable that will store the received data
  char buffer[1024];

  // infinite loop to read data from socket
  while (1) 
  {
    // read data from sender socket and store in buffer
    int received_bytes = SDLNet_TCP_Recv(sender, buffer, sizeof(buffer));

    // if there is no data received, then exit the loop
    if (received_bytes <= 0) 
    {
      break;
    }

    // creating a stream for decoding and playing audio
    SDL_RWops* rw = SDL_RWFromMem(buffer, received_bytes);
    SDL_AudioSpec spec;
    Uint32 length;
    Uint8* buffer_decode;
    Mix_Chunk* chunk;

    // decoding audio and storing it in variables
    SDL_LoadWAV_RW(rw, 1, &spec, &buffer_decode, &length);
    chunk = Mix_QuickLoad_WAV(buffer_decode);
    SDL_FreeWAV(buffer_decode);

    // set playback volume, depending on the value of the volume argument
    Mix_VolumeChunk(chunk, volume);

    // audio playback
    Mix_PlayChannel(-1, chunk, 0);
  }
}

void SCVCG_2D_stop_receive(TCPsocket recipient)
{
  Mix_CloseAudio();
  SDLNet_TCP_Close(recipient);
}