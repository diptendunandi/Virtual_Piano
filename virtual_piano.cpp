#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

class Piano {
public:
    // SFML related variables
    sf::RenderWindow window;
    std::vector<sf::RectangleShape> whiteKeys;
    std::vector<sf::RectangleShape> blackKeys;
    std::vector<sf::SoundBuffer> soundBuffers;
    std::vector<sf::Sound> sounds;

    Piano() {
        window.create(sf::VideoMode(800, 400), "Virtual Piano");

        // Initialize the piano keys
        initKeys();

        // Load sound files for each key (0 to 11 for white and black keys)
        for (size_t i = 0; i < 12; ++i) {
            sf::SoundBuffer buffer;
            if (!buffer.loadFromFile("piano_key_" + std::to_string(i) + ".wav")) {
                std::cerr << "Error loading sound: piano_key_" + std::to_string(i) + ".wav" << std::endl;
            }
            soundBuffers.push_back(buffer);
            sounds.push_back(sf::Sound());
            sounds[i].setBuffer(soundBuffers[i]);
        }
    }

    void initKeys() {
        // White Keys (Rectangles)
        for (int i = 0; i < 7; ++i) {  // 7 white keys (C, D, E, F, G, A, B)
            sf::RectangleShape key(sf::Vector2f(100, 300));
            key.setPosition(i * 120, 50);
            key.setFillColor(sf::Color::White);
            key.setOutlineColor(sf::Color::Black);
            key.setOutlineThickness(2);
            whiteKeys.push_back(key);
        }

        // Black Keys (Rectangles)
        for (int i = 0; i < 5; ++i) {  // 5 black keys (C#, D#, F#, G#, A#)
            if (i != 2) {  // Skip the position between E and F, since no black key exists here
                sf::RectangleShape key(sf::Vector2f(60, 200));
                key.setPosition(i * 120 + 90, 50);
                key.setFillColor(sf::Color::Black);
                blackKeys.push_back(key);
            }
        }
    }

    void playSound(int keyIndex) {
        if (keyIndex >= 0 && keyIndex < sounds.size()) {
            sounds[keyIndex].play();
        }
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // Draw the piano keys
            window.clear(sf::Color::Green);

            for (auto& key : whiteKeys) {
                window.draw(key);
            }
            for (auto& key : blackKeys) {
                window.draw(key);
            }

            window.display();

            // Handle mouse clicks
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                int keyIndex = checkKey(mousePos.x, mousePos.y);
                if (keyIndex != -1) {
                    playSound(keyIndex);
                }
            }
        }
    }

    int checkKey(int x, int y) {
        // Check if mouse is over any white keys
        for (int i = 0; i < 7; ++i) {
            if (x >= whiteKeys[i].getPosition().x && x <= whiteKeys[i].getPosition().x + whiteKeys[i].getSize().x &&
                y >= whiteKeys[i].getPosition().y && y <= whiteKeys[i].getPosition().y + whiteKeys[i].getSize().y) {
                return i;  // White keys are numbered 0 to 6
            }
        }

        // Check if mouse is over any black keys
        for (int i = 0; i < 5; ++i) {
            if (x >= blackKeys[i].getPosition().x && x <= blackKeys[i].getPosition().x + blackKeys[i].getSize().x &&
                y >= blackKeys[i].getPosition().y && y <= blackKeys[i].getPosition().y + blackKeys[i].getSize().y) {
                return i + 7;  // Black keys are numbered 7 to 11
            }
        }

        return -1;  // No key clicked
    }
};

int main() {
    Piano piano;
    piano.run();

    return 0;
}
