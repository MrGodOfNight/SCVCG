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



static int paCallback(const void *inputBuffer, void *outputBuffer, 
unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, 
PaStreamCallbackFlags statusFlags, void *userData)
{
  float *rptr = (float*)inputBuffer;
  float *wptr = &data[numSamples];
  int framesLeft = framesPerBuffer;
  (void) outputBuffer;  
  // copying data from the input buffer to the write buffer
  while (framesLeft > 0) 
  {
    int framesToProcess = (framesLeft < numSamples) ? framesLeft : numSamples;
    for (int i = 0; i < framesToProcess; i++) 
    {
      *wptr++ = *rptr++;
    }
    framesLeft -= framesToProcess;
  }
  numSamples += framesPerBuffer; // update the number of recorded samples
  return paContinue; // returns the write continuation status code
}

void prepareData() 
{
  int numBytes;
  numSamples = NUM_SECONDS * SAMPLE_RATE; // calculate the total number of samples to record
  numBytes = numSamples * sizeof(float); // calculate the size of the memory buffer in bytes
  data = (float*)malloc(numBytes); // allocate memory for the data buffer
}

void SCVCG_start_rec() 
{
  // initializing the PortAudio System
  PaError err = Pa_Initialize();
  if (err != paNoError) 
  {
    printf("Error initializing PortAudio: %s", Pa_GetErrorText(err));
    return;
  }

  // opening a stream for writing
  err = Pa_OpenDefaultStream(&stream, NUM_CHANNELS, 0, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, paCallback, NULL);
  if (err != paNoError) 
  {
    printf("Error opening default stream: %s", Pa_GetErrorText(err));
    return;
  }

  // starting a stream for writing
  err = Pa_StartStream(stream);
  if (err != paNoError) 
  {
    printf("Error starting stream: %s", Pa_GetErrorText(err));
    return;
  }
}

void SCVCG_stop_rec()
{
  // stop stream for writing
  PaError err = Pa_StopStream(stream);
  if (err != paNoError) 
  {
    printf("Error stopping stream: %s", Pa_GetErrorText(err));
    return;
  }

  // close the stream for writing
  err = Pa_CloseStream(stream);
  if (err != paNoError) 
  {
    printf("Error closing stream: %s", Pa_GetErrorText(err));
    return;
  }
}