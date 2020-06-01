#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class TileMap : public sf::Sprite
{
public:
    bool load(const std::string& tileset, sf::Vector2u tileSize, const std::string& map_file, unsigned int width, unsigned int height);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    std::vector<std::unique_ptr<int>> map;
    int tiles;
    std::string TileLocation;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;

};
