```bash

g++ -std=c++23 -Wall -Werror -Wpedantic *.cpp -o output `pkg-config gtkmm-4.0 --cflags --libs`

```