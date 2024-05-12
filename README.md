The music player application is designed to provide basic functionalities for playing music files. 
Users can select a song, control playback options such as play, pause, fast forward, adjust speed, 
and manage volume. Additionally, the application prompts users to select another song to play 
once the current song is finished.
File Handling:
- Encapsulation: Ensures data security and prevents unauthorized access by
encapsulating file handling functions within the `MusicPlayer` class.
Functions Created:
1. `choose Song(): Allows the user to select a song from the file system.
2. playSong(): Initiates playing the selected song
3. pauseSong(): Pauses the currently playing song.
4. fastForward(): Skips forward in the current song.
5. normalSpeed(): Sets the playback speed to normal.
6. increaseVolume(): Increases the volume of the playing song.
7. decreaseVolume(): Decreases the volume of the playing song.
8. playAnotherSong(): Prompts the user to choose another song to play after the current song 
ends.
Classes Created:
 9. MusicPlayer class to encapsulate file handling functionalities.
10.Variables/Objects Created:
 11.std::fstream fileHandler: For handling file operations.
 12. int currentVolume: Stores the current volume level.
 13. std::string currentSong: Holds the path or name of the currently playing song.
 14.#if,#else,#elif :use of preprocessor directives
 15.Use of #include<iostream> for input and output data
