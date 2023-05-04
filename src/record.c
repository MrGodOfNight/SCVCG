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



#include "headers/record.h"
#include <SDL.h>
#include <SDL_net.h>
#include <SDL_mixer.h>



// Определяем структуру для чтения аудиопакетов
typedef struct {
  Uint8 *data;            // Данные аудиопакета
  Uint32 length;          // Длина пакета
  Uint32 position;        // Позиция текущего чанка
} audio_packet;

// Функция, инициализирующая SDL, SDL_mixer и SDL_net для записи и передачи потокового аудио
void SCVCG_2D_start_send(TCPsocket sender, TCPsocket recipient) 
{
  // Запускаем запись аудио
  Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, AUDIO_S16SYS, 2, 1024);
  Mix_AllocateChannels(1);
  int stream_channel = Mix_PlayChannel(-1, NULL, 0);
  // Записываем аудио в буфер и сразу отправляем его на получателя
  audio_packet packet;
  while (1) 
  {//как преобразовать uint32 к int в с?
    Mix_Chunk *audioChunk;
    audioChunk = Mix_GetChunk(stream_channel);
    // Получаем текущий чанк аудио
    packet.position = 0;
    packet.length = audioChunk->alen;
    packet.data = audioChunk->abuf;
    if (SDLNet_TCP_Send(sender, packet.data, packet.length) < (int)packet.length) 
    {
      printf("Ошибка при отправке данных: %s", SDLNet_GetError());
    }
    send(sender, recipient);
  }
}

void SCVCG_2D_stop_send(TCPsocket sender)
{
  Mix_CloseAudio();
  stop_send(sender);
}