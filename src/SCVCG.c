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



int SCVCG_init()
{
  //initialize the library SDL
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0) 
  {
    printf("SDL_Init Error: %s", SDL_GetError());
    return 1;
  }

  //initialize the library SDL_mixer
  if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, AUDIO_S16SYS, 2, 1024) != 0) 
  {
    printf("Mix_OpenAudio Error: %s", Mix_GetError());
    return 1;
  }

  //initialize the library SDL_net
  if(SDLNet_Init() != 0) 
  {
    printf("SDLNet_Init Error: %s", SDLNet_GetError());
    return 1;
  }
  
  //initialize the library OpenAL
  ALCdevice *device = alcOpenDevice(NULL);
  if (device == NULL) 
  {
    return -1;
  }

  ALCcontext *context = alcCreateContext(device, NULL);
  if (context == NULL) 
  {
    return -1;
  }

  alcMakeContextCurrent(context);

  return 0;
}

void SCVCG_cleanup()
{
  SDLNet_Quit();
  SDL_Quit();
  ALCcontext *context = alcGetCurrentContext();
  ALCdevice *device = alcGetContextsDevice(context);
  alcMakeContextCurrent(NULL);
  alcDestroyContext(context);
  alcCloseDevice(device);
}