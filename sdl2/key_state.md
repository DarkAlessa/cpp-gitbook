```cpp
	bool isRunning = true;
	while (isRunning) {
		frameStart = SDL_GetTicks64();
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0) {
	        switch (e.type) {
	            case SDL_EventType::SDL_QUIT:
	                isRunning = false;
	                break;
				case SDL_EventType::SDL_MOUSEBUTTONDOWN:
					dest_1.x = e.button.x - (dest_1.w / 2);
					dest_1.y = e.button.y - (dest_2.h / 2);
					break;
	            default:
	            	break;
	        }
    	}

        const Uint8* keys = SDL_GetKeyboardState(NULL);
        if (keys[SDL_GetScancodeFromKey(SDLK_a)]) {
            std::cout << "'A' key is pressed." << '\n';
        }
        if (keys[SDL_GetScancodeFromKey(SDLK_d)]) {
            std::cout << "'A' key is pressed." << '\n';
        }
        if (keys[SDL_GetScancodeFromKey(SDLK_w)]) {
            std::cout << "'A' key is pressed." << '\n';
        }
        if (keys[SDL_GetScancodeFromKey(SDLK_s)]) {
            std::cout << "'A' key is pressed." << '\n';
        }

        /*
		 ...
        */
    }
```