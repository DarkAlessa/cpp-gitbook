```cpp
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <cassert>

#define WIN_W 640
#define WIN_H 480

int main(int argc, char** argv) {
	// SDL init
	assert(SDL_Init(SDL_INIT_EVERYTHING) == 0);
	SDL_WindowFlags window_flags = static_cast<SDL_WindowFlags>(SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
	SDL_Window* window = SDL_CreateWindow("Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, window_flags);
	assert(window);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	assert(renderer);
    SDL_SetWindowMinimumSize(window, WIN_W, WIN_H);

    // ImGui init
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    // Load Font
    io.Fonts->AddFontFromFileTTF("./assets/Mitr-Regular.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesThai());

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    ImGuiStyle& style = ImGui::GetStyle();
    style.TabRounding    = 4.0f;
    style.FrameRounding  = 4.0f;
    style.WindowRounding = 4.0f;
    style.PopupRounding  = 4.0f;
    //style.Colors[ImGuiCol_WindowBg] = ImVec4(0.131f, 0.242f, 0.133f, 0.9f);

	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    //// FPS --------------------------------------
    constexpr int FPS        = 60;
    constexpr int frameDelay = 1000 / FPS;
    Uint64 frameStart;
    Uint64 frameTime;

	// Loop
	bool running = true;
	while (running) {
        frameStart = SDL_GetTicks64();
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event);
			if (event.type == SDL_QUIT)
                running = false;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
                running = true;
		}
		
        // Start the Dear ImGui frame
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Performance");
        ImGui::Text("Frame Time : %.1f ms/frame", 1000.0f / io.Framerate);
        ImGui::Text("Frame Rate : %d FPS", static_cast<int>(io.Framerate));
        ImGui::End();

		// Rendering
        SDL_RenderSetScale(renderer, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
        SDL_SetRenderDrawColor(renderer, (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
        SDL_RenderClear(renderer);
        ImGui::Render();
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks64() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
	}

	// Cleanup
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}

```