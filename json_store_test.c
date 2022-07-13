//
// Created by Joe Geezer on 10/07/2022.
//
#include "include/json_store.h"
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char** argv)
{
    JS_Store *js_store = JS_json_store_new("example.JSON");
    free(js_store); // Free the store memory
    return 0;
}