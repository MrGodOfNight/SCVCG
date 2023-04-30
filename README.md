# SCVCG
SCVCG (Simple C Voice Chat for Games) is a library written in C that you can add to your game (or just an application). 
## It is planned to add:
1. 3D sound.
2. Support for the density of the object to dampen the sound.
3. Pure 2D sound.

### The project is educational, but it would be great if you get inspired to create it and help me.
### Made by Ushakov Igor.


## How to compile a library?
1. You need to write 'git clone' to the console and add a link to the project.
2. Write 'git submodule update --init' to the console to include all submodules in the project.
3. Copy and rename, but don't delete file '.CMakeLists.txt' to 'CMakeLists.txt'.
4. Install the OpenAL SDK on your computer and write the full path to the OpenAL headers and .lib file in the CMakeLists.txt file(OPENAL_INCLUDE_DIR and OPENAL_LIBRARY).
5. Compile this via CMake.