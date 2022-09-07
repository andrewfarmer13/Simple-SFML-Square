#include <SFML/Graphics.hpp>
#include <iostream>




int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 720), "SFML works!");
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Green);

    sf::Vector2f rectanglePos(600, 350);
    shape.setPosition(rectanglePos);
    shape.setSize(sf::Vector2f(100, 100));

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString("Andrew's Square");
    text.setFillColor(sf::Color::Green);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    text.setPosition(sf::Vector2f(1200 / 2.0f, 40 / 2.0f));

    float x_velocity = 4;
    float y_velocity = 4;

    while (window.isOpen())
    {
        sf::Event event;
        //sf::Clock clock;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                rectanglePos.x += x_velocity;
                shape.setPosition(rectanglePos);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
                rectanglePos.x -= x_velocity;
                shape.setPosition(rectanglePos);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                rectanglePos.y -= y_velocity;
                shape.setPosition(rectanglePos);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                rectanglePos.y += y_velocity;
                shape.setPosition(rectanglePos);
            }
        }
        //Physics//
        //Checks for bounds
       /* if (rectanglePos.x < 0 || rectanglePos.x > 1200-100) {
            x_velocity *= -1;
        }
        if (rectanglePos.y < 0 || rectanglePos.y > 720-100) {
            y_velocity *= -1;
        }*/

        ////This does the moving 
        /*rectanglePos.x += x_velocity;
        rectanglePos.y += y_velocity;
        shape.setPosition(rectanglePos);*/

        window.clear();
        window.draw(shape);
        window.draw(text);
        window.display();
    }



    return 0;
}