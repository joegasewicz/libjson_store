#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>
#include "include/json_store.h"

#define JS_DEBUG 1
#define JS_JSON_FILE_SIZE 1000
#define JS_LOGGER(msg) if (JS_DEBUG) printf("%s\n", msg);
#define JS_SUCCESS 0
#define JS_FILE_ERROR 1
#define JS_PRINT_ERROR(err) {\
        if (err == JS_FILE_ERROR) printf("Error creating JSON file\n");\
    }


/**
 * Create a JSON file
 * @param file_name The JSON file name & path e.g 'example.JSON'
 * @param json_data The JSON string
 * @return Error
 */
int JS_create_json_file(const char *file_name, const char *json_data)
{
    FILE *json_file_ptr;
    json_file_ptr = fopen(file_name, "w");

    if (json_file_ptr == NULL) {
        fclose(json_file_ptr);
        return JS_JSON_FILE_SIZE;
    }
    fputs(json_data, json_file_ptr);
    fclose(json_file_ptr);
    return JS_SUCCESS;
}

/**
 * Create a new instance of the json store & generates a JSON file.
 * @return Error
 */
int JS_json_store_new(void) {
    json_object *root = json_object_new_object();
    const char *json_data = json_object_to_json_string_ext(root, JSON_C_TO_STRING_PRETTY);
    printf("JSON:\n\n\n%s\n\n\n", json_object_to_json_string_ext(root, JSON_C_TO_STRING_PRETTY));
    int err = JS_create_json_file("example.JSON", json_data);
    if (err > 0) {
        JS_PRINT_ERROR(JS_FILE_ERROR);
        return 1;
    }
    json_object_put(root);
    return JS_SUCCESS;
}
