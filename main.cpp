#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>

#include "duktape.h"

static duk_ret_t native_print(duk_context *ctx) {
    printf("%s\n", duk_to_string(ctx, 0));
    return 0;  /* no return value (= undefined) */
}

int main() {
    // Load javascript
    std::ifstream t("test.js");
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    std::cout << "Javascript loaded" << std::endl;

    // Create the context
    duk_context *ctx = duk_create_heap_default();

    // Register native function
    duk_push_c_function(ctx, native_print, 1 /*nargs*/);
    duk_put_global_string(ctx, "print");

    // Load the string containing our javascript into the context
    duk_eval_string_noresult(ctx, str.c_str());



    // Call our custom function
    duk_get_global_string(ctx, "myfunc");
    //duk_push_string(ctx, "Peter");

    duk_idx_t obj_idx;
    obj_idx = duk_push_object(ctx);
    duk_push_int(ctx, 42);
    duk_put_prop_string(ctx, obj_idx, "meaningOfLife");

    int r = duk_pcall(ctx, 1);
    std::cout << r << " - " << duk_get_int(ctx, -1) << std::endl;

    // Destroy the context
    duk_destroy_heap(ctx);

    return 0;
}