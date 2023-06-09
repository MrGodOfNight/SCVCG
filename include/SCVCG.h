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



#ifndef SCVCG_H
#define SCVCG_H

#if defined(__cplusplus)
extern "C" {
#endif



typedef struct _TCPsocket *TCPsocket;

/*
* library initialization
*/
int SCVCG_init();



// all server functions:

/**
* server function to send sound from one user to another
* @param sender sender socket
* @param recipient recipient socket
*/
void SCVCG_2D_server_send(TCPsocket sender, TCPsocket recipient);



//all client functions:

/**
* client-server connection function. Function that takes the string ip and the number port as arguments, and returns an object of type TCPsocket
* @param ip Server IP
* @param port Server Port
*/
TCPsocket SCVCG_connect(char* ip, int port);

/**
* start sending sound to server
* @param sender sender socket
*/
void SCVCG_2D_start_send(TCPsocket sender);

/**
* stopping the Audio Receive Stream
* @param sender sender socket
*/
void SCVCG_2D_stop_send(TCPsocket sender);

/**
* starting an Audio Playback Stream
* @param recipient recipient socket
* @param volume volume from 0 to 128
*/
void SCVCG_2D_start_receive(TCPsocket recipient, int volume);

/**
* stop audio playback stream
* @param recipient recipient socket
*/
void SCVCG_2D_stop_receive(TCPsocket recipient);

/*
* releasing resources occupied by the library
*/
void SCVCG_cleanup();



#if defined(__cplusplus)
}  /* extern "C" */
#endif

#endif // SCVCG_H