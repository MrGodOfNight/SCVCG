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


#ifndef server_H
#define server_H

#if defined(__cplusplus)
extern "C" {
#endif



/*
* including headers of the library itself
*/
#include "../../include/SCVCG.h"
#include "record.h"
#include "reproduction.h"
#include "client.h"

/*
* connecting various headers and libs
*/
#include <al.h>
#include <alc.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_net.h>



void SCVCG_2D_server_send(TCPsocket sender, TCPsocket recipient);



#if defined(__cplusplus)
}  /* extern "C" */
#endif

#endif // server_H