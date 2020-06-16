#ifndef TILEMAP_H
#define TILEMAP_H

#include<Biblioteki.h>

class TileMap : public sf::Sprite
{
public:
    TileMap(sf::Vector2u tileSize = sf::Vector2u(16, 16), unsigned int width = 62, unsigned int height = 66,
            const std::string& tileset_s = "C:/Users/szymo/OneDrive/Game_PSiO/SSD/Grafiki/tileset.png");

    bool load(const std::string &map_file);
    bool loadColissionMap(const std::string& map_file);
    void change();

public:
    std::vector<std::vector<int>> cmap;
    std::vector<std::unique_ptr<int>> number_map;
    int NUM;
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    unsigned int width_;
    unsigned int height_;
    int tiles_;
    std::string MapLoaded_;

    std::string TileLocation;
    sf::VertexArray vertices_;
    sf::Texture tileset_;
    sf::Vector2u tileSize_;

};

#endif //TILEMAP_H
