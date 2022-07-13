# libjson store
C library for file based storage using JSON.

## Installation
```bash
git clone https://github.com/joegasewicz/libjson_store.git
# Build
make build
# Move the archive & header files into you projects root
mkdir your_project/lib && mv libjson_store/lib your_project/lib
mv libjson_store/include your_project/include
# If your project has a main.c file then run the following 
gcc main.c -ljson_store -ljson-c -I include -L lib
```

## Setup
```bash
# If your project has a main.c file then run the following:
gcc main.c -ljson_store -ljson-c -I include -L lib
```

## Usage
Create a JSON store & JSON file
```c
#include "json_store.h"

int main(int argc, char** argv)
{
    JS_Store *js_store = JS_json_store_new("example.JSON");
    free(js_store); // Free the store memory
    return 0;
}
```