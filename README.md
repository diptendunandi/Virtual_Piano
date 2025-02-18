Virtual Piano with SFML

A simple virtual piano application built using SFML (Simple and Fast Multimedia Library). This program simulates a piano with 12 keys (7 white keys and 5 black keys) and plays corresponding sounds when the user clicks on the keys.
Features

    7 White Keys: Representing natural notes (C, D, E, F, G, A, B).
    5 Black Keys: Representing sharp notes (C#, D#, F#, G#, A#).
    Mouse Interaction: Click on the white and black keys to play corresponding piano sounds.
    Audio Files: Each key is associated with a .wav sound file.

Requirements

    SFML Library: Ensure you have SFML installed on your system.
    Audio Files: This project uses .wav files for each key. Ensure the sound files are correctly named and placed in the project directory.
        The files should be named: piano_key_0.wav, piano_key_1.wav, ..., piano_key_11.wav.
    C++ Compiler: A compatible C++ compiler (e.g., GCC, Clang).

Installation
1. Install SFML

Follow the official SFML installation guide for your platform:

    SFML Download Page

2. Compile the Project

To compile the project, you need to link the SFML libraries. Here's an example of how you can compile and link the program with g++:

g++ -o virtual_piano main.cpp -lsfml-graphics -lsfml-window -lsfml-audio

3. Run the Program

Once compiled, run the program:

./virtual_piano

How to Use

    Start the Application: The application will open a window with a virtual piano layout.
    Play the Piano: Click on any white or black key to play the sound associated with it.
    Close the Application: Click the close button of the window to exit the program.

File Structure

/virtual_piano
|-- main.cpp                # Main C++ source code
|-- README.md               # Project README file
|-- piano_key_0.wav         # Sound file for the first white key (C)
|-- piano_key_1.wav         # Sound file for the second white key (D)
|-- ...                     # Additional sound files for the rest of the keys
|-- piano_key_11.wav        # Sound file for the last black key (A#)

Sound Files

Make sure that you have the following .wav files in your project folder:

    piano_key_0.wav -> C (white key)
    piano_key_1.wav -> D (white key)
    piano_key_2.wav -> E (white key)
    piano_key_3.wav -> F (white key)
    piano_key_4.wav -> G (white key)
    piano_key_5.wav -> A (white key)
    piano_key_6.wav -> B (white key)
    piano_key_7.wav -> C# (black key)
    piano_key_8.wav -> D# (black key)
    piano_key_9.wav -> F# (black key)
    piano_key_10.wav -> G# (black key)
    piano_key_11.wav -> A# (black key)

Troubleshooting

    No sound: Make sure you have the .wav sound files correctly named and placed in the same directory as the executable.
    Missing SFML libraries: Ensure you’ve correctly linked SFML during the compilation.

License

This project is open-source and available under the MIT License. See the LICENSE file for more information.
