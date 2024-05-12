#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>

class Button {
public:
    sf::Text text;

    Button(const std::string& label, sf::Font& font, sf::Vector2f position, unsigned int charSize = 20) {
        text.setFont(font);
        text.setString(label);
        text.setCharacterSize(charSize);
        text.setPosition(position);
        text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);
    }

    void drawTo(sf::RenderWindow& window) {
        window.draw(text);
    }

    bool isHovered(sf::Vector2i mousePos) {
        return text.getGlobalBounds().contains(mousePos.x, mousePos.y);
    }

    void setColor(sf::Color color) {
        text.setFillColor(color);
    }
};
class MusicPlayer {
private:
    std::vector<std::string> tracks;
    sf::Music music;
    int currentTrack = 0;
    float playbackSpeed = 1.0;

public:
    MusicPlayer(const std::vector<std::string>& trackList) : tracks(trackList) {
        if (!music.openFromFile(tracks[currentTrack])) {
            std::cerr << "Error loading initial track: " << tracks[currentTrack] << std::endl;
            throw std::runtime_error("Failed to load initial track.");
        }
    }

    void play() {
        if (music.getStatus() != sf::Music::Playing) {
            music.play();
        }
    }

    void pause() {
        if (music.getStatus() == sf::Music::Playing) {
            music.pause();
        }
    }

    void nextTrack() {
        currentTrack = (currentTrack + 1) % tracks.size();
        music.stop();
        if (!music.openFromFile(tracks[currentTrack])) {
            std::cerr << "Error loading track: " << tracks[currentTrack] << std::endl;
            throw std::runtime_error("Failed to load track.");
        }
        music.play();
    }

    void fastForward(float seconds) {
        if (music.getPlayingOffset() + sf::seconds(seconds) < music.getDuration()) {
            music.setPlayingOffset(music.getPlayingOffset() + sf::seconds(seconds));
        }
    }

    void adjustSpeed(float adjustment) {
        playbackSpeed = std::min(std::max(playbackSpeed + adjustment, 0.5f), 2.0f);
        music.setPitch(playbackSpeed);
    }

    void adjustVolume(float delta) {
        float newVolume = std::min(std::max(music.getVolume() + delta, 0.f), 100.f);
        music.setVolume(newVolume);
    }
};
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 200), "SFML Music Player", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Could not load font\n";
        return 1;
    }

    MusicPlayer player({"track1.ogg", "track2.ogg","track2.ogg","track3.ogg","track4.ogg"});
    std::vector<Button> buttons = {
        Button("Play", font, {50, 100}),
        Button("Pause", font, {150, 100}),
        Button("Next", font, {250, 100}),
        Button(">>", font, {350, 100}),
        Button("Speed", font, {450, 100}),
        Button("+Vol", font, {550, 100}),
        Button("-Vol", font, {650, 100})
    };
