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



#ifndef record_H
#define record_H

#if defined(__cplusplus)
extern "C" {
#endif



#include "../include/SCVCG.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>



/* Значения констант */
#define SAMPLE_RATE  (44100) /* частота дискретизации аудиопотока (в Герцах) */
#define FRAMES_PER_BUFFER (64) /* размер буфера (в кадрах) */
#define NUM_SECONDS     (2) /* продолжительность записи (в секундах) */
#define NUM_CHANNELS    (2) /* количество каналов (1 для моно и 2 для стерео записи) */

/* Начальная инициализация глобальных переменных */
PaStream *stream;
float *data;
int numSamples;


static int paCallback(const void *inputBuffer, void *outputBuffer, 
unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, 
PaStreamCallbackFlags statusFlags, void *userData);

void prepareData();

void SCVCG_2D_start_rec();

void SCVCG_2D_stop_rec();



#if defined(__cplusplus)
}  /* extern "C" */
#endif

#endif // record_H