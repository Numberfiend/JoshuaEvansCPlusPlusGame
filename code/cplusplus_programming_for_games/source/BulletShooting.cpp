/*#include "BulletShooting.h"

//BulletShooting::BulletShooting(SDL_Renderer* renderer) {

//}

void BulletShooting::init() {
	SDL_Surface* surface = IMG_Load("assets/bullet.png");
	this->bulletTexture = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);

}

void BulletShooting::processInput(bool*keyDown) {
	if (keyDown[SDL_SCANCODE_SPACE]) {
		if (SDL_GetTicks() - lastShot > SHOOT_TIMER_MS) {
			bullets.push_back(Bullet{ 315.0f, 230.0f, 90, 0.0f });
			lastShot = SDL_GetTicks();
		}
	}
}

void BulletShooting::update() {
	for (auto& b : bullets) {
		b.x += sin(b.rotation * PI / 180.0f) * BULLET_VELOCITY;
		b.y -= cos(b.rotation * PI / 180.0f) * BULLET_VELOCITY;
		b.distance += BULLET_VELOCITY;
	}
	//remove bullet after they have travelled approx 1000 pixels. this code could be called less frequently for efficiency
	auto remove = std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) { return b.distance > 1000; });
	bullets.erase(remove, bullets.end());
}

void BulletShooting::render() {
	SDL_Point center = { 5, 5 };
	for (auto& b : bullets) {
		SDL_Rect dest = { b.x, b.y, 10, 10 };
		SDL_RenderCopyEx(renderer, bulletTexture, 0, &dest, b.rotation, &center, SDL_FLIP_NONE);
	}
}

void BulletShooting::clean() {
	SDL_DestroyTexture(this->bulletTexture);
}*/