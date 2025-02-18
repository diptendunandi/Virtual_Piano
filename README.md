Virtual Piano

This is a simple virtual piano built using the SFML library, which allows you to play piano sounds by clicking on the piano keys displayed on the screen. Each key corresponds to a sound file (WAV format) that plays when you click on it. This project demonstrates how to use SFML for creating a graphical interface, handling mouse input, and playing audio.
Features:

    Virtual Piano Interface: 7 white piano keys and 5 black piano keys.
    Sound Playback: Each key plays a unique piano note when clicked.
    Mouse Interaction: Click on the piano keys to play sounds.

Requirements:

Before running the program, make sure you have the following dependencies installed:

    SFML (Simple and Fast Multimedia Library):

        SFML is used for graphics, audio, and window handling.

        To install SFML on Linux, use the following commands:

        sudo apt-get update
        sudo apt-get install libsfml-dev

        For other systems, visit the SFML download page for installation instructions.

    Sound Files:
        The program expects .wav files for each piano key to be present in the same directory as the executable.
        You need to have piano_key_0.wav, piano_key_1.wav, piano_key_2.wav, piano_key_3.wav, piano_key_4.wav, piano_key_5.wav, and piano_key_6.wav files for the corresponding piano keys.
        You can find free piano sound files online or record them using tools like Audacity or arecord on Linux.

Setup:

    Clone the repository or download the project files.

    Place your .wav sound files for each piano key (named piano_key_0.wav, piano_key_1.wav, etc.) in the same directory as the project.

    Compile the program:

    If you are using g++ with SFML installed, you can compile the program using the following command:

g++ -o piano piano.cpp -lsfml-graphics -lsfml-window -lsfml-audio

Run the program:

After compilation, run the program using the following command:

    ./piano

    The virtual piano will appear, and you can click on the keys to play different sounds.

Controls:

    Mouse Click: Click on the piano keys to play sounds. The left mouse button is used to trigger the sound.

License:

This project is open-source and released under the MIT License. Feel free to modify and distribute it as you like.
