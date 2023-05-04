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



/**
* defining a Structure for Reading Audio Packets
* @param data audio packet data
* @param length packet length
* @param position position of the current chunk
*/
typedef struct {
  Uint8 *data;
  Uint32 length;
  Uint32 position;
} audio_packet;

void SCVCG_2D_start_send(TCPsocket sender, TCPsocket recipient) 
{
  Mix_AllocateChannels(1);
  int stream_channel = Mix_PlayChannel(-1, NULL, 0);
  // we write audio to the buffer and immediately send it to the recipient
  audio_packet packet;
  while (1) 
  {
    Mix_Chunk *audioChunk;
    audioChunk = Mix_GetChunk(stream_channel);
    // get current audio chunk
    packet.position = 0;
    packet.length = audioChunk->alen;
    packet.data = audioChunk->abuf;
    if (SDLNet_TCP_Send(sender, packet.data, packet.length) < (int)packet.length) 
    {
      printf("Error sending data: %s", SDLNet_GetError());
    }
    send(sender, recipient);
  }
}

void SCVCG_2D_stop_send(TCPsocket sender)
{
  Mix_CloseAudio();
  stop_send(sender);
}