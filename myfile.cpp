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

