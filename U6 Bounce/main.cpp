#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Bounce");
    window.setFramerateLimit(60);

    sf::CircleShape ball(30);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(400, 0);  

    float gravity = 0.5f;
    float velocity = 0.0f;
    float bounceFactor = 0.8f;  

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        velocity += gravity;

        ball.move(0, velocity);

        if (ball.getPosition().y + ball.getRadius() * 2 > window.getSize().y) {

            velocity = -velocity * bounceFactor;

            ball.setPosition(ball.getPosition().x, window.getSize().y - ball.getRadius() * 2);
        }

        window.clear();

        window.draw(ball);

        window.display();
    }

    return 0;
}
