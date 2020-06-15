#include "tilemap.h"

TileMap::TileMap(sf::Vector2u tileSize, unsigned int width, unsigned int height, const std::string& tileset_s) :
    width_(width), height_(height), tileSize_(tileSize)
{
    tileset_.loadFromFile(tileset_s);
};

bool TileMap::load(const std::string &map_file)
{
    MapLoaded_ = map_file;
    //load map.txt file
    std::fstream file(MapLoaded_);
    if (!file.is_open())
        return false;

    while(!file.eof()){
        file >> TileLocation;
        tiles_ = atoi(TileLocation.c_str());
        number_map.emplace_back(std::make_unique<int>(tiles_));
    }

    // resize the vertex array to fit the level size
    vertices_.setPrimitiveType(sf::Quads);
    vertices_.resize(width_ * height_ * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width_; ++i)
        for (unsigned int j = 0; j < height_; ++j)
        {
            // get the current tile number
            int &tileNumber = *number_map[i + j * width_];

            // find its position in the tileset texture
            int tu = tileNumber % (tileset_.getSize().x / tileSize_.x);
            int tv = tileNumber / (tileset_.getSize().x / tileSize_.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices_[(i + j * width_) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize_.x, j * tileSize_.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize_.x, j * tileSize_.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize_.x, (j + 1) * tileSize_.y);
            quad[3].position = sf::Vector2f(i * tileSize_.x, (j + 1) * tileSize_.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize_.x, tv * tileSize_.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize_.x, tv * tileSize_.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize_.x, (tv + 1) * tileSize_.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize_.x, (tv + 1) * tileSize_.y);

        }

    return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    states.texture = &tileset_;

    target.draw(vertices_, states);

}

bool TileMap::loadColissionMap(const std::string& map_file){
    std::ifstream openfile(map_file);
    std::vector<int> tempMap;
    cmap.clear();

    if(openfile.is_open()){
        while(!openfile.eof()) {
              std::string str, value;
              getline(openfile, str);
              std::stringstream stream(str);
              while(std::getline(stream, value, '\t')){
                  if(value.length() > 0){
                      int dupa_ = atoi(value.c_str());
                      tempMap.emplace_back(dupa_);
                  }
              }
              cmap.emplace_back(tempMap);
              tempMap.clear();
        }
    }
    return true;
}

void TileMap::change()
{
    MapLoaded_ = "Map2.txt";
}
