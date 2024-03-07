#include "tilemaplose.h"

tilemaplose::tilemaplose(SDL_Renderer* sdlrenderer, std::string filename) {
	renderer = sdlrenderer;
	this->filename = filename;
}
int tilemaplose::init() {
	SDL_Surface* image = IMG_Load(filename.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	loadTileMapFromFile();
	//saveState();
	return 0;
}

void tilemaplose::render() {
	for (int i = 0; i < mapHeight2; i++) {
		for (int j = 0; j < mapWidth2; j++) {

			SDL_Rect sourceRect;
			sourceRect.x = (map[i][j] % 8) * sourceTileSizePx;
			sourceRect.y = (map[i][j] / 8) * sourceTileSizePx;
			sourceRect.h = sourceTileSizePx;
			sourceRect.w = sourceTileSizePx;

			SDL_Rect renderRect;
			renderRect.x = j * tileWidth;
			renderRect.y = i * tileHeight;
			renderRect.h = tileHeight;
			renderRect.w = tileWidth;

			SDL_RenderCopy(renderer, texture, &sourceRect, &renderRect);
		}
	}
}

void tilemaplose::loadTileMapFromFile() {
	std::ifstream tilemap_stream;
	tilemap_stream.open("assets/tilemap2.txt", std::ios::in);
	if (!tilemap_stream.is_open()) {
		std::cout << "Failed to open tilemap.txt" << std::endl;
		return;
	}
	else {

		for (int rowIdx = 0; rowIdx < mapHeight2; rowIdx++) {
			for (int colIdx = 0; colIdx < mapWidth2; colIdx++) {
				std::string tileValue;
				std::getline(tilemap_stream, tileValue, ' ');
				std::cout << tileValue;
				int value = atoi(tileValue.c_str());
				map[rowIdx][colIdx] = value;
			}
		}
	}
	tilemap_stream.close();
}
void tilemaplose::saveTileMapToFile() {
	std::ofstream tilemap_stream("assets/tilemap2.txt");
	if (!tilemap_stream.is_open()) {
		std::cout << "Failed to open tilemap.txt" << std::endl;
		return;
	}
	for (int rowIdx = 0; rowIdx < mapHeight2; rowIdx++) {
		for (int colIdx = 0; colIdx < mapWidth2; colIdx++) {
			tilemap_stream << map[rowIdx][colIdx] << " ";
		}


		tilemap_stream << std::endl;
	}


	tilemap_stream.close();
}

void tilemaplose::clean() {

}
