SDL_Init() ต้องถูกเรียกก่อนฟังก์ชันอื่น 
	return 0 คือ success
	return น้อยกว่า 0 คือ failure

SDL_Quit() ใช้ก่อนจบโปรแกรมหรือ error

//------------------------------------

int main(int argc, char* argv[]) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
	std::cout << "Could not initialize SDL: " << SDL_GetError() << '\n';
        SDL_Quit();
    } 
    /* Code Hear */
    SDL_Quit();
    return 0;
}