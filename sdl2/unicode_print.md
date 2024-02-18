//font file : "Sauce Code Pro Nerd Font Complete.ttf"

ใช้ char16_t (ใช้ operator+ ไม่ได้)
```cpp

const char16_t icon[] = u"\uE61D \uE711 \uE70C \uE749 \uE74F \uE26D";
SDL_Surface* text_surf = TTF_RenderUNICODE_Blended(font, reinterpret_cast<const Uint16*>(icon), fg);

```

ใช้ std::u16string (ใช้ operator+ ไม่ได้)
```cpp

std::u16string icon = u"\uF028 Hello";
SDL_Surface* textSurface = TTF_RenderUNICODE_Blended(fontFace, reinterpret_cast<const Uint16*>(text.c_str()), fg);

```

ใช้ std::wstring
```cpp

std::wstring icon = L"\uE61D \uE711 \uE70C \uE749 \uE74F \uE26D";
SDL_Surface* text_surf = TTF_RenderUNICODE_Blended(font, reinterpret_cast<const Uint16*>(icon.c_str()), fg);

```