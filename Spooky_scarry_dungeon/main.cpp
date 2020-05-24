#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <stdlib.h>


class CustomRectangleShape : public sf::RectangleShape {
public:
    CustomRectangleShape(const sf::Vector2f &size, const sf::Vector2f &position)
        : sf::RectangleShape(size) {
        setPosition(position);
    }

    void setSpeed(float velocity_x, float velocity_y, float angular_velocity) {
        velocity_x_ = velocity_x;
        velocity_y_ = velocity_y;
        angular_velocity_ = angular_velocity;
    }

    void animate(const sf::Time &elapsed) {

        if(is_selected == false) {
            move(elapsed.asSeconds() * velocity_x_, elapsed.asSeconds() * velocity_y_);
            rotate(elapsed.asSeconds() * angular_velocity_);
            bounce();

        }else if(is_selected == true) {
            auto rectangle_bounds = getGlobalBounds();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                std::cout << "Up" << std::endl;
                if(rectangle_bounds.top > top_bound_) {
                    move(0.0, -0.5);
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                std::cout << "Down" << std::endl;
                if(rectangle_bounds.top + rectangle_bounds.height < bottom_bound_) {
                    move(0.0, 0.5);
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                std::cout << "Left" << std::endl;
                if(rectangle_bounds.left > left_bound_) {
                    move(-0.5, 0.0);
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                std::cout << "Right" << std::endl;
                if(rectangle_bounds.left + rectangle_bounds.width < right_bound_) {
                    move(0.5, 0.0);
                }
            }
        }
    }

    void setBounds(const int &left_bound, const int &right_bound, const int &top_bound, const int &bottom_bound) {
        left_bound_ = left_bound;
        right_bound_ = right_bound;
        top_bound_ = top_bound;
        bottom_bound_= bottom_bound;
    }

    void setBounds(const sf::IntRect &bounds) {
        left_bound_ = bounds.left;
        right_bound_ = bounds.left + bounds.width;
        top_bound_ = bounds.top;
        bottom_bound_= bounds.top + bounds.height;
    }

    void select() { is_selected = true;}
    void unselect() { is_selected = false;}

private:
    void bounce() {
        auto rectangle_bounds = getGlobalBounds();
        if(rectangle_bounds.left < left_bound_) {
            velocity_x_ = std::abs(velocity_x_);
        }

        if(rectangle_bounds.top < top_bound_) {
            velocity_y_ = std::abs(velocity_y_);
        }

        if(rectangle_bounds.left+rectangle_bounds.width > right_bound_) {
            velocity_x_ = -std::abs(velocity_x_);
        }

        if(rectangle_bounds.top+rectangle_bounds.height > bottom_bound_) {
            velocity_y_ = -std::abs(velocity_y_);
        }
    }

float velocity_x_ = 0;
float velocity_y_ = 0;
float angular_velocity_ = 0;

float left_bound_;
float right_bound_;
float top_bound_;
float bottom_bound_;

bool is_selected = false;

};

int main() {
    srand (time(NULL));

    sf::RenderWindow window(sf::VideoMode(1000, 600), "Okienko");
    std::vector<CustomRectangleShape> rectangles;
    for (int i=0; i<10; i++) {
        sf::Vector2f size(120.0, 60.0);
        sf::Vector2f position(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60));
        rectangles.emplace_back(CustomRectangleShape(size, position));
    }

    for (auto &rec : rectangles) {
        rec.setFillColor(sf::Color(100, 100, 100));
        rec.setBounds(0, window.getSize().x, 0, window.getSize().y);
        rec.setSpeed(100, 200, 30);
    }

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (auto &rec : rectangles) {
            rec.animate(elapsed);
        }

        window.clear(sf::Color::Black);
        for(const auto &rec : rectangles) {
                window.draw(rec);
         }

        window.display();
        std::vector<sf::FloatRect> rectangle_bounds;
        for (int i=0; i<10; i++) {
            rectangle_bounds.emplace_back(rectangles[i].getGlobalBounds());

            if (event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if((mouse_pos.x > rectangle_bounds[i].left)&&(mouse_pos.x < rectangle_bounds[i].left + rectangle_bounds[i].width)
                            &&(mouse_pos.y > rectangle_bounds[i].top)&&(mouse_pos.y < rectangle_bounds[i].top + rectangle_bounds[i].height)) {
                        rectangles[i].select();
                        rectangles[i].setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));

                    }
                }
            }

        if (event.type == sf::Event::MouseButtonPressed) {
            if(event.mouseButton.button == sf::Mouse::Right) {
                sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if((mouse_pos.x > rectangle_bounds[i].left)&&(mouse_pos.x < rectangle_bounds[i].left + rectangle_bounds[i].width)
                        &&(mouse_pos.y > rectangle_bounds[i].top)&&(mouse_pos.y < rectangle_bounds[i].top + rectangle_bounds[i].height)) {
                    rectangles[i].unselect();
                    rectangles[i].setFillColor(sf::Color(100, 100, 100));
                }

            }
        }
    }

    }

    return 0;
}
