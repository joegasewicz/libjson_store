#ifndef JSON_STORE_JSON_STORE_H
#define JSON_STORE_JSON_STORE_H

#include <json-c/json.h>

typedef struct Store {
    json_object *root;
} JS_Store;

JS_Store *JS_json_store_new(const char *name);
int JS_create_json_file(const char *file_name, const char *json_data);
// DB commands
int JS_get(void);
int JS_get_all(void);
int JS_create(JS_Store *s, const char *key, const char *value);
int JS_delete(void);
int JS_update(void);


#endif //JSON_STORE_JSON_STORE_H
