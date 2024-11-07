#!/usr/bin/env sh

# WEB
clang --target=wasm32 --no-standard-libraries -I./libs/raylib/include -Wl,--export-all -Wl,--no-entry -Wl,--allow-undefined -DPLATFORM_WEB -o c-wasm.wasm c-wasm.c

# LINUX
gcc c-wasm.c -o c-wasm -O2 -Wall -Wno-missing-braces -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
